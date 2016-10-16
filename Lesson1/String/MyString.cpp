#include "MyString.h"

/**
*
*brief:constructor
*param:
*/

MyString::MyString()
{
	m_current_length = strlen("");
	m_allocated = m_current_length + 1;
	m_characters = new char[m_allocated];
	strcpy(m_characters, "");
}

MyString::MyString(const char str[])
{
	m_current_length = strlen(str);
	m_allocated = m_current_length + 1;
	m_characters = new char[m_allocated];
	strcpy(m_characters, str);
	m_characters[m_current_length] = '\0';
}
MyString::MyString(const MyString& s)
{
	m_allocated = s.m_allocated;
	m_current_length = s.m_current_length;
	m_characters = new char[m_allocated];
	strcpy(m_characters, s.m_characters);
	
}

/*
*
*brief:deconstructor
*param:
*/
MyString::~MyString()
{
	if (NULL != m_characters)
		delete[] m_characters;
}


/****variable functions definitions*****/

bool MyString::operator== (const MyString& s)
{
	return (0 == strcmp(this->m_characters, s.m_characters));
}

void MyString::operator += (const MyString& addend)
{
	size_t all_len = m_current_length + addend.m_current_length;
	if (m_allocated < all_len)
		reserve(all_len + 1);
	strcat(m_characters, addend.m_characters);
	m_current_length = all_len;
	m_characters[m_current_length] = '\0';
}

void MyString::operator+= (const char addend[])
{
	size_t all_len = m_current_length + strlen(addend);
	if (m_allocated < all_len)
		reserve(all_len + 1);
	strcat(m_characters, addend);
	m_current_length = all_len;
	m_characters[m_current_length] = '\0';
}

void MyString::operator += (char addend)
{
	if (m_allocated < m_current_length + 1)
		reserve(m_current_length + 2);
	m_characters[m_current_length] = addend;
	m_characters[m_current_length + 1] = '\0';
	m_current_length++;
	m_characters[m_current_length] = '\0';
}

 MyString& MyString::operator = (const MyString& s)
{
	if (m_allocated < s.m_allocated)
	{
		if (NULL != m_characters)
			delete[] m_characters;

		m_characters = new char[s.m_allocated];
		strcpy(m_characters, s.m_characters);
		m_current_length = s.m_current_length;
		m_allocated = s.m_allocated;
	}
	else
	{
		strcpy(m_characters, s.m_characters);
		m_current_length = s.m_current_length;
		m_allocated = s.m_allocated;
	}

	return *this;
}

MyString& MyString::operator = (const char addend[])
{
	size_t len = strlen(addend);
	if (m_allocated <= len)
	{
		reserve(len + 1);
		m_allocated = len + 1;
		m_current_length = len;
		strcpy(m_characters, addend);
		m_characters[m_current_length] = '\0';
	}
	else
	{
		m_current_length = len;
		strcpy(m_characters, addend);
		m_characters[m_current_length] = '\0';
	}
		
	return *this;
}
MyString& MyString::operator = (const char ch)
{
	if (NULL != m_characters)
		delete[] m_characters;
	m_allocated = 2;
	m_characters = new char[m_allocated];
	m_characters[0] = ch;
	m_current_length = 1;
	m_characters[m_current_length] = '\0';
	return *this;
}



void MyString::reserve(size_t n)
{
	char *new_data = NULL;
	if (m_allocated < n)
	{
		new_data = new char[n];

		strcpy(new_data, m_characters);
		if (NULL != m_characters)
			delete[] m_characters;
		m_characters = new_data;
		m_allocated = n;
	}
}

MyString& operator+ (const MyString& s1, const MyString& s2)
{
	MyString str ;
	str += s1;
	str += s2;
	return str;
}
char MyString::operator[] (const size_t pos)
{
	if (pos >= 0 && pos < m_current_length)
		return m_characters[pos];
	return '\0';
}

istream& operator>> (istream& ins, MyString& s)
{
	while (ins && isspace(ins.peek()))
		ins.ignore();
	return ins >> s.m_characters;
}

ostream& operator<< (ostream& ons, const MyString& s)
{
	ons << s.m_characters;
	return ons;
}


