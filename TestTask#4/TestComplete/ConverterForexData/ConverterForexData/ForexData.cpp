#include "ForexData.h"

#include <algorithm>
#include <ctime>
#include <iterator>
#include <fstream>

#include <filesystem>

#pragma warning(disable : 4996)

ForexData::ForexData(std::string inputPathAndFileName, std::string outputPath) {
	this->inputPathAndFileName = inputPathAndFileName;
	this->outputPath = outputPath + "./";
}

void ForexData::read_data() {
	std::ifstream input_file(inputPathAndFileName);
	std::string line;

	if ( getline(input_file, line) ) {
		data.push_back(line);
	}

	while ( std::getline(input_file, line) ) {
		if ( !std::equal(data.back().begin(), data.back().end(), line.begin(), line.end()) ) {
			data.push_back(line);
		}
	}
	input_file.close();
}

void ForexData::convert_data() {
	std::size_t i;
	std::string::iterator it_start, it_end;
	std::string::reverse_iterator rev_it_start, rev_it_end;
	std::string line;
	std::string temp[4];
	std::time_t time;
	struct tm* struct_time;

	rev_it_start = std::find(inputPathAndFileName.rbegin(), inputPathAndFileName.rend(), '.');
	std::advance(rev_it_start, 1);
	rev_it_end = std::find(rev_it_start, inputPathAndFileName.rend(), '_');
	i = rev_it_end - rev_it_start;
	(*temp).resize(i); (*(temp + 1)).resize(i);
	std::copy(rev_it_start, rev_it_end, (*(temp + 1)).begin());
	std::copy((*(temp + 1)).rbegin(), (*(temp + 1)).rend(), (*temp).begin());
	rev_it_start = rev_it_end; std::advance(rev_it_start, 1);
	rev_it_end = std::find_if(rev_it_start, inputPathAndFileName.rend(), [](const char& a) {
			return a == '/' || a == '\\'; 
		});
	i = rev_it_end - rev_it_start;
	(*(temp + 3)).resize(i); (*(temp + 1)).resize(i);
	std::copy(rev_it_start, rev_it_end, (*(temp + 1)).begin());
	std::copy((*(temp + 1)).rbegin(), (*(temp + 1)).rend(), (*(temp + 3)).begin());
	time = std::stoll(*temp);
	(*temp).clear(); (*(temp + 1)).clear();
	struct_time = std::gmtime(&time);
	(*temp).resize(24);
	std::strftime(const_cast<char*>((*temp).data()), (*temp).size(), "%Y", struct_time);
	outputPath += (*temp).c_str();
	outputPath.push_back('/');
	std::strftime(const_cast<char*>((*temp).data()), (*temp).size(), "%m", struct_time);
	line += (*temp).c_str();
	outputPath += (*temp).c_str();
	outputPath.push_back('/');
	std::strftime(const_cast<char*>((*temp).data()), (*temp).size(), "%Y%m%d", struct_time);
	outputFileName = *(temp + 3) + '_' + (*temp).c_str() + ".tck";
	(*temp).clear();
	
	for ( auto& elem : data ) {
		it_start = elem.begin();
		i = 0;

		do {
			it_end = std::find(it_start, elem.end(), ';');
			temp[i].resize(it_end - it_start);
			std::copy(it_start, it_end, temp[i].begin());
			if (it_end == elem.end()) {
				break;
			}
			it_start = it_end; std::advance(it_start, 1);
			i += 1;
		} while (true);

		line = *(temp + 3);
		line.push_back(',');
		time = std::stoll(*temp);
		struct_time = std::gmtime(&time);
		(*temp).clear();
		(*temp).resize(24);
		std::strftime(const_cast<char*>((*temp).data()), (*temp).size(), "%Y%m%d", struct_time);
		line += (*temp).c_str();
		line.push_back(',');
		std::strftime(const_cast<char*>((*temp).data()), (*temp).size(), "%H%M%S", struct_time);
		line += (*temp).c_str();
		line.push_back(',');
		line += *(temp + 2);
		line.push_back(',');
		line += *(temp + 1);
		elem.resize(line.size());
		std::copy(line.cbegin(), line.cend(), elem.begin());
		line.clear();
	}
}

void ForexData::write_to_file() {
	std::filesystem::create_directories(outputPath);
	std::ofstream output_file(outputPath + outputFileName);
	std::ostream_iterator<std::string> output_iterator(output_file, "\n");
	std::copy(data.begin(), data.end(), output_iterator);
	output_file.close();
}

void ForexData::delete_oldFile()
{
	std::filesystem::path path(inputPathAndFileName);
	std::filesystem::remove(path);
}
