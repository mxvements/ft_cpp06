/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:34:30 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/27 21:17:17 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){}
A::~A(){}
B::~B(){}
C::~C(){}

/* ************************************************************************** */

/**
 * Exercise on dynamic cast, since it works at runtime and only with polymorphic
 * instances (Base and its children)
 */

Base *generate(void)
{
	std::srand(std::time(0)); //seed
	double random_number = static_cast<double>(std::rand()) / RAND_MAX;
	
	if (random_number < 0.3) 
		return new A();
	 else if (random_number > 0.6) 
		return new C();
	else
		return new B();
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (const std::exception &e) {
		try {
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		} catch (const std::exception &e) {
			try {
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			} catch (const std::exception &e) {
				std::cerr << "Not any of the children classes" << std::endl;
				std::cerr << e.what() << std::endl;
			}
		}
	}
}

