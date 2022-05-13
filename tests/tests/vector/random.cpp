/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:59:02 by mleblanc          #+#    #+#             */
/*   Updated: 2022/05/13 16:36:55 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_prelude.hpp"

void vec_test_random()
{
    SETUP_ARRAYS();

    {
        STRVECTOR v;

        v.insert(v.end(), s_string, s_string + s_size);

        CHECK_AND_PRINT_ALL(v);

        v.insert(v.begin() + 7, 3, b_string[6]);

        CHECK_AND_PRINT_ALL(v);

        PRINT_MSG(v[6]);
        PRINT_MSG(v.at(6));

        STRVECTOR::iterator it = v.erase(v.end() - 1);

        if (it == v.end()) {
            PRINT_MSG("End");
        }

        CHECK_AND_PRINT_ALL(v);

        for (int i = 0; i < 8; ++i) {
            v.push_back(b_string[i]);
        }

        CHECK_AND_PRINT_ALL(v);

        PRINT_LINE("Max size:", v.max_size());

        for (int i = 0; i < 3; ++i) {
            v.pop_back();
        }

        CHECK_AND_PRINT_ALL(v);

        for (STRVECTOR::const_reverse_iterator crit = v.rbegin(); crit != v.rend(); ++crit) {
            PRINT_MSG(*crit);
        }

        it = v.insert(v.begin(), "ABCD");

        PRINT_MSG(*it);

        PRINT_MSG(v.back());
        PRINT_MSG(v.front());

        v.clear();

        CHECK_AND_PRINT_ALL(v);

        v.resize(70, "Cool string");

        CHECK_AND_PRINT_ALL(v);

        v.assign(22, "64");

        CHECK_AND_PRINT_ALL(v);

        v.assign(b_string, b_string + 8);

        CHECK_AND_PRINT_ALL(v);

        STRVECTOR v2;

        if (v2 < v) {
            PRINT_MSG("Small");
        }

        v2 = v;

        if (v2 == v) {
            PRINT_MSG("Equal");
        }

        if (v2 <= v) {
            PRINT_MSG("Le");
        }

        v2.reserve(64);

        CHECK_AND_PRINT_ALL(v2);

        v.erase(v.begin() + 4, v.end());

        CHECK_AND_PRINT_ALL(v);

        leak_checker::check_alive_objects();
    }
}

MAIN(vec_test_random)
