/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:38:22 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/02 14:02:10 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char *av[]) {
	if (ac != 4) {
		std::cerr << "Error: Bad number of arguments." << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::ifstream ifs(filename.c_str());
	if (!ifs.is_open()) {
		std::cerr << "Error: Unable to open source file." << std::endl;
        return (1);
	}
	std::string out_filename = filename + ".replace";
	std::ofstream ofs(out_filename.c_str());
	if (!ofs.is_open()) {
		std::cerr << "Error: Unable to create output file." << std::endl;
		ifs.close();
        return (1);
	}
	std::string line;
	while(std::getline(ifs, line))
	{
		int i = 0;
		size_t found;
		std::string result;
		while ((found = line.find(av[2], i)) != std::string::npos) {
			result += line.substr(i, found - i);
			result += av[3];
			i = found + std::string(av[2]).length();
		}
		result += line.substr(i);
		ofs << result << std::endl;
	}
	ifs.close();
	ofs.close();
	return(0);
}
