#pragma once


template<typename value_type>
class ILinkedList
{
public:
	struct LNode
    {
        value_type value;
        LNode* prev;				
        LNode* next;
        LNode(value_type v, LNode* p, LNode* n) : value(v), prev(p), next(n) {};
    };
    LNode* head;
    LNode* tail;

	ILinkedList(): head( NULL ), tail ( NULL ),size(0) {}

	template <int N>
	ILinkedList(value_type (&arr)[N]):head( NULL ),tail ( NULL ),size(N)
	{
		for( int i(0); i != N; ++i)
			push_back(arr[i]);
	}

	~ILinkedList(void){}

	int size;
	void reverse();
	void remove(value_type value);
	void push_back(value_type value);
	int find(value_type value);
	value_type get(int i);
	value_type getLast(int i);
	void sort();
	bool validata();

	value_type* toArray();

	friend ostream& operator<< <>(ostream& output, const ILinkedList<value_type>& list);

};

template <typename value_type>
bool ILinkedList<value_type>::validata(){
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
}

template <typename value_type>
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
}

//template <typename value_type>
//void ILinkedList<value_type>::reverse(){
//	LNode* cur_node = NULL;
//	LNode* temp = NULL;
//	while(head){
//		temp = head->next; 
//		head->next = cur_node;
//		cur_node = head;
//		head = temp;
//	}
//
//	head = cur_node;
//}

template <typename value_type>
void ILinkedList<value_type>::remove(value_type value){
	LNode* cur_node = this->head;

	while(cur_node != NULL)
	{
		if(cur_node->value == value)
		{
			if (cur_node->prev != NULL)
				cur_node->prev->next = cur_node->next;
			else
				this->head = cur_node->next;
			
			if (cur_node->next != NULL)
				cur_node->next->prev = cur_node->prev;
			else
				this->tail = cur_node->prev;

			delete cur_node;
			size--;
			return;
		}
		else
			cur_node = cur_node->next;
	}
}

template <typename value_type>
void ILinkedList<value_type>::push_back(value_type data)
{
    tail = new LNode(data, tail, NULL);
    if( tail->prev )
        tail->prev->next = tail;
	else
        head = tail;

	size++;
}


template <typename value_type>
int ILinkedList<value_type>::find(value_type data){
	LNode* cur_node = this->head;
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
	LNode* cur_node = this->head;
	int ind = 0;
	while (ind < i){
		ind ++;
		cur_node = cur_node->next; 
	}

	return cur_node->value;
}

template <typename value_type>
value_type ILinkedList<value_type>::getLast(int i){
	LNode* p1 = this->head;
	LNode* p2 = this->head;
	int ind = 0;
	while(ind < i-1){
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
value_type* ILinkedList<value_type>::toArray(){
	value_type* cur = this->head;
	value_type* arr = new value_type[size];
	count = 0;
	while(cur != NULL){
		arr[count] = cur->value;
		count++;
		cur = cur->next;
	}

	return arr;
}

template <typename value_type>
ostream& operator<<<>(ostream& output, const ILinkedList<value_type>& list){
	ILinkedList<value_type>::LNode* p = list.head;

	while(p){
		output<<p->value<<" ";
		p = p->next;
	}
	output<<endl;
	return output;
}