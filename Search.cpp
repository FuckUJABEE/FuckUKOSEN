#include"Search.h"

#include<fstream>
#include<sstream>
#include<vector>
#include<iostream>

std::vector<std::string> split(const std::string& input, char delimiter)
{
	std::istringstream stream(input);

	std::string field;
	std::vector<std::string> result;
	while (std::getline(stream, field, delimiter)) {
		result.push_back(field);
	}
	return result;
}

void Search::getSearchString(const std::string& _searchString)
{
	searchString = _searchString;
}

bool Search::searchFromCSV()
{
	std::ifstream ifs(fileNameCSV);

	if (ifs){
		for (std::string line; std::getline(ifs, line);)
		{
			ResponceSet _rs;
			bool responcibleFlag = false;
			int getVarCount = 0;
			
			for (const std::string& s : split(line, ',')) {
				if (getVarCount == 0 && !(s.find(searchString) == std::string::npos)){
					responcibleFlag = true;
				}

				if (responcibleFlag){
					switch (getVarCount){
					case 0:
						_rs.name = s;
						break;
					case 3:
						_rs.URL = s;
						break;
					}
				}
				++getVarCount;
			}
			if (responcibleFlag)
				responceSet.push_back(_rs);
		}
	}
	else{
		std::cout << "error" << std::endl;
	}

	std::cout << std::endl;
	return false;
}

bool Search::responceToTerminal()
{
	if (!responceSet.empty()){
		for (auto it : responceSet){
			std::cout << it.name << " " << it.URL << std::endl;
		}
	}
	else{
		std::cout << "Empty!" << std::endl;
	}

	return true;
}