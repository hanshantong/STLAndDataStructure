#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_
#include <iostream>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

using namespace std;
class Sequence
{
public:
	typedef int value_type;
	typedef std::size_t size_type;
	typedef int index_type;
	static  size_type CAPACITY;

public:
	Sequence();
	size_type size() const;
	void insert(const value_type& entry);
	void attach(const value_type& entry);
	size_type count(const value_type& target) const;
	bool erase_one(const value_type& target);
	size_type erase(const value_type& target);
	void operator += (const Sequence& b);
	void remove_current();

	value_type getCurrentItem()const;
	//iterator
	void start();
	value_type current() const;
	void advance();
	bool isItem();

	//print elements
	void print()
	{
		size_type i = 0;
		while (i < m_used)
		{
			cout << m_data[i] << " ";
			i++;
		}
		cout << endl;
	}

	friend Sequence operator + (const Sequence& b1, const Sequence& b2);
private:
	value_type *m_data;
	size_type m_used;
	index_type m_index;

};

#endif