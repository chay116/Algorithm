/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:27:52 by minckim           #+#    #+#             */
/*   Updated: 2022/03/17 02:18:20 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <vector>
#include <random>
#include <iostream>
#include <unistd.h>

int	main()
{
	int fd = 0;
	char buffer[4];
	std::cout << read(-1, buffer, 0) << std::endl;
	std::cout << read(-1, buffer, 0) << std::endl;
	close(fd);
	std::cout << read(fd, buffer, 0) << std::endl;
	std::cout << "buffer : " << buffer << std::endl;
}
