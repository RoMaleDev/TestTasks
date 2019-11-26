#ifndef CONVERTDATA_H
#define CONVERTDATA_H

#include <regex>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <sstream>
#include "CharArray.h"
#include "CAPointer.h"

using namespace System;

typedef struct {
	std::size_t position;
	std::size_t length;
	std::string data;
} foundData;

class ConvertData {
private:
	CharArray *charArray;
	std::vector<std::string> *stringArray;
	foundData * result;
	std::size_t columns;// колонка
	std::size_t rows;  // строки
	std::string& extractComment(std::string& str);
public:
	ConvertData();
	~ConvertData();
	void push_back(char value);
	std::size_t sizeString() { return stringArray->size(); }
	std::size_t sizeC() { return charArray->size(); }
	inline std::size_t ShCol() { return columns; }
	inline std::size_t ShRow() { return rows; }
	std::string ShString(std::size_t index) {
		std::vector<std::string>::iterator it = stringArray->begin();
		return it[index];
	}
	void markArray();
	bool searchData();
	void moveDataToTable();
	void readyToSave();
	void clearData();
	void insertColumn(std::size_t index);
	void deleteColumn(std::size_t index);
	void insertRow(std::size_t index);
	void deleteRow(std::size_t index);
	void replaceData(std::size_t columnIndex, std::size_t rowIndex, std::string data);

};

#endif //CONVERTDATA_H