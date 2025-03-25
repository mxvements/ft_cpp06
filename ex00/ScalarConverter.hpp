/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:40:21 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/25 20:32:05 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <limits>

class ScalarConverter
{
	private:
	protected:
	public:
		static void convert(std::string literal); //output value in 4 scalar types - char, int, float, double
};

#endif