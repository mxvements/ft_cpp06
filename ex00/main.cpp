/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:39:37 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/25 20:16:28 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//it needs to be a program, so be need input
int	main(void)
{	
	//char cases
	std::string char1 = "c";
	std::string char2 = "a";
	std::string char3 = "nan";

	//int cases
	std::string int1 = "0";
	std::string int2 = "-42";
	std::string int3 = "42";
	//float cases
	std::string float1 = "0.0f";
	std::string float2 = "-4.2f";
	std::string float3 = "4.2f";
	//double cases
	std::string double1 = "0.0";
	std::string double2 = "-4.2";
	std::string double3 = "4.2";

	ScalarConverter::convert(char1);
	ScalarConverter::convert(char2);
	ScalarConverter::convert(char3);

	ScalarConverter::convert(int1);
	ScalarConverter::convert(int2);
	ScalarConverter::convert(int3);

	ScalarConverter::convert(float1);
	ScalarConverter::convert(float2);
	ScalarConverter::convert(float3);

	ScalarConverter::convert(double1);
	ScalarConverter::convert(double2);
	ScalarConverter::convert(double3);

	return (0);
}
