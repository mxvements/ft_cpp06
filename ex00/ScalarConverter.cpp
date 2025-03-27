/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:49:21 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/27 16:06:00 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/**
 * notes on conversion in cpp
 * (i) in the exercise only the decimal notation will be used
 *
 * std::string	->	int			std::stoi(str, pos)		(INT_MIN..INT_MAX)
 * 		allows
 * 			- optional (+/-), prefix (0, 0x, OX) + hexadecimal digits 0123456789abcdef
 * 			- discards all std::isspace until the 1sr non-whitespace
 * 		returns
 *	 		- std::invalid_argument		if no conversion could be performed
 * 			- std::out_of_range 		sets errno to ERANGE
 *
 * std::string	->	float		std::stof(str, pos) 	(FLT_MIN..FLT_MAX)
 * std::string	-> 	double		std::stod(str, pos)		(DBL_MIN..DBL_MAX)
 * 		allows
 * 			- optional (+/-),
 * 			- hexadecimal : prefix (0x, 0X) + hexadecimal digits 0123456789abcdef
 * 			- scientific notation : e or E with optional (+/-) and decimal digits
 * 			- nan or NAN with char_sequence (with digits, latin letters and underscores)
 * 				    "NaN(custom_value)";	// Allowed (ignored value inside)
 * 					"NaN(123abc_);			// Allowed
 * 					"NaN(@#$)";				// Not allowed
 * 		returns
 *	 		- std::invalid_argument		if no conversion could be performed
 * 			- std::out_of_range 		sets errno to ERANGE
 *
 *
 * pdf examples:
 *  char literals	-> 	'c', 'a'
 *  int literals	-> 	0, -42, 42
 * 	float literales	-> 	0.0f, -4.2f, 4.2f, -inff, +inff, nanf
 *  double literals	-> 	0.0, -4.2, 4.2, -inf, +inf, nan
 *
 * use of union:
 * an union is a special data structure that allows multiple variables to share
 * the same memory allocation
 *
 * using constructor inside a struc
 * In C++ the only difference between a class and a struct is that members
 * and base classes are private by default in classes, whereas they are public
 * by default in structs. So structs can have constructors, and the syntax is
 * the same as for classes.
 */

static void formatter(Format f[4])
{
	for (int i = 0; i < 4; i++)
	{
		switch (f[i].type)
		{
		case CHAR:
			f[i].iserror ? std::cout << "char : " << f[i].error << std::endl
						 : std::cout << "char : '" << f[i].c << "'" << std::endl;
			break;
		case INT:
			f[i].iserror ? std::cout << "int :  " << f[i].error << std::endl
						 : std::cout << "int :  " << f[i].i << std::endl;
			break;
		case FLOAT:
			f[i].iserror ? std::cout << "float : " << f[i].error << std::endl
						 : std::cout << std::fixed << std::setprecision(1) << "float : " << f[i].f << "f" << std::endl;
			break;
		case DOUBLE:
			f[i].iserror ? std::cout << "double : " << f[i].error << std::endl
						 : std::cout << std::fixed << std::setprecision(1) << "double : " << f[i].d << std::endl;
			break;
		}
	}
}

static int is_edge_cases(std::string literal)
{
	EdgeCase cases[6] = {
		{"nanf", {Format(CHAR, "impossible"), Format(INT, "impossible"), Format(FLOAT, "nanf"), Format(DOUBLE, "nan")}},
		{"nan", {Format(CHAR, "impossible"), Format(INT, "impossible"), Format(FLOAT, "nanf"), Format(DOUBLE, "nan")}},
		{"+inff", {Format(CHAR, "impossible"), Format(INT, "impossible"), Format(FLOAT, "+inff"), Format(DOUBLE, "+inf")}},
		{"+inf", {Format(CHAR, "impossible"), Format(INT, "impossible"), Format(FLOAT, "+inff"), Format(DOUBLE, "+inf")}},
		{"-inff", {Format(CHAR, "impossible"), Format(INT, "impossible"), Format(FLOAT, "-inff"), Format(DOUBLE, "-inf")}},
		{"-inf", {Format(CHAR, "impossible"), Format(INT, "impossible"), Format(FLOAT, "-inff"), Format(DOUBLE, "-inf")}}};

	for (int i = 0; i < 6; i++)
	{
		if (literal == cases[i].input)
		{
			formatter(cases[i].format);
			return (1);
		}
	}
	return (0);
}

/**
 * convert from string to its actual type
 * then convert it explicitly to the other data types *
 */
static void convert_char(std::string literal)
{
	// explicit conversion
	char c = literal[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	Format format[4] = {std::isprint(c) ? c : Format(CHAR, "Non displayable"), i, f, d};
	return formatter(format);
}

void ScalarConverter::convert(std::string literal)
{
	std::cout << std::endl;
	std::cout << "testing: " << literal << std::endl;
	// general case:
	//  1 - if there's a f -> it's float
	//  2 - if there's a . -> it's a double
	//  3 - if the first is not a digit or +/- -> char else int
	if (is_edge_cases(literal) == 1)
	{
		return;
	}
	if (literal.find("f") != std::string::npos)
	{
		std::cout << "could be a float!" << std::endl;
		// use atof
	}
	else if (literal.find(".") != std::string::npos)
	{
		std::cout << "could be a double!" << std::endl;
		// use atod
	}
	else if (literal.length() == 1 && !std::isdigit(literal[0]) && (std::isprint(literal[0]) || std::iscntrl(literal[0])))
	{
		std::cout << "could be a char!" << std::endl;
		convert_char(literal);
	}
	else if ((std::isdigit(literal[0])) || (!std::isdigit(literal[0]) && std::isdigit(literal[1])))
	{
		std::cout << "could be an int!" << std::endl;
		// use atoi
	}
	else
	{
		Format f[4] = {Format(CHAR, "impossible"), Format(INT, "impossible"), Format(FLOAT, "impossible"), Format(DOUBLE, "impossible")};
		return formatter(f);
	}
}