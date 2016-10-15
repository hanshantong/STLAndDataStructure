#ifndef _BAG_H_
#define _BAG_H_
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
using namespace std;

class Bag
{
public:
	typedef int value_type;
	typedef std::size_t size_type;
	static  size_type CAPACITY;

public:
	Bag();
	Bag(size_type size);
	Bag(const Bag& b);

	size_type size() const;
	void insert(const value_type& entry);
	size_type count(const value_type& target) const;
	bool erase_one(const value_type& target);
	size_type erase(const value_type& target);
	void operator += (const Bag& b);
	void operator = (const Bag& b);

	value_type getItem(size_type i)const;
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

	friend Bag operator + (const Bag& b1, const Bag& b2);
private:
	value_type *m_data;
	size_type m_used;




};

#endif