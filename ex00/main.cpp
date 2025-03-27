/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:39:37 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/27 19:07:42 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Colors.hpp"

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
static void print_test(std::string literal)
{
	std::cout << FG_LIGHT_BLUE << "Testing: " << BOLD << literal << RESET << std::endl;
	ScalarConverter::convert(literal);
	std::cout << std::endl;
}

static void convert_test(void)
{
	//char cases
	std::cout << UNDERLINED << FG_BR_BLUE << "CHAR cases:" << RESET << std::endl;
	print_test("*");
	print_test("	"); //tab, not printable
	print_test("nan");
	print_test("f");
	print_test(".");
	print_test("ff");
	print_test("..");
	print_test("a");
	print_test("aa");
	//int cases
	std::cout << UNDERLINED << FG_BR_BLUE << "INT cases:" << RESET << std::endl;
	print_test("0");
	print_test("-42");
	print_test("42");
	//float cases
	std::cout << UNDERLINED << FG_BR_BLUE << "FLOAT cases:" << RESET << std::endl;
	print_test("0.0f");
	print_test("-4.2f");
	print_test("4.2f");
	//double cases
	std::cout << UNDERLINED << FG_BR_BLUE << "DOUBLE cases:" << RESET << std::endl;
	print_test("0.0");
	print_test("-4.2");
	print_test("4.2");
	//limit cases, check long's limits, int limits, extended ascii limits, printable limits..
	std::cout << UNDERLINED << FG_BR_BLUE << "LIMIT cases:" << RESET << std::endl;
	print_test("9223372036854775807");
	print_test("-9223372036854775808");
	print_test("2147483647");
	print_test("-2147483648");
	print_test("256");
	print_test("255");
	print_test("128");
	print_test("127");
	print_test("32");
	print_test("31");
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
