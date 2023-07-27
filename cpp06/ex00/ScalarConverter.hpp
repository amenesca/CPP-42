/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:50:34 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/26 18:10:51 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class ScalarConverter {
	private:
    	ScalarConverter(void);
    	ScalarConverter(const ScalarConverter& copy);
    	ScalarConverter &operator=(const ScalarConverter& copy);
    public:
    	~ScalarConverter(void);
        
    	static void convert(std::string input);
};



#endif