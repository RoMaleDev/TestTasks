#include "ConvertData.h"

ConvertData::ConvertData()
{
	this->charArray = new CharArray();
	this->result = new foundData[4];
	this->stringArray = new std::vector<std::string>();
}

ConvertData::~ConvertData() {
	charArray->~CharArray();
	delete[] result;
}

std::string& ConvertData::extractComment(std::string& str) {
	CAPointer charArrayPtr(*charArray);
	this->charArray->eraseArray();

	for (std::size_t index = 0; index < str.length(); index++) {
		this->charArray->push_back(str.at(index));
	}

	this->markArray();

	char *charString = new char[charArray->size() + 1];
	std::size_t char_index = 0;

	for (std::size_t it_index = 0; it_index < charArray->size(); it_index++) {
		if (charArrayPtr[it_index].mark == magicChar::COMMENT) {
			charString[char_index] = charArrayPtr[it_index].Char;
			char_index += 1;
		}
	}
	charString[char_index] = '\0';

	str.clear();
	str.append(charString);

	delete[] charString;
	return str;
}

void ConvertData::push_back(char value) {
	this->charArray->push_back(value);
}

void ConvertData::markArray() {
	size_t indx = 0;
	bool MarkON = false;
	CAPointer charArrayPtr(*charArray);

start:
	for (; !MarkON && indx < charArray->size(); indx++) {
		if (charArray->value(indx).Char == '/' || charArrayPtr[indx].Char == '\"') {
			MarkON = true;
		}
	}
	if (indx >= charArray->size())
		return;
	indx -= 1;
	if (charArray->isMatch("//", indx)) {
		for (; (charArrayPtr[indx].Char != '\n' && indx < charArray->size()); indx++) {
			charArrayPtr[indx].mark = magicChar::COMMENT;
		}
		MarkON = false;
		goto start;
	}

	if (charArray->isMatch("/*", indx)) {
		for (; MarkON && indx < charArray->size(); indx++) {
			charArrayPtr[indx].mark = magicChar::COMMENT;
			if (charArrayPtr[indx].Char == '/') {
				if (charArray->isMatch("*/", indx - 1))
					MarkON = false;
			}
		}
		goto start;
	}

	if (!charArray->isMatch("\\\"", indx - 1)) {
		charArrayPtr[indx].mark = magicChar::QUOTES;
		for (indx++; MarkON && indx < charArray->size(); indx++) {
			charArrayPtr[indx].mark = magicChar::STRING;
			if (charArrayPtr[indx].Char == '\"') {
				if (!charArray->isMatch("\\\"", indx - 1)) {
					charArrayPtr[indx].mark = magicChar::OFF;
					MarkON = false;
				}
			}
		}
		goto start;
	}
	else {
		indx++;
		MarkON = false;
		goto start;
	}
}

bool ConvertData::searchData() {
	std::cmatch result;
	std::regex regular("char\\s*\\*\\s*\\w+\\s*\\[\\s*(\\w*)\\s*\\]\\s*\\[\\s*(\\w*)\\s*\\][\\s=]*\\{\\s*\\{\\s*\\\"");
	CAPointer charArrayPtr(*charArray);
	char *charString = new char[charArray->size() + 1];

	for (size_t index; index < charArray->size(); index++) {
		if (!charArrayPtr[index].mark || charArrayPtr[index].mark == magicChar::QUOTES) {
			charString[index] = charArrayPtr[index].Char;
		}
		else {
			charString[index] = '\x20';
		}
	}
	charString[charArray->size()] = '\0';

	std::regex_search(charString, result, regular);

	if (!result.size()) {
		return false;
	}

	for (std::size_t i = 0; i < result.size(); i++) {
		(*(this->result + i)).position = result.position(i);
		(*(this->result + i)).length = result.length(i);
		(*(this->result + i)).data = result[i];
	}
	delete[] charString;
	return true;
}

