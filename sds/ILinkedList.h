#pragma once
#include <iostream>

template<typename value_type>
class ILinkedList;

template<typename value_type>
std::ostream& operator<<(std::ostream& output, const ILinkedList<value_type>& list);

template<typename value_type>
class ILinkedList
{
public:
	struct LNode
    {
        value_type value;
        LNode* next;
        LNode(value_type v, LNode* p, LNode* n) : value(v), next(n) {};
    };
  
	LNode* head;
	LNode* tail;
	ILinkedList(): head( NULL ), tail( NULL ), size(0) {}

	template <int N>
	ILinkedList(value_type (&arr)[N]):head( NULL ), tail( NULL ), size(0)
	{
		for( int i(0); i != N; ++i)
			push_back(arr[i]);
	}

	~ILinkedList(void){}

	size_t size;
	void reverse();
	void remove(value_type value);
	void push_back(value_type value);
	int find(value_type value);
	value_type get(int i);
	value_type get_last(int i);
	//void sort();
	//bool validate();
	value_type* to_array();

	friend std::ostream& operator<< <value_type>(std::ostream& output, const ILinkedList<value_type>& list);
};

/**template <typename value_type>
bool ILinkedList<value_type>::validate(){
	LNode* cur = head;
	bool isCorrect = true;
	while(cur != tail){
		if(cur->next-> prev != cur){
			isCorrect = false;
			break;
		}
		cur = cur->next;
	}

	return isCorrect;
}*/

/**template <typename value_type>
void ILinkedList<value_type>::sort(){
	// insert sort
	LNode* cur = head;
	LNode* itr = head;
	value_type temp = NULL;
	while(cur != tail)
	{
		cur = cur->next;
		itr = cur;
		while((itr->prev != NULL) && (itr->value < itr->prev->value)){
			temp = itr->value;
			itr->value = itr->prev->value;
			itr->prev->value = temp;

			itr = itr->prev;
		}
	}
}*/

template <typename value_type>
void ILinkedList<value_type>::reverse(){
	LNode* cur_node = NULL;
	LNode* temp = NULL;
	tail = head;
	
	while(head){
		temp = head->next; 
		head->next = cur_node;
		cur_node = head;
		head = temp;
	}

	head = cur_node;
}

template <typename value_type>
void ILinkedList<value_type>::remove(value_type value){
	LNode* cur_node = head;
  LNode* pre_node = NULL;
	
	while(cur_node != NULL)
	{
		if(cur_node->value == value)
		{
			if (pre_node != NULL)
				pre_node->next = cur_node->next;
			else//head node
				head = cur_node->next;
			
			if (cur_node->next == NULL)//tail node
				tail = pre_node;

			delete cur_node;
			size--;
			return;
		}
		
		pre_node = cur_node;
		cur_node = cur_node->next;
	}
}

template <typename value_type>
void ILinkedList<value_type>::push_back(value_type data)
{
	LNode* orig_tail = tail;
  	tail = new LNode(data, tail, NULL);
  	if( orig_tail)
  		orig_tail->next = tail;
	else
    	head = tail;

	size++;
}

template <typename value_type>
int ILinkedList<value_type>::find(value_type data){
	LNode* cur_node = head;
	int ind = -1;
	while (cur_node != NULL ){
		ind ++;
		if (cur_node->value == data)
			return ind;
		else
			cur_node = cur_node->next; 
	}

	return -1;
}

template <typename value_type>
value_type ILinkedList<value_type>::get(int i)
{
	if(i<0)
		return NULL;
	
	LNode* cur_node = head;
	int ind = 0;
	while (ind < i){
		ind++;
		cur_node = cur_node->next; 
	}

	return cur_node->value;
}

template <typename value_type>
value_type ILinkedList<value_type>::get_last(int i){
	if(i<0)
		return NULL;
	
	LNode* p1 = head;
	LNode* p2 = head;
	int ind = 0;
	while(ind < i){
		ind++;
		p2 = p2->next;
	}
		
	while(p2->next){
		p2 = p2->next;
		p1 = p1->next;
	}

	return p1->value;
}

template <typename value_type>
value_type* ILinkedList<value_type>::to_array(){
	typename ILinkedList<value_type>::LNode* cur = head;
	value_type* arr = new value_type[size];
	int count = 0;
	while(cur != NULL){
		arr[count] = cur->value;
		count++;
		cur = cur->next;
	}

	return arr;
}

template <typename value_type>
std::ostream& operator<<(std::ostream& output, const ILinkedList<value_type>& list){
	typename ILinkedList<value_type>::LNode* p = list.head;

	while(p){
		output<<p->value<<" ";
		p = p->next;
	}
	output<<std::endl;
	return output;
}
