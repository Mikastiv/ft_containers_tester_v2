/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:23:40 by mleblanc          #+#    #+#             */
/*   Updated: 2022/05/08 20:17:48 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "track/leak_checker.hpp"
#include "track/track_allocator.hpp"

int main()
{
    track_allocator<int> alloc;

    int* ptr = alloc.allocate(20);
    alloc.construct(ptr, 6);
    alloc.destroy(ptr);
    alloc.deallocate(ptr, 20);
    leak_checker::check_leaks();
    leak_checker::check_destructor_calls();
}
