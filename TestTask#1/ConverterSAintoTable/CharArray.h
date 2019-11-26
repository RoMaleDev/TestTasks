#ifndef CHARARRAY_H
#define CHARARRAY_H

#include <iostream>
#include <cstdlib>

typedef struct  {
	char Char;
	unsigned char mark : 2;
	typedef enum { OFF = 0, COMMENT, STRING, QUOTES } markOn;
} magicChar;

class OutOfMemoryException {};
class ZeroLenException {};

class CharArray {
private:
	magicChar* array;
	std::size_t capacity;
	double multiplier;
	std::size_t current;
public:
	CharArray(std::size_t capacity = 1000, double multiplier = 1.15);
	~CharArray();

	std::size_t size() const;
	std::size_t max_size() const;

	magicChar& value(size_t index);
	void eraseItem(int index);
	void eraseArray();
	void insert(char value, int index);

	void push_back(char value);
	magicChar pop_back();

	bool isMatch(const char* other, size_t index) const;

	magicChar& operator[](int index) const;
	magicChar& operator*()  {
		return *array;
	}
	bool operator==(const CharArray& other) const;
	bool operator!=(const CharArray& other) const;

	friend class CAPointer;
};

std::ostream& operator<<(std::ostream& out, const CharArray& list);

#endif // CHARARRAY_H