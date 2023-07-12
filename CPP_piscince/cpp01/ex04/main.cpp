/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:29:05 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/03 12:08:07 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	std::string	  filename;
	std::string	  outfile_name;
	std::string	  tofind;		// every occurrence of tofind_string
	std::string	  toreplace;	// must be substituted with toreplace_string
	std::string	  line;			// current line readen with getline();
	std::string   substring;	// substring up until tofind next occurrence
	std::string   result;		// final result
	std::size_t	  match;		// next_match cursor on current line
	std::ifstream toopen;		// stream dove mettere il file
	std::ofstream towrite;		// file stream dove scrivere il risultato
	
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments.";
		return (1);
	}
	filename = argv[1];
	tofind = argv[2];
	toreplace = argv[3];
	if (!filename.size()
		|| !tofind.size()
		|| !toreplace.size())
	{
		std::cerr << "Please provide non-NULL arguments";
		return (1);
	}
	toopen.open(filename.c_str());					// stream assignment from filename argv argument.
	if (toopen.rdstate() == std::ios_base::badbit) // check if badbit bool is flagged.
	{
		std::cerr << "Error in file opening.";
		return (1);
	}
	outfile_name = filename + ".replace";
	towrite.open(outfile_name.c_str());
	if (towrite.rdstate() == std::ios_base::badbit)
	{
		std::cerr << "Error in file opening.";
		return (1);
	}	
	while (getline(toopen, line))
	{
		match = line.find(tofind);
		for (unsigned long x = 0; x < line.size(); x++)
		{
			if ((match = line.find(tofind, x)) != line.npos)
			{
				substring = line.substr(x, (match - x));
				result.append(substring);
				result.append(toreplace);
				substring.erase();
				x = match + tofind.size() - 1;		// x shall be cursor, so it shall be size - 1
			}
			else
			{
				substring = line.substr(x, (line.size() - x));
				result.append(line.substr(x));
				break;
			}
		}
		if (line.size())
			result.append("\n");
	}
	towrite << result;
}