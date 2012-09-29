#pragma once
using namespace std;

template <typename T>
class IHeap
{
public:
	/*struct HeapNode{
		T value;
        HeapNode* left;				
        HeapNode* right;
		HeapNode(T v, HeapNode* l, HeapNode* r) : value(v), left(l), right(r) {};
	};*/

	IHeap(void);
	IHeap(T* arr, int len);
	~IHeap(void){}

	void insert(T data);
	T get_top();
	void remove_top();
	void siftdown(int i);
	void siftup(int i);
	bool is_empty();

	friend ostream& operator<< <>(ostream& output,  IHeap<T>& heap);
private:
	int size;
	int MAX_LEN;
	T* top;

	void resize(int new_max_len);
};


template <typename T>
IHeap<T>::IHeap():MAX_LEN(5),size(0){
	top = new T[MAX_LEN];
}

template <typename T>
IHeap<T>::IHeap(T* arr, int len){
	MAX_LEN = 2*len;
	top = new T[MAX_LEN];
	for(int i = 0; i != len; ++i){
		insert(arr[i]);
	}
	size = len;
}

template <typename T>
T IHeap<T>::get_top(){
	if(size > 0)
		return top[0];
	else
		return NULL;
}

template <typename T>
void IHeap<T>::remove_top(){
	if(size > 0){
		swap(top[0], top[size-1]);
		size--;
		siftdown(0);
	}
}

template <typename T>
bool IHeap<T>::is_empty(){
	return (size == 0);	
}

template <typename T>
void IHeap<T>::resize(int NEW_MAX_LEN){
	T* new_top = new T[NEW_MAX_LEN];

	for(int i = 0; i != size; ++i){
		new_top[i] = top[i];
	}

	swap(new_top, top);
	delete[] new_top;
}

template <typename T>
void IHeap<T>::insert(T v){
	if(size  == MAX_LEN){
		MAX_LEN *= 2;
		resize(MAX_LEN);
	}

	top[size++] = v;
	siftup(size-1);
}	

template <typename T>
void IHeap<T>::siftdown(int i){
	int swapInd = 0;
	T cur = top[i];

	if(top[i] == 281){
		int fuck = 0;
	}

	while(2*i + 1< size){
		int leftChild = 2*i + 1;
		int rightChild = 2*(i+1);

		if(top[leftChild] > cur)
			swapInd = leftChild;
		
		if(rightChild < size && cur < top[rightChild] && top[leftChild] < top[rightChild])
			swapInd = rightChild;
		
		if(i != swapInd){
			top[i] = top[swapInd];
			i = swapInd;
		}
		else
			break;
	}

	top[i] = cur;
}

template <typename T>
void IHeap<T>::siftup(int i){
	int j = (i-1)/2;
	T cur = top[i];

	while(i > 0 && cur > top[j]){
		top[i] = top[j];

		i = j;
		j = (i-1)/2;
	}

	top[i] = cur;
}

template <typename T>
ostream& operator<< (ostream& output,  IHeap<T>& heap){
	for(int i = 0; i != heap.size; ++i){
		output<<heap.top[i]<<" ";
	}
	output<<endl;

	return output;
}