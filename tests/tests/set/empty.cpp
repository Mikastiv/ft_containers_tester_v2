/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:19:27 by mleblanc          #+#    #+#             */
/*   Updated: 2022/05/19 23:19:44 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_prelude.hpp"

void set_test_empty()
{
    SETUP_ARRAYS();

    {
        strset m;

        PRINT_LINE("Empty:", m.empty() ? "true" : "false");

        m.insert("Hello");

        PRINT_LINE("Empty:", m.empty() ? "true" : "false");

        m.erase(m.begin());

        PRINT_LINE("Empty:", m.empty() ? "true" : "false");
    }

    {
        intset m (intstr_arr, intstr_arr + intstr_size);

        PRINT_LINE("Empty:", m.empty() ? "true" : "false");
    }
}

MAIN(set_test_empty)
