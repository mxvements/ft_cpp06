/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:39:37 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/27 16:07:00 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/**
 * ./convert 0
 * char: Non displayable
 * int: 0
 * float: 0.0f
 * double: 0.0
 * 
 * ./convert nan
 * char: impossible
 * int: impossible
 * float: nanf
 * double: nan
 * 
 * ./convert 42.0f
 * char: '*'
 * int: 42
 * float: 42.0f
 * double: 42.0
 */
static void convert_test(void)
{
	std::cerr << "testing cases..." << std::endl;
	std::cerr << std::endl;
	//char cases
	std::string char1 = "*";
	ScalarConverter::convert(char1);
	std::string char2 = "	";
	ScalarConverter::convert(char2);
	std::string char3 = "nan";
	ScalarConverter::convert(char3);
	//int cases
	std::string int1 = "0";
	ScalarConverter::convert(int1);
	std::string int2 = "-42";
	ScalarConverter::convert(int2);
	std::string int3 = "42";
	ScalarConverter::convert(int3);
	//float cases
	std::string float1 = "0.0f";
	ScalarConverter::convert(float1);
	std::string float2 = "-4.2f";
	ScalarConverter::convert(float2);
	std::string float3 = "4.2f";
	ScalarConverter::convert(float3);
	//double cases
	std::string double1 = "0.0";
	ScalarConverter::convert(double1);
	std::string double2 = "-4.2";
	ScalarConverter::convert(double2);
	std::string double3 = "4.2";
	ScalarConverter::convert(double3);
}

int	main(int argc, char **argv)
{	
	if (argc == 2)
	{
		std::string arg = argv[1];
		if (arg == "test")
			convert_test();
		else
			ScalarConverter::convert(arg);
		return (0);
	} else if (argc == 1)
	{
		std::cerr << "error: no arguments provided" << std::endl;
		return (1);
	}else {
		std::cerr << "error: wrong number of arguments" << std::endl;
		return (1);
	}
	return (0);
}
