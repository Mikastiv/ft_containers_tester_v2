/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:32:18 by mleblanc          #+#    #+#             */
/*   Updated: 2022/05/19 23:32:47 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_prelude.hpp"

void set_test_swap()
{
    SETUP_ARRAYS();

    {
        intset m1(intstr_arr, intstr_arr + 32);
        intset m2;

        NAMESPACE::swap(m1, m2);

        PRINT_ALL(m1);
        PRINT_ALL(m2);

        m1.clear();
        m1.swap(m2);

        PRINT_ALL(m1);
        PRINT_ALL(m2);

        m1.clear();
        m2.swap(m1);

        PRINT_ALL(m1);
        PRINT_ALL(m2);

        m1.insert(64);
        NAMESPACE::swap(m1, m2);

        PRINT_ALL(m1);
        PRINT_ALL(m2);

        m2.insert(intstr_arr, intstr_arr + intstr_size);
        m1.swap(m2);

        PRINT_ALL(m1);
        PRINT_ALL(m2);

        m1.clear();
        m1.swap(m2);
        m1.clear();
        m1.swap(m2);

        PRINT_ALL(m1);
        PRINT_ALL(m2);
    }
}

MAIN(set_test_swap)