/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:40:21 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/27 18:50:13 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cerrno>
#include <cstdlib> 
#include <iostream>
#include <iomanip>
#include <sstream>
#include <climits>


/* ************************************************************************** */
/* UTILS FOR THE FORMAT OUTPUT*/

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

struct Format
{
	Type type;
	bool iserror;
	std::string error;
	union
	{
		char c;
		int i;
		float f;
		double d;
	};

	Format(char c) : type(CHAR), iserror(false), c(c) {}
	Format(int i) : type(INT), iserror(false), i(i) {}
	Format(float f) : type(FLOAT), iserror(false), f(f) {}
	Format(double d) : type(DOUBLE), iserror(false), d(d) {}
	Format(Type t, std::string error) : type(t), iserror(true), error(error) {}
};

struct EdgeCase
{
	std::string input;
	Format format[4];
};

/* ************************************************************************** */
/*SCALAR CONVRTER*/
class ScalarConverter
{
private:
protected:
public:
	static void convert(std::string literal); // output value in 4 scalar types - char, int, float, double
};

/* ************************************************************************** */

#endif