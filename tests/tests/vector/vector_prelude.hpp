/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_prelude.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:39:36 by mleblanc          #+#    #+#             */
/*   Updated: 2022/05/13 19:06:59 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector.hpp"
#include <vector>

#include "prelude.hpp"

#define STRVECTOR NAMESPACE::vector<std::string, track_allocator<std::string> >
#define INTVECTOR NAMESPACE::vector<int, track_allocator<int> >
#define LONGVECTOR NAMESPACE::vector<long, track_allocator<long> >
#define DOUBLEVECTOR NAMESPACE::vector<double, track_allocator<double> >
#define CHARVECTOR NAMESPACE::vector<char, track_allocator<char> >
