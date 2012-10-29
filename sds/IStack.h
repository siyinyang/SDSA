#pragma once
#include <iostream>
 
template <typename value_type>
class IStack;

template <typename value_type>
std::ostream& operator<<(std::ostream& output, const IStack<value_type>& stack);

template <typename value_type>
class IStack
{
private:
	int len;
	size_t capacity;
	value_type* data;
	void resize(size_t new_capacity);
public:
	IStack(void):len(-1),capacity(100),data(NULL){}

	template <int N>
	IStack(value_type (&arr)[N]):len(-1),capacity(2*N),data(NULL)
	{
		for( int i =0; i != N; ++i)
			push(arr[i]);
	}

	~IStack(void){}

	void push(value_type value);
	value_type* pop();
	value_type* peek();
	bool empty();
	int find(value_type value);

	friend std::ostream& operator<< <value_type>(std::ostream& output, const IStack<value_type>& stack);
};

template <typename value_type>
void IStack<value_type>::resize(size_t new_capacity){
	capacity = new_capacity;
	value_type* temp = new value_type[capacity];
	for(int i = 0; i < len; i++)
		temp[i] = data[i];
	
	swap(temp, data);
	delete[] temp;
}

template <typename value_type>
int IStack<value_type>::find(value_type value)
{
	for(int i = 0; i < len; i++)
		if(data[i] == value)
			return i;

	return -1;
}

template <typename value_type>
void IStack<value_type>::push(value_type value)
{
	if (data == NULL)
		data = new value_type[capacity];

	if (len == capacity)
		resize(2 * capacity);
	
	data[++len] = value;
}

template <typename value_type>
value_type* IStack<value_type>::pop(void)
{
	if(len>=0){
		len--;
		return &data[len+1];
	}
	return NULL;
}

template <typename value_type>
value_type* IStack<value_type>::peek(void)
{
	if(len>=0){
		return &data[len];
	}
	return NULL;
}

template <typename value_type>
bool IStack<value_type>::empty()
{
	return len < 0;
}

template <typename value_type>
std::ostream& operator<< (std::ostream& output, const IStack<value_type>& stack){
	for (int i = 0; i <= stack.len; i++)
		output<<stack.data[i]<<' ';

	return output;
}
