#ifndef _LINKED_NODE_H_
#define _LINKED_NODE_H_

#include <iostream>
#include <stdint.h>
#include <assert.h>
using namespace std;


typedef int data_type;
typedef struct _Node
{
	data_type data;
	_Node *next;
}Node;



class LinkedList
{
public:
	typedef data_type value_type;
	typedef std::size_t sizt_type;

public:
	LinkedList();
	virtual ~LinkedList();
	sizt_type list_length();
	void list_head_insert(const value_type& val);
	void list_insert(const value_type& val);
	Node* list_search(const value_type& target);
	Node* list_locate(const sizt_type& position);
	Node* operator[] (const sizt_type& index);
	void list_remove_one(const value_type& val);
	void list_clear();

	void print()const;
private:
	Node *m_head;
	Node *m_tail;
	sizt_type m_length;
};

#endif