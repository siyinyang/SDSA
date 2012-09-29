#include "StdAfx.h"
#include "Node.h"


template <typename key_type, typename value_type> 
bool Node<key_type, value_type>::operator< (const Node<key_type, value_type>& node){
	return this->key < node.key;
}

template <typename key_type, typename value_type> 
bool Node<key_type, value_type>::operator> (const Node<key_type, value_type>& node){
	return this->key < node.key;
}

template <typename key_type, typename value_type>
ostream& operator<< <> (ostream& output, const Node<key_type, value_type>& node) {
	output<< "(" <<  node.key << ", " << node.value <<")";
    return output;  // for multiple << operators.
}