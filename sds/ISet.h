#pragma once
#include "IBST.h"





template <typename T>
class ISet
{

private:
	IBST<T, T> elements;
public:
	ISet(void){}
	ISet(T* arr, int size);
	~ISet(void);

	void add(T e);
	void remove(T e);
	int size(){return elements.size();}

	ostream& output_set(ostream& output, ISet<T>& set){
		output<<set.elements;
		return output;
	}

	friend ostream& operator<< <>(ostream& output,  ISet<T>& set); 
};


template <typename T>
ISet<T>::ISet(T* arr, int size)
{
	for(int i = 0; i != size; ++i)
		insert(arr[i]);
}



template <typename T>
ISet<T>::~ISet(void)
{
}

template <typename T>
void ISet<T>::add(T e){
	IBST<T, T>::Node*  node = new IBST<T, T>::Node(e, e);
	elements.insert(*node);
}

template <typename T>
void ISet<T>::remove(T e){
	elements.remove(e);
}

template <typename T>
ostream& operator<< <>(ostream& output,  ISet<T>& set){
	output<<set.output_set(output, set);

	return output;
}


// bit vector to implement the integer set
template <>
class ISet<int>{
private:
	enum{BITSPERWORD = 32, SHIFT = 5, MASK = 0x1F};
	int n; 
	int hi; 
	int *x;
	void set(int i){ x[i>>SHIFT] |= (1 << (i & MASK));}
	void clr(int i){ x[i>>SHIFT] &= ~(1<< (i & MASK));}
	int test(int i){ return x[i>>SHIFT] & (1<<(i & MASK));}
public:
	ISet(void):n(0),hi(10000){
		x = new int[1 + hi/BITSPERWORD]; 
		for(int i = 0; i < hi; i++)
			clr(i);
	}
	ISet(int* arr, int size){
		hi = max<int>(arr[0], arr[size+1]);
		x = new int[1 + hi/BITSPERWORD];
		for(int i = 0; i < hi; i++)
			clr(i);
		for(int i = 0; i != size; ++i)
			add(arr[i]);
	}

	~ISet(void){};

	void add(int e){
		if(test(e))
		return;

		set(e);
		n++;
	}

	void remove(int e){
		if(test(e)){
			clr(e);
			n--;
		}
	}

	int size(){return n;}

	ostream& output_set(ostream& output,  ISet<int>& set){
		for(int j=0; j < hi; j++)
			if(test(j))
				output<<j<<" ";

		return output;
	}

	friend ostream& operator<< <int>(ostream& output,  ISet<int>& set); 
};