/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:13:26 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/29 13:41:04 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *d = new Data();
	d->int_data = 42;
	d->str_data = "Hello world";
	uintptr_t ptr;
	try {
		std::cout << "Before : " << d->int_data << " " << d->str_data << std::endl;
		ptr = Serializer::serialize(d);
		std::cout << "Serialized pointer comparison : ptr -> " << ptr << " data -> " << d << std::endl;
		Data *dd = Serializer::deserialize(ptr);
		std::cout << "After serialization : " << dd->int_data << " " << d->str_data << std::endl;
		std::cout << "Deserialized pointer comparison : d -> " << d << " dd -> " << dd << std::endl;

	} catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
