#ifndef _MY_STRING_H_
#define _MY_STRING_H_
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

using namespace std;
class MyString
{
public:
	MyString();
	MyString(const char str[]);
	explicit MyString(const MyString& s);
	virtual ~MyString();

	char operator[] (const size_t pos);
	void operator+= (const MyString& addend);
	void operator+= (const char addend[]);
	void operator+= (char addend);
	bool operator== (const MyString& s);
	MyString& operator = (const MyString& s);
	MyString& operator = (const char addend[]);
	MyString& operator = (const char ch);

	friend MyString& operator + (const MyString& s1, const MyString& s2);
	friend istream& operator >> (istream& ins,MyString& s);
	friend ostream& operator << (ostream& ons, const MyString& s);

	void reserve(size_t n);
protected:

private:
	
	size_t m_allocated;
	size_t m_current_length;
public:
	char *m_characters;
};


#endif