void ConvertData::clearData() {
	charArray->eraseArray();
	stringArray->clear();
}

void ConvertData::moveDataToTable() {
	bool markON = false;
	bool quotes = false;
	CAPointer charArrayPtr(*charArray);
	this->columns = std::atoi(((std::string)result[2].data).c_str());
	this->rows = std::atoi(((std::string)result[1].data).c_str());

	std::size_t pivotPoint = result[0].position + result[0].length;
	char *charToString0 = new char[pivotPoint + 1];

	for (std::size_t index = 0; index < pivotPoint; index++) {
		charToString0[index] = charArrayPtr[index].Char;
	}
	charToString0[pivotPoint] = '\0';
	stringArray->push_back(charToString0);

	if (charArrayPtr[pivotPoint].mark != magicChar::STRING) {
		stringArray->push_back("");
	}
	delete[] charToString0;
	
	char *charToString = new char[charArray->size() - pivotPoint];

	for (size_t index = pivotPoint; index < charArray->size();) {
		if (charArrayPtr[index].mark == magicChar::STRING) {
			std::size_t indx = 0;

			for (; charArrayPtr[index].mark == magicChar::STRING; indx++, index++) {
				charToString[indx] = charArrayPtr[index].Char;
			}
			charToString[indx] = '\0';
			stringArray->push_back(charToString);
		}
		if (charArrayPtr[index].mark != magicChar::STRING) {
			std::size_t indx = 0;
			for (; !markON && charArrayPtr[index].mark != magicChar::STRING; indx++, index++) {

				if (quotes) {
					charToString[indx] = '\0';
					stringArray->push_back(charToString);
					stringArray->push_back("");
					indx = 0;
					quotes = false;
				}
				if (charArrayPtr[index].mark == magicChar::QUOTES) {
					quotes = true;
				}
				charToString[indx] = charArrayPtr[index].Char;

				if (charToString[indx] == ';' && charArrayPtr[index].mark != magicChar::COMMENT) {
					markON = true;
				}
			}
			if (markON) {
				for (; index < charArray->size(); indx++, index++) {
					charToString[indx] = charArrayPtr[index].Char;
				}
			}
			charToString[indx] = '\0';
			stringArray->push_back(charToString);
			quotes = false;
		}
	}
	delete[] charToString;
}

void ConvertData::readyToSave() {
	stringArray->at(0).erase(this->result[2].position, this->result[2].length);
	stringArray->at(0).insert(this->result[2].position, static_cast<std::ostringstream*>(&(std::ostringstream() << this->columns))->str());
	stringArray->at(0).erase(this->result[1].position, this->result[1].length);
	stringArray->at(0).insert(this->result[1].position, static_cast<std::ostringstream*>(&(std::ostringstream() << this->rows))->str());
}

void ConvertData::insertColumn(std::size_t index) {
	std::size_t double_indexColumns = 2 * this->columns;
	std::size_t arr_index = 2 * this->columns * (this->rows - 1) + 2 * index + 1;

	if ( index == this->columns ) {
		arr_index -= 1;

		for (std::size_t it_index = 0; it_index < rows; it_index++) {
			stringArray->insert(stringArray->begin() + arr_index, (std::string)"");
			stringArray->insert(stringArray->begin() + arr_index, (std::string)"\",\"");
			arr_index -= double_indexColumns;
		}
	}
	else {
		for (std::size_t it_index = 0; it_index < rows; it_index++) {
			stringArray->insert(stringArray->begin() + arr_index, (std::string)"\", \"");
			stringArray->insert(stringArray->begin() + arr_index, (std::string)"");
			arr_index -= double_indexColumns;
		}	
	}
	
	this->columns += 1;
}

