#include"StringBuilder.h"
#include <iostream>
using namespace std;

int main()
{
    StringBuilder str1 = "Hello, World! ";
	StringBuilder str2 = "C++ Programming";

	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;

	// Concatenation
	StringBuilder str3 = str1 + str2;
	str3 = str3 + " is fun!";
	str3 += " Let's learn it.";

	cout << "Concatenated String: " << str3 << endl;
	// Substring
	StringBuilder substr = str1.substr(0, 5);
	cout << "Substring: " << substr << endl;
	// Length
	cout << "Length of str1: " << str1.getLength() << endl;
	// Comparison
	if (str1 == str2) {
		cout << "str1 and str2 are equal." << endl;
	}
	else {
		cout << "str1 and str2 are not equal." << endl;
	}
	return 0;


}