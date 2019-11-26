#ifndef CAPOINTER_H
#define CAPOINTER_H

#include <cstdlib>
#include "CharArray.h"

class CAPointer {
	CharArray& charArray;
	int index;
public:
	CAPointer(CharArray& objc);
	bool over();
	void reset();
	void next();
	void previous();

	//Type value();

	void operator++();
	void operator++(int);
	void operator--();
	void operator--(int);
	magicChar& operator[](int index) const;
	//Type operator*();
	// ����������� �������� �������� ������� ����� ������:
	/*bool operator++() { // ���������� ������
	if (index >= oc.a.size()) return false;
	if (oc.a[++index] == 0) return false;
	return true;
	}
	bool operator++(int) { // ����������� ������
	return operator++(); // ������������� ���������� ������
	}
	Obj* operator->() const {
	require(oc.a[index] != 0, "Zero value "
	"returned by SmartPointer::operator->()");
	return oc.a[index];
	}*/
};
#endif // CAPOINTER_H