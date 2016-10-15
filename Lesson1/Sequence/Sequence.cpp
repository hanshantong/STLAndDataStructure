#include "Sequence.h"
Sequence::size_type Sequence::CAPACITY = 100;
Sequence::Sequence()
{
	m_used = 0;
	m_data = new value_type[CAPACITY];
	m_index = 0;
}


Sequence::size_type Sequence::size() const
{
	return m_used;
}

void Sequence::insert(const value_type& entry)
{
	if (-1 == m_index)return;
	size_type i = m_used;
	while (i > 0 && i > m_index)
	{
		m_data[i] = m_data[i - 1];
		i--;
	}
	m_data[i] = entry;
	m_index = i;
	m_used++;
}

void Sequence::attach(const value_type& entry)
{
	if (-1 == m_index)return;
	size_type i = m_used;
	while (i > 0 && i > m_index + 1)
	{
		m_data[i] = m_data[i - 1];
		i--;
	}
	m_data[i] = entry;
	m_index = i;
	m_used++;
}

Sequence::size_type Sequence::count(const value_type& target) const
{
	size_type cnt = 0;
	for (size_type i = 0; i < m_used; ++i)
	{
		if (target == m_data[i])
			cnt++;
	}
	return cnt;
}

bool Sequence::erase_one(const value_type& target)
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

//clear all target elements
Sequence::size_type Sequence::erase(const value_type& target)
{
	size_type i = 0;
	size_type cnt = 0;
	size_type number = 0;
	while (i < m_used)
	{
		if (target == m_data[i])
		{
			size_type j = i;
			while (j < m_used )
			{
				m_data[j] = m_data[j+1];
				j++;
			}
			m_used--;
			i--;
			cnt++;
		}
		i++;
	}
	return cnt;
}

void Sequence::operator += (const Sequence& b)
{
	if (this == &b) //防止sequence += sequence
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

Sequence operator + (const Sequence& b1, const Sequence& b2)
{
	Sequence sequence;
	sequence += b1;
	sequence += b2;

	return sequence;
	/*Sequence::size_type b1_len = b1.size();
	Sequence::size_type b2_len = b2.size();

	if (Sequence::CAPACITY < b1_len + b2_len)
	{
	Sequence::CAPACITY = b1_len + b2_len + 50;
	Sequence::value_type *tmp = new Sequence::value_type[Sequence::CAPACITY];

	for (Sequence::size_type i = 0; i < b1_len; ++i)
	{
	tmp[i] = b1.m_data[i];
	}

	for (Sequence::size_type i = 0; i < b2_len; ++i)
	{
	tmp[i] = b1.m_data[i];
	}

	sequence.m_used = b1_len + b2_len;
	delete[] sequence.m_data;
	sequence.m_data = tmp;
	return sequence;
	}

	for (Sequence::size_type i = 0; i < b1_len; ++i)
	{
	sequence.m_data[sequence.m_used++] = b1.m_data[i];
	}

	for (Sequence::size_type i = 0; i < b2_len; ++i)
	{
	sequence.m_data[sequence.m_used++] = b1.m_data[i];
	}*/
}


void Sequence::start()
{
	m_index = 0;
}

Sequence::value_type Sequence::current() const
{
	assert(m_index >= 0 && m_index < m_used);
	return m_data[m_index];
}

void Sequence::advance()
{
	assert(m_index >= 0 && m_index < m_used);
	m_index++;
}

bool Sequence::isItem()
{
	return (m_index >= 0 && m_index < m_used) ? true : false;
}

void Sequence::remove_current()
{
	size_type i = m_index;
	while (i < m_used)
	{
		m_data[i] = m_data[i + 1];
		i++;
	}
	m_used--;
}

Sequence::value_type Sequence::getCurrentItem()const
{
	assert(m_index >= 0 && m_index < m_used);
	return m_data[m_index];
}

