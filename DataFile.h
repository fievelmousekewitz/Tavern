#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
void readCSV(std::istream &input, std::vector< std::vector<std::string> > &output)
{
	std::string csvLine;	// read every line from the stream
	while( std::getline(input, csvLine) )
	{		std::istringstream csvStream(csvLine);
		std::vector<std::string> csvColumn;
		std::string csvElement;		// read every element from the line that is seperated by commas
	
		// and put it into the vector or strings
		while( std::getline(csvStream, csvElement, ',') )
		{
			csvColumn.push_back(csvElement);
		}
				output.push_back(csvColumn);
	}
}