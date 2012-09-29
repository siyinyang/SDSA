#pragma once
#include <iostream>
using namespace std;


template <typename key_type, typename value_type>
class Node
{

public:
	key_type key;
	value_type value;

	Node(void){}
	Node(key_type k, value_type v):key(k),value(v){}
	~Node(void){}
	

	bool operator< (const Node<key_type, value_type>& node);
	bool operator> (const Node<key_type, value_type>& node);
	friend ostream& operator<< <> (ostream& output, const Node<key_type, value_type>& node);

};

