#include "CAPointer.h"

CAPointer::CAPointer(CharArray& objc) : charArray(objc) {
	index = 0;
}

bool CAPointer::over() {
	if (index < 0) {
		index += 1;
		return true;
	}
	if (index >= charArray.size()) {
		index -= 1;
		return true;
	}
	return false;
}

void CAPointer::reset() {
	this->index = 0;
}

void CAPointer::next() {
	if (over()) {
		return;
	}
	index += 1;
}

void CAPointer::previous() {
	if (over()) {
		return;
	}
	index -= 1;
}

/*template <typename Type>
Type ArrayIterator<Type>::value() {
return array[current];
}*/

void CAPointer::operator++() {
	next();
}

void CAPointer::operator++(int) {
	operator++();
}

void CAPointer::operator--() {
	previous();
}

void CAPointer::operator--(int) {
	operator--();
}

/* SmartPointer::operator*() {
return value();
}*/
magicChar& CAPointer::operator[](int index) const {
	return charArray.array[index];
}