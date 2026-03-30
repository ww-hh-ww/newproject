#include"StringBuilder.h"
#include <iostream>
#include <cstring>
#include <cmath>

	//针对新的字符串长度，判断是否需要重定义str数组大小（扩容或缩容）,并进行相应的内存操作
	void StringBuilder::resize(int newLength, bool copyOldStr) {
		if (growthFactor < 1.1) growthFactor = 1.1;
		if (growthFactor > 10) growthFactor = 10;

		if (newLength >= capacity || !str) {
			// 扩容
			int newCapacity = capacity;
			while (newLength >= newCapacity) {
				newCapacity = static_cast<int>(ceil(newCapacity * growthFactor));
			}
			char* newStr = new char[newCapacity];
			if (str && copyOldStr) {
				strcpy_s(newStr, newCapacity, str);
				delete[] str;
			}
			str = newStr;
			capacity = newCapacity;
		}
		else if (autoShrink && newLength < capacity / growthFactor - 1) {
			// 缩容
			int newCapacity = capacity;
			while (newCapacity > newLength && newCapacity > 0 && static_cast<int>(newCapacity / growthFactor) > newLength) {
				newCapacity = static_cast<int>(newCapacity / growthFactor);
			}
			char* newStr = new char[newCapacity];
			if (str && copyOldStr) {
				strcpy_s(newStr, newCapacity, str);
				delete[] str;
			}
			str = newStr;
			capacity = newCapacity;
		}
	}


	StringBuilder::StringBuilder() {
		resize(0);
	}

	StringBuilder::StringBuilder(int cap) {
		if (cap < 1) cap = 1;
		capacity = cap;
		str = new char[capacity];
	}

	StringBuilder::StringBuilder(const char* s, int cap) {
		length = strlen(s);
		if (cap < length + 1) cap = length + 1;
		capacity = cap;
		str = new char[capacity];
		strcpy_s(str, capacity, s);
	}

	StringBuilder::StringBuilder(const char* s) {
		length = strlen(s);
		resize(length, false);
		strcpy_s(str, length + 1, s);
	}

	StringBuilder:: StringBuilder(const StringBuilder& other) {
		length = other.length;
		resize(length, false);
		strcpy_s(str, length + 1, other.str);
	}

	StringBuilder::~StringBuilder() {
		delete[] str;
	}

	const char* StringBuilder::getStr() const {
		return str;
	}

	StringBuilder StringBuilder::substr(int start, int end) 
	{
		if (start < 0 || end >= length || start > end) {
			cerr << "Invalid substring range." << endl;
			return StringBuilder();
		}
		char* subStr = new char[end - start + 2];
		strncpy_s(subStr, end - start + 2, str + start, end - start + 1);
		StringBuilder result(subStr);
		delete[] subStr;
		return result;
	}

	int StringBuilder::getLength() const {
		return length;
	}

	bool StringBuilder::operator==(const StringBuilder& other) const {
		return strcmp(str, other.str) == 0;
	}

	ostream& operator<<(ostream& os, const StringBuilder& sb) {
    os << sb.getStr();
    return os;
}

StringBuilder operator+(const StringBuilder& lhs, const StringBuilder& rhs) {
	StringBuilder result(lhs.length + rhs.length + 1);
		strcpy_s(result.str, result.capacity, lhs.str);
		strcat_s(result.str, result.capacity, rhs.str);
		result.length = lhs.length + rhs.length;
		return result;
}

StringBuilder& StringBuilder::operator=(const StringBuilder& other) {
	if (this != &other) {
		length = other.length;
		resize(length, false);
		strcpy_s(str, length + 1, other.str);
	}
	return *this;
}

StringBuilder& StringBuilder::operator+=(const StringBuilder& other) 
{
	int length = length + other.length;
	resize(length, true);
	strcat_s(str, capacity, other.str);
	return *this;
}
