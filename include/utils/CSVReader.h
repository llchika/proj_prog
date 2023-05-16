#ifndef _CSVReader_H
#define _CSVReader_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class CSVReader
{
private :
	std::string m_filename;
	char m_delimiter;

public :
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="filename">Filename to read</param>
	/// <param name="delimiter">The delimiter of the csv file</param>
	CSVReader(std::string filename, char delimiter = ';');
	/// <summary>
	/// Function to fetch data from a CSV File
	/// </summary>
	/// <returns>The data</returns>
	std::vector<std::vector<int>> getData();

};

#endif
