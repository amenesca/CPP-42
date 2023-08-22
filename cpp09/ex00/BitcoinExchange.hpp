/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:16:31 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/22 12:04:32 by amenesca         ###   ########.fr       */
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
	public:
		bool setData(const std::string& filePath);
		void initProgamm(const std::string& inputFile) const;
		void printData(void);// TEST FUNCTION ***

};

#endif