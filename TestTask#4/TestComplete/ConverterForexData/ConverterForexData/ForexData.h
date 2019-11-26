#pragma once

#include <string>
#include <vector>

class ForexData
{
private:
	std::string inputPathAndFileName;
	std::string outputPath;
	std::string outputFileName;
	std::vector<std::string> data;
public:
	ForexData(std::string inputPathAndFileName, std::string outputPath);
	void read_data();
	void convert_data();
	void write_to_file();
	void delete_oldFile();
};

