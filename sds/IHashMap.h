#pragma once
#include <iostream>
#include <tr1/functional>

template <typename key_type, typename value_type>
class IKVNode;

template <typename key_type, typename value_type>
class IHashMap;

template <typename key_type, typename value_type>
std::ostream& operator<< (std::ostream& output, const IKVNode<key_type, value_type>& node);

template <typename key_type, typename value_type>
std::ostream& operator<< (std::ostream& output, const IHashMap<key_type, value_type>& hash_map);

template <typename key_type, typename value_type>
class IKVNode
{
public:
	key_type key;
	value_type value;
	IKVNode* next;  // element with same hash code will linked in a list
	
	IKVNode(void){}
	IKVNode(key_type k, value_type v):key(k),value(v),next(NULL){}
	IKVNode(key_type k, value_type v, IKVNode* node):key(k),value(v),next(node){}
	~IKVNode(void){}
	
	bool operator< (const IKVNode<key_type, value_type>& node);
	bool operator> (const IKVNode<key_type, value_type>& node);
	friend std::ostream& operator<< <> (std::ostream& output, const IKVNode<key_type, value_type>& node);
};

template <typename key_type, typename value_type> 
bool IKVNode<key_type, value_type>::operator< (const IKVNode<key_type, value_type>& node){
	return this->key < node.key;
}

template <typename key_type, typename value_type> 
bool IKVNode<key_type, value_type>::operator> (const IKVNode<key_type, value_type>& node){
	return this->key < node.key;
}

template <typename key_type, typename value_type>
std::ostream& operator<< (std::ostream& output, const IKVNode<key_type, value_type>& node) {
	output<< "(" <<  node.key << ", " << node.value <<")";
	return output;
}

template <typename key_type, typename value_type>
	class IHashMap
{
public:
	int MAX_LEN;
	int size;
	IKVNode<key_type, value_type>** elements;

	void resize(int new_max_len);	
	IHashMap(void):MAX_LEN(100),size(0){
		elements = new IKVNode<key_type, value_type>*[MAX_LEN];
	}
	~IHashMap(void){}

	size_t hash(key_type k);
	bool exist(key_type k);
	void put(key_type k, value_type v);
	//IKVNode<key_type, value_type>* get(key_type k);
	//void remove(key_type k);
	friend std::ostream& operator<< <key_type, value_type>(std::ostream& output, const IHashMap<key_type, value_type>& hash_map);
};

template <typename key_type, typename value_type>
void IHashMap<key_type, value_type>::resize(int NEW_MAX_LEN){
	IKVNode<key_type, value_type>** new_table = new IKVNode<key_type, value_type>*[NEW_MAX_LEN];
		
	size_t new_hash_code = 0;
	for(int i = 0; i != MAX_LEN; ++i){
		if(elements[i]){
			new_hash_code = hash(elements[i]->key) % NEW_MAX_LEN;
			new_table[new_hash_code] = elements[i];
		}
	}

	swap(elements, new_table);
	MAX_LEN = NEW_MAX_LEN;
	delete[] new_table;
}

template <typename key_type, typename value_type>
size_t IHashMap<key_type, value_type>::hash(key_type e){
	std::tr1::hash<key_type> hashfunc;
	return hashfunc(e);
}

template <typename key_type, typename value_type>
bool IHashMap<key_type, value_type>::exist(key_type k){
	size_t hash_code = hash(k) % MAX_LEN;
	IKVNode<key_type, value_type>* cur_node = elements[hash_code];
	
	if(!cur_node)
		return false;
	
	do{
		if(cur_node->key == k)
			return true;
		}while((cur_node = cur_node->next) != NULL);
	
	return false;
}

template <typename key_type, typename value_type>
void IHashMap<key_type, value_type>::put(key_type k, value_type v){
	if(size > MAX_LEN/2)
		resize(MAX_LEN*2);

	size_t hash_code = hash(k) % MAX_LEN;
	
	IKVNode<key_type, value_type>* cur_node = elements[hash_code];
	if(!cur_node){
		elements[hash_code] = new IKVNode<key_type, value_type>(k,v);
		size++;
		return;
	}	
		
	while(cur_node->key != k && cur_node->next){
		cur_node = cur_node->next;
	}
	
	if(cur_node->key != k){
		cur_node->next = new IKVNode<key_type, value_type>(k,v);
		size++;
	}else{
		cur_node->value = v;
	}
}

template <typename key_type, typename value_type> 
std::ostream& operator<< (std::ostream& output, const IHashMap<key_type, value_type>& hash_map){ 
	// brute force scan; should be replaced by dedicated iterator in the future 
	for(int i = 0; i < hash_map.MAX_LEN; i++){
		if(hash_map.elements[i])
			output<<*(hash_map.elements[i])<<" ";
	}
	return output;
}