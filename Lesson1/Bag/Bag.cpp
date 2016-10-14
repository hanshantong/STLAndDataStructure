#include "Bag.h"
Bag::size_type Bag::CAPACITY = 100;
Bag::Bag()
{
	m_used = 0;
	m_data = new value_type[CAPACITY];
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
	/*Bag::size_type b1_len = b1.size();
	Bag::size_type b2_len = b2.size();

	if (Bag::CAPACITY < b1_len + b2_len)
	{
	Bag::CAPACITY = b1_len + b2_len + 50;
	Bag::value_type *tmp = new Bag::value_type[Bag::CAPACITY];

	for (Bag::size_type i = 0; i < b1_len; ++i)
	{
	tmp[i] = b1.m_data[i];
	}

	for (Bag::size_type i = 0; i < b2_len; ++i)
	{
	tmp[i] = b1.m_data[i];
	}

	bag.m_used = b1_len + b2_len;
	delete[] bag.m_data;
	bag.m_data = tmp;
	return bag;
	}

	for (Bag::size_type i = 0; i < b1_len; ++i)
	{
	bag.m_data[bag.m_used++] = b1.m_data[i];
	}

	for (Bag::size_type i = 0; i < b2_len; ++i)
	{
	bag.m_data[bag.m_used++] = b1.m_data[i];
	}*/
}