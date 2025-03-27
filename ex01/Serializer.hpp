/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:13:19 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/27 20:19:30 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	std::string str_data;
	int int_data;
};

class Serializer
{
	private:
		~Serializer();
		Serializer();
		Serializer(Serializer const &src);
		Serializer &operator=(Serializer const &rhs);
	
	protected:
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif