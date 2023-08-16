/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:16:31 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/16 15:28:00 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
	private:
		std::map<std::string, double> _data;
	public:
		bool setData(const std::string& filePath);
		void printData(void);
};

#endif