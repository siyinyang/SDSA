#pragma once
#include <iostream>

template <typename data_type>
class IQueue;

/**This declaration is to 'trick' the complier to treat the friend function as a template*/
template <typename data_type>
std::ostream& operator<< (std::ostream& output, const IQueue<data_type>& IQueue);

template <typename data_type>
class IQueue
{
private:
	int first;
	int last;
	size_t capacity;
	size_t len;
	data_type* data;
public:
	IQueue(void):len(0),first(0),last(-1),capacity(100),data(NULL){}

	IQueue(data_type* arr, size_t len):len(len), first(0),last(-1),capacity(2*len),data(NULL){
		for( size_t i =0; i != len; ++i)
			enqueue(arr[i]);
	}

	template <size_t N>
	IQueue(data_type (&arr)[N]):len(0),first(0),last(-1),capacity(2*N),data(NULL)
	{
		for( size_t i =0; i != N; ++i)
			enqueue(arr[i]);
	}
	
	~IQueue(void){}

	void enqueue(data_type elem);
	data_type* dequeue();
	data_type* peek();
	bool empty();
	friend std::ostream& operator<< <>(std::ostream& output, const IQueue<data_type>& IQueue);
};


template <typename data_type>
void IQueue<data_type>::enqueue(data_type value)
{
	if (this->data == NULL)
		data = new data_type[capacity];

	if (len == capacity){
		data_type* temp = new data_type[2*capacity];

		size_t flag = 0;
		if(first > last)
			flag = 1;

		for(size_t i = first,j=0; i <= capacity*flag+last; i++,j++)
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

template <typename data_type>
data_type* IQueue<data_type>::dequeue(void)
{
	if(len>0){
		len--;

		size_t ind = first;
		first = (++first)%capacity;
		return &data[ind];
	}
	
	return NULL;
}

template <typename data_type>
data_type* IQueue<data_type>::peek(void)
{
	if(len>0){
		return &data[first];
	}
	
	return NULL;
}

template <typename data_type>
bool IQueue<data_type>::empty()
{
	return len == 0;
}

template <typename data_type>
std::ostream& operator<< (std::ostream& output, const IQueue<data_type>& queue){
	if(queue.len>0){
		int flag = 0;
		if(queue.first > queue.last)
			flag = 1;

		for(size_t i = queue.first; i <= queue.capacity*flag+queue.last; i++)
			output<<queue.data[i%queue.capacity]<<" ";
	}
	return output;
}
