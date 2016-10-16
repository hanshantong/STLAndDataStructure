#include "LinkedList.h"
LinkedList::LinkedList()
{
	m_head = new Node();
	m_head->next = NULL;
	m_tail = new Node();
	m_tail->next = NULL;
	m_length = 0;
}

LinkedList::~LinkedList()
{
	list_clear();
}

LinkedList::sizt_type LinkedList::list_length()
{
	return m_length;
}

void LinkedList::list_head_insert(const value_type& val)
{
	Node *s = new Node();
	s->data = val;
	if (m_head->next == NULL)
	{
		s->next = m_head->next;
		m_head->next = s;
		m_tail->next = s;
		m_length++;
		return;
	}
	s->next = m_head->next;
	m_head->next = s;
	m_length++;
}

void LinkedList::list_insert(const value_type& val)
{

	Node *s = new Node();
	s->data = val;
	if (m_head->next == NULL)
	{
		s->next = m_head->next;
		m_head->next = s;
		m_tail->next = s;
		m_length++;
		return;
	}
	m_tail->next->next = s;
	m_tail->next = s;
	m_length++;

}

Node* LinkedList::list_search(const value_type& target)
{
	Node* p = m_head->next;
	for (; p != NULL; p = p->next)
	{
		if (target == p->data)
			return p;
	}
	return NULL;
}

Node* LinkedList::list_locate(const sizt_type& position)
{
	if (position < 0 || position >= m_length)
		return NULL;
	Node* p = m_head->next;
	return (*this)[position];
}
//从0开始计数
Node* LinkedList::operator[] (const sizt_type& index)
{
	if (index < 0 || index >= m_length)
		return NULL;
	sizt_type i = 0;
	Node *p = m_head->next;
	while (i < m_length && p != NULL)
	{
		if (i == index)
			break;
		i++;
		p = p->next;
	}
	if (i == m_length)
		return NULL;
	return p;
}


void LinkedList::list_remove_one(const value_type& val)
{
	Node* p = m_head;
	Node *q = NULL;
	while (p != NULL)
	{
		if (NULL != p->next && val == p->next->data)
		{
			q = p->next;
			if (NULL == q->next)
			{
				m_tail->next = p;
			}
			p->next = q->next;
			delete q;
			return;
		}
		p = p->next;
	}
}

void LinkedList::list_clear()
{
	Node *p = m_head->next;
	Node *q;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
	delete m_head;
	delete m_tail;
}

void LinkedList::print()const
{
	Node *p = m_head->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

