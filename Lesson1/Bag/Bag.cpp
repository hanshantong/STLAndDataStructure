#include "Bag.h"
Bag::size_type Bag::CAPACITY = 100;
Bag::Bag()
{
	m_used = 0;
	m_data = new value_type[CAPACITY];
}

Bag::Bag(size_type size)
{
	if (CAPACITY < size)
		CAPACITY = size;
	m_used = 0;
	m_data = new value_type[CAPACITY];
}

Bag::Bag(const Bag& b)
{
	this->m_used = b.size();
	if (NULL != m_data)
		delete[] m_data;

	size_type b_len = b.size();
	if (CAPACITY > b_len)
		m_data = new value_type[CAPACITY];
	else
		m_data = new value_type[b_len + 30];

	for (size_type i = 0; i < b_len; ++i)
		m_data[i] = b.getItem(i);
}

Bag::size_type Bag::size() const
{
	return m_used;
}

void Bag::insert(const value_type& entry)
{
	m_data[m_used++] = entry;
}

Bag::size_type Bag::count(const value_type& target) const
{
	size_type cnt = 0;
	for (size_type i = 0; i < m_used; ++i)
	{
		if (target == m_data[i])
			cnt++;
	}
	return cnt;
}

bool Bag::erase_one(const value_type& target)
{
	for (size_type i = 0; i < m_used; ++i)
	{
		if (target == m_data[i])
		{
			size_type j = i;
			while (j < m_used - 1)
			{
				m_data[j] = m_data[++j];
			}
			m_used--;
			return true;
		}
	}
	return false;
}

Bag::size_type Bag::erase(const value_type& target)
{
	size_type i = 0;
	size_type cnt = 0;
	while (i < m_used)
	{
		if (target == m_data[i])
		{
			size_type j = i;
			while (j < m_used - 1)
			{
				m_data[j] = m_data[++j];
			}
			m_used--;
			cnt++;
		}
		i++;
	}
	return cnt;
}

void Bag::operator += (const Bag& b)
{
	if (this == &b) //防止bag += bag
		return;
	size_type b_len = b.size();
	if (m_used + b_len > CAPACITY)
	{
		CAPACITY = m_used + b_len + 50;
		value_type *temp = new value_type[CAPACITY];
		for (size_type i = 0; i < m_used; ++i)
		{
			temp[i] = m_data[i];
		}

		for (size_type i = 0; i < b_len; ++i)
		{
			temp[m_used + i] = b.m_data[i];
		}
		delete[] m_data;
		m_data = temp;
		m_used += b_len;
	}

	for (size_type i = 0; i < b.size(); ++i)
	{
		m_data[m_used++] = b.m_data[i];
	}
}

Bag operator + (const Bag& b1, const Bag& b2)
{
	Bag bag;
	bag += b1;
	bag += b2;
	return bag;
}

void Bag::operator = (const Bag& b)
{
	if (m_data != NULL)
		delete[] m_data;
	size_type b_len = b.size();
	if (b_len < CAPACITY)
		m_data = new value_type[CAPACITY];
	else
		m_data = new value_type[b_len + 30];

	for (size_type i = 0; i < b_len; ++i)
		m_data[i] = b.getItem(i);
	m_used = b.size();
}

Bag::value_type Bag::getItem(size_type i)const
{
	assert(i >= 0 && i < m_used);
	return m_data[i];
}