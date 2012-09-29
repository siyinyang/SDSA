#pragma once

using namespace std;

template <typename T>
class IQueue
{
private:
	int first;
	int last;
	int capacity;
	int len;
	T* data;
public:
	IQueue(void):len(0),first(0),last(-1),capacity(100),data(NULL){}

	IQueue(T* arr, int len):len(len), first(0),last(-1),capacity(2*len),data(NULL){
		for( int i =0; i != len; ++i)
			enqueue(arr[i]);
	}

	template <int N>
	IQueue(T (&arr)[N]):len(0),first(0),last(-1),capacity(2*N),data(NULL)
	{
		for( int i =0; i != N; ++i)
			enqueue(arr[i]);
	}
	
	
	
	~IQueue(void){}

	void enqueue(T elem);
	T* dequeue();
	T* peek();
	bool empty();
	friend ostream& operator<<<>(ostream& output, const IQueue<T>& IQueue);
};




template <typename T>
void IQueue<T>::enqueue(T value)
{
	if (this->data == NULL)
		data = new T[capacity];

	if (len == capacity){
		T* temp = new T[2*capacity];

		int flag = 0;
		if(first > last)
			flag = 1;

		for(int i = first,j=0; i <= capacity*flag+last; i++,j++)
			temp[j] = data[i%capacity];

		swap(temp, data);
		capacity*=2;
		first = 0;
		last = first + len -1;
		delete[] temp;
	}
	
	last = (++last)%capacity;
	data[last] = value;
	len++;
}

template <typename T>
T* IQueue<T>::dequeue(void)
{
	if(len>0){
		len--;

		int ind = first;
		first = (++first)%capacity;
		return &data[ind];
	}
	
	return NULL;
}

template <typename T>
T* IQueue<T>::peek(void)
{
	if(len>0){
		return &data[first];
	}
	
	return NULL;
}

template <typename T>
bool IQueue<T>::empty()
{
	return len == 0;
}

template <typename T>
ostream& operator<<<>(ostream& output, const IQueue<T>& queue){
	if(queue.len>0){
		int flag = 0;
		if(queue.first > queue.last)
			flag = 1;

		for(int i = queue.first; i <= queue.capacity*flag+queue.last; i++)
			output<<queue.data[i%queue.capacity]<<" ";
	}
	return output;
}

