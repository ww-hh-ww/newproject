#ifndef __STRING_BUILDER_H__
#define __STRING_BUILDER_H__

#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class StringBuilder {
private:
	char* str = nullptr;
	int length = 0;
	int capacity = 1;
	double growthFactor = 2.0;	//必须大于1.0
	bool autoShrink = true;		//是否自动缩容

	//针对新的字符串长度，判断是否需要重定义str数组大小（扩容或缩容）,并进行相应的内存操作
	void resize(int newLength, bool copyOldStr = false) ;

public:
	StringBuilder() ;

	StringBuilder(int cap) ;

	StringBuilder(const char* s, int cap) ;

	StringBuilder(const char* s) ;

	StringBuilder(const StringBuilder& other) ;

	~StringBuilder() ;

	const char* getStr() const ;
	
	StringBuilder substr(int start, int end) ;

	int getLength() const ;

	bool operator==(const StringBuilder& other) const ;

	friend ostream& operator<<(ostream& os, const StringBuilder& sb) ;

	friend StringBuilder operator+(
		const StringBuilder& lhs, const StringBuilder& rhs) ;
	
	StringBuilder& operator=(const StringBuilder& other);
	StringBuilder& operator+=(const StringBuilder& other);
	
};


#endif
