#pragma once

using namespace std;

template <typename T>
class IStack
{
private:
	int len;
	int capacity;
	T* data;

public:
	IStack(void):len(-1),capacity(100),data(NULL){}

	template <int N>
	IStack(T (&arr)[N]):len(-1),capacity(2*N),data(NULL)
	{
		for( int i =0; i != N; ++i)
			push(arr[i]);
	}

	~IStack(void){}

	void push(T value);
	T* pop();
	T* peek();
	bool empty();
	int find(T value);

	friend ostream& operator<<<>(ostream& output, const IStack<T>& stack);
};

template <typename T>
int IStack<T>::find(T value)
{
	for(int i = 0; i < len; i++)
		if(data[i] == value)
			return i;

	return -1;
}

template <typename T>
void IStack<T>::push(T value)
{
	if (this->data == NULL)
		data = new T[this->capacity];

	if (this->len == capacity){
		capacity = 2 * capacity;
		T* temp = new T[capacity];
		for(int i = 0; i < len; i++)
			temp[i] = data[i];
		swap(temp, data);
		
		delete[] temp;
	}
	
	data[++this->len] = value;
}

template <typename T>
T* IStack<T>::pop(void)
{
	if(len>=0){
		len--;
		return &data[len+1];
	}
	return NULL;
}

template <typename T>
T* IStack<T>::peek(void)
{
	if(len>=0){
		return &data[len];
	}
	return NULL;
}

template <typename T>
bool IStack<T>::empty()
{
	return len < 0;
}

template <typename T>
ostream& operator<<<>(ostream& output, const IStack<T>& stack){
	for (int i = 0; i <= stack.len; i++)
		output<<stack.data[i]<<' ';

	return output;
}
