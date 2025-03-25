/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:49:21 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/25 20:45:48 by luciama2         ###   ########.fr       */
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
 * 	float literales	-> 	0.0f, -4.2f, 4.2f, -inff, +inff
 *  double literals	-> 	0.0, -4.2, 4.2, -inf, +inf, (+/-)nan
 */


static void formatter(std::string msg[4])
{
	std::cout << "char : " << msg[0] << std::endl;
	std::cout << "int : " << msg[1] << std::endl;
	std::cout << "float : " << msg[2] << std::endl;
	std::cout << "double : " << msg[3] << std::endl;
}

static void formatter(char c, int i, float f, double d)
{
	std::cout << "char : " << c << std::endl;
	std::cout << "int : " << i << std::endl;
	std::cout << "float : " << f << std::endl;
	std::cout << "double : " << d << std::endl;
}

struct EdgeCase
{
	std::string input;
	std::string format[4];
};

static int is_edge_cases(std::string literal)
{
	EdgeCase cases[6] = {
		{"nanf", {"impossible", "impossible", "nanf", "nan"}},
		{"nan", {"impossible", "impossible", "nanf", "nan"}},
		{"+inff", {"impossible", "impossible", "+inff", "+inf"}},
		{"+inf", {"impossible", "impossible", "+inff", "+inf"}},
		{"-inff", {"impossible", "impossible", "-inff", "-inf"}},
		{"-inf", {"impossible", "impossible", "-inff", "-inf"}}};

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
	if (literal.length() > 1)
	{
		std::string msg[4] = {"impossible", "impossible", "impossible", "impossible"};
		return formatter(msg);
	}
	// explicit conversion
	char c = literal[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	return formatter(c, i, f, d);
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
	else if (std::isalpha(literal[0]))
	{
		std::cout << "could be a char!" << std::endl;
		convert_char(literal);
	}
	else if (literal.find("f") != std::string::npos)
	{
		std::cout << "could be a float!" << std::endl;
		// use atof
	}
	else if (literal.find(".") != std::string::npos)
	{
		std::cout << "could be a double!" << std::endl;
		// use atod
	}
	else
	{
		std::cout << "could be an int!" << std::endl;
		// use atoi
	}
}