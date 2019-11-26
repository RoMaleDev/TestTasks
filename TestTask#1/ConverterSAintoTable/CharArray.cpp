#include "CharArray.h"

CharArray::CharArray(std::size_t capacity, double multiplier) : capacity(capacity), current(0), multiplier(multiplier) {
	array = (magicChar*)std::malloc(capacity*sizeof(magicChar));

	if (array == NULL) {
		throw OutOfMemoryException();
	}
}

CharArray::~CharArray() {
	std::free(array);
}

std::size_t CharArray::size() const {
	return this->current;
}

std::size_t CharArray::max_size() const {
	return this->capacity;
}

void CharArray::eraseItem(int index) {
	for (index += 1; index < this->current; index++) {
		array[index - 1] = array[index];
	}
	this->pop_back();
}

void CharArray::eraseArray() {
	this->current = 0;
}

void CharArray::insert(char value, int index) {
	std::size_t newCurrent = current + 1;

	if (newCurrent > capacity) {
		std::size_t newCapacity = capacity * multiplier;
		magicChar* newArray = (magicChar*)std::realloc(array, newCapacity*sizeof(magicChar));

		if (newArray == NULL) {
			throw OutOfMemoryException();
		}

		capacity = newCapacity;
		array = newArray;
	}
	for (int i = current; i > index; i--) {
		array[i] = array[i - 1];
	}
	this->current = newCurrent;
	this->array[index].Char = value;
	this->array[index].mark = magicChar::OFF;
}

void CharArray::push_back(char value) {
	int newCurrent = current + 1;

	if (newCurrent > capacity) {
		std::size_t newCapacity = capacity * multiplier;
		magicChar* newArray = (magicChar*)std::realloc(array, newCapacity*sizeof(magicChar));

		if (newArray == NULL) {
			throw OutOfMemoryException();
		}

		capacity = newCapacity;
		array = newArray;
	}
	array[current].Char = value;
	array[current].mark = magicChar::OFF;
	current = newCurrent;
}

magicChar CharArray::pop_back() {
	if (current == 0) {
		throw ZeroLenException();
	}
	current -= 1;
	return array[current];
}

magicChar& CharArray::value(size_t index) {
	return array[index];
}

bool CharArray::isMatch(const char* other, size_t index) const {
	bool toggle = false;
	size_t length = strlen(other);

	if (this->current > (index + length)) {
		toggle = true;

		for (int i = 0; i < length && toggle; i++) {
			toggle = this->array[i + index].Char == other[i];
		}
	}
	return toggle;
}

magicChar& CharArray::operator[](int index) const {
	return this->array[index];
}

bool CharArray::operator==(const CharArray& other) const {
	bool toggle = false;

	if (this->current == other.current) {
		toggle = true;

		for (int i = 0; i < this->current && toggle; i++) {
			toggle = this->array[i].Char == other.array[i].Char;
		}
	}
	return toggle;
}

bool CharArray::operator!=(const CharArray& other) const {
	return !operator==(other);
}

std::ostream& operator<<(std::ostream& out, const CharArray& list) {
	int last = list.size() - 1;

	for (int i = 0; i < last; i++) {
		out << list[i].Char;
	}
	out << list[last].Char;
	return out;
}
