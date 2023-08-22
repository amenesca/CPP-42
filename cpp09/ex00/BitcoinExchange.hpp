/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:16:31 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/22 16:14:06 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

class BitcoinExchange {
	private:
		std::map<std::string, float> _data;
		void doOperation(const std::string& date, const float& value) const;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const std::map<std::string, float>& data);
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		std::map<std::string, float> getData(void) const;
	
		bool setData(const std::string& filePath);
		void initProgamm(const std::string& inputFile) const;

};

#endif