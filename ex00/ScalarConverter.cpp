/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:49:21 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/24 20:10:46 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/**
 * notes on conversion in cpp
 * 
 * std::string	->	int			std::stoi(str, pos)		(INT_MIN..INT_MAX)
 * 		allows
 * 			- optional (+/-), prefix (0, 0x, OX)
 * 			- discards all std::isspace until the 1sr non-whitespace
 * 		returns 
 *	 		- std::invalid_argument		if no conversion could be performed
 * 			- std::out_of_range 		sets errno to ERANGE 
 * 	
 * std::string	->	float		std::stof(str, pos) 	(FLT_MIN..FLT_MAX)
 * std::string	-> 	double		std::stod(str, pos)		(DBL_MIN..DBL_MAX)
 * 		allows
 * 			- optional (+/-), 
 * 			- hexadecimal : prefix (0x, 0X) + hexadecimal digits
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



