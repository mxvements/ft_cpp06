/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:30:39 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/27 21:17:13 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include <ctime>
# include <iostream>
# include <exception>
# include <stdexcept>


class Base
{
	public:
		virtual ~Base();
};

class A : public Base
{
	public:
		~A();
};
class B : public Base
{
	public:
		~B();
};
class C : public Base
{
	public:
		~C();
};

// FUNCTIONS:
/* It randomly instantiates A, B,
	or C and returns the instance as a Base pointer. Feel free
	to use anything you like for the random choice implementation.*/
Base	*generate(void);

// It prints the actual type of the object pointed to by p: "A", "B", or "C".
void	identify(Base *p);

/*	It prints the actual type of the object referenced by p: "A", "B",
	or "C". Using a pointer
	inside this function is forbidden.*/
void	identify(Base &p);

#endif