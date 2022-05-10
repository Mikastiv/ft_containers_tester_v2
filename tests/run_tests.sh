#!/bin/sh

FT_CONTAINERS="../../ft_containers"

# ANSI Colors
RED="\033[31;1m"
GREEN="\033[32;1m"
RST="\033[0m"

if [[ "$OSTYPE" == "darwin"* ]]; then
    ECHO_FLAG=""
else
    ECHO_FLAG="-e"
fi

LOGS="logs"
DIFFS="diffs"

CXX="clang++"
CXXFLAGS="-Wall -Werror -Wextra -std=c++98 -I$FT_CONTAINERS -I."

TEST_DIR="tests"

# Print success
test_success() {
    echo $ECHO_FLAG $1:$GREEN OK! $RST
}

# Print failure
test_fail() {
    echo $ECHO_FLAG $1:$RED KO! $RST
}

# Print red text
print_err() {
    echo $ECHO_FLAG $RED$1$RST
}

test_container() {
    TESTS=$(find "$TEST_DIR/$1" -type f -name '*.cpp' | sort)

    if [[ ${#TESTS} == 0 ]] ; then
        return
    fi

    mkdir -p $LOGS/$1 $DIFFS/$1

    for test in $TESTS; do
        TEST_NAME=$(basename -- $test)
        TEST_NAME=${TEST_NAME%.*}
        LOG_FT="$LOGS/$1/$TEST_NAME"_ft.log
        LOG_STD="$LOGS/$1/$TEST_NAME"_std.log

        if $CXX $CXXFLAGS -DNAMESPACE=ft $test track/memory_tracker.cpp track/leak_checker.cpp; then
            if ! ./a.out > $LOG_FT; then
                test_fail "$TEST_NAME"
                continue
            fi
        else
            print_err "Error compiling $test"
            test_fail "$TEST_NAME"
            continue
        fi

        $CXX $CXXFLAGS -DNAMESPACE=std $test track/memory_tracker.cpp track/leak_checker.cpp
        ./a.out > $LOG_STD

        DIFF_FILE="$DIFFS/$1/$TEST_NAME"_diff.diff
        diff -u $LOG_FT $LOG_STD > $DIFF_FILE
        RESULT=$(cat $DIFF_FILE)

        if [[ ${#RESULT} > 0 ]] ; then
            test_fail "$1 $t"
            print_err "Check $DIFF_FILE for $t diffs with std"
        else
            test_success "$1 $TEST_NAME"
            rm -f $DIFF_FILE
        fi
    done

    rm -f a.out
}

test_files() {
    TESTS=${@:2}

    for test in $TESTS; do
        TEST_NAME=$test
        LOG_FT="$LOGS/$1/$TEST_NAME"_ft.log
        LOG_STD="$LOGS/$1/$TEST_NAME"_std.log

        TEST_FILE="tests/$1/$TEST_NAME.cpp"

        if $CXX $CXXFLAGS -DNAMESPACE=ft $TEST_FILE track/memory_tracker.cpp track/leak_checker.cpp; then
            ./a.out > $LOG_FT
        else
            print_err "Error compiling $TEST_FILE"
            test_fail "$TEST_NAME"
            continue
        fi

        $CXX $CXXFLAGS -DNAMESPACE=std $TEST_FILE track/memory_tracker.cpp track/leak_checker.cpp
        ./a.out > $LOG_STD

        DIFF_FILE="$DIFFS/$1/$TEST_NAME"_diff.txt
        diff -u $LOG_FT $LOG_STD > $DIFF_FILE
        RESULT=$(cat $DIFF_FILE)

        if [[ ${#RESULT} > 0 ]] ; then
            test_fail "$1 $t"
            print_err "Check $DIFF_FILE for $t diffs with std"
        else
            test_success "$1 $TEST_NAME"
            rm -f $DIFF_FILE
        fi
    done

    rm -f a.out
}

run_container_tests() {
    rm -rf $LOGS $DIFFS
    mkdir -p $LOGS $DIFFS

    CONTAINERS="vector map stack set"

    if [ $# -ne 0 ]; then
        CONTAINERS=$@;
    fi

    for c in $CONTAINERS; do
        test_container $c
    done
}

run_test_files() {
    test_files $1 ${@:2}
}