void ConvertData::deleteColumn(std::size_t index) {
	if (this->columns == 1) {
		// Тут бросить исключение ***********************************************************
	}
	std::string *cache = new std::string("\"");
	std::size_t double_indexColumns = 2 * this->columns;
	std::size_t arr_index = 2 * this->columns * (this->rows - 1) + 2 * index + 1;

	if (index == this->columns - 1) {
		arr_index -= 1;

	    for (std::size_t it_index = 0; it_index < rows; it_index++) {

			*cache += stringArray->at(arr_index);
		    stringArray->erase(stringArray->begin() + arr_index);
		    stringArray->erase(stringArray->begin() + arr_index);

		    *cache = extractComment(*cache);
			cache->insert(0, "\" ");

			stringArray->at(arr_index).erase(0, 1);
		    stringArray->at(arr_index).insert(0,*cache);

		    arr_index -= double_indexColumns;
	    }

    } else {
	    for (std::size_t it_index = 0; it_index < rows; it_index++) {
		    stringArray->erase(stringArray->begin() + arr_index);
		    *cache += stringArray->at(arr_index);
		    stringArray->erase(stringArray->begin() + arr_index);

		    *cache = extractComment(*cache);
			cache->append(" \"");

		    stringArray->at(arr_index - 1).pop_back();
		    stringArray->at(arr_index - 1).append(*cache);

		    arr_index -= double_indexColumns;
	    }
    }
	this->columns -= 1;
	delete cache;
}

void ConvertData::insertRow(std::size_t index) {
	std::size_t arr_index = 2 * this->columns * index + 1;

	if (index == this->rows) {
		arr_index -= 1;
		for (std::size_t it_index = 1; it_index < columns; it_index++) {
			stringArray->insert(stringArray->begin() + arr_index, (std::string)"");
			stringArray->insert(stringArray->begin() + arr_index, (std::string)"\", \"");
		}
		stringArray->insert(stringArray->begin() + arr_index, (std::string)"");
		stringArray->insert(stringArray->begin() + arr_index, (std::string)"\"},\n{\"");
	}
	else {
		stringArray->insert(stringArray->begin() + arr_index, (std::string)"\"},\n{\"");
		stringArray->insert(stringArray->begin() + arr_index, (std::string)"");
		for (std::size_t it_index = 1; it_index < columns; it_index++) {
			stringArray->insert(stringArray->begin() + arr_index, (std::string)"\", \"");
			stringArray->insert(stringArray->begin() + arr_index, (std::string)"");
		}
	}
	this->rows += 1;
}

void ConvertData::deleteRow(std::size_t index) {
	if (this->rows == 1) {
		//***********************************Исключение*********************************************
	}
	std::string *cache = new std::string("\"");
	std::size_t arr_index = 2 * this->columns * index + 1;

	if (index == this->rows - 1) {
		arr_index -= 1;

		for (std::size_t it_index = 0; it_index < columns; it_index++) {
			*cache += stringArray->at(arr_index);
			stringArray->erase(stringArray->begin() + arr_index);
			stringArray->erase(stringArray->begin() + arr_index);
		}
		*cache = extractComment(*cache);
		cache->insert(0, "\" ");

		stringArray->at(arr_index).erase(0, 1);
		stringArray->at(arr_index).insert(0, *cache);
	} else {
		for (std::size_t it_index = 0; it_index < columns; it_index++) {
			stringArray->erase(stringArray->begin() + arr_index);
			*cache += stringArray->at(arr_index);
			stringArray->erase(stringArray->begin() + arr_index);
		}
		*cache = extractComment(*cache);
		cache->append(" \"");

		stringArray->at(arr_index - 1).pop_back();
		stringArray->at(arr_index - 1).append(*cache);
	}
	this->rows -= 1;
	delete cache;
}

void ConvertData::replaceData(std::size_t columnIndex, std::size_t rowIndex, std::string data) {
	std::size_t arr_index = 2 * (rowIndex * this->columns + columnIndex) + 1;
	stringArray->at(arr_index).clear();
	stringArray->at(arr_index).append(data);
}
