#pragma once
using namespace std;

template <typename T>
class Sort
{
public:
	Sort(void){}
	~Sort(void){}
	static void quicksort(T arr[], int left, int right, int* sortInd);
	static int  partition(T arr[], int left, int right, int* sortInd);

	static void mergesort(T arr[], int left, int right);
	static void merge(T arr[], int left, int mid, int right);


	static void heapsort(T arr[], int len);
	static void siftdown(T arr[], int start, int end);
	static void heapify(T arr[], int len);

	static int* insertsort(T arr[], int len);
};

template <typename T>
void  Sort<T>::heapsort(T arr[], int len){
	// heapify the unsorted array
	heapify(arr, len);

	//
	int end = len - 1;
	while(end > 0){
		swap(arr[end], arr[0]);
		siftdown(arr, 0, end-1);
		end--;
	}
}

template <typename T>
void  Sort<T>::heapify(T arr[], int len){
	//start is assigned the index in a of the last parent node
    int start = len / 2 - 1;
     
     while (start >= 0 ){
        //sift down the node at index start to the proper place such that all nodes below the start index are in heap order)
        siftdown(arr, start, len-1);
		start = start - 1;
	 }
     //after sifting down the root all nodes/elements are in heap order)
}

template <typename T>
void Sort<T>::siftdown(T A[], int start, int end){
	int root = start;

	// while have at least on child
	while(2*root + 1 <= end){
		int leftChild = 2 * root + 1;
		int swapInd = root;
		
		//if less than children, swap
		if (A[swapInd] < A[leftChild]){
			swapInd = leftChild;
		}
		if(leftChild + 1 <= end && A[swapInd] < A[leftChild+1]){
			swapInd = leftChild + 1;
		}

		if(root != swapInd){
			swap(A[swapInd], A[root]);
			root = swapInd;
		}
		else
			return;
	}
}
	
template <typename T> 
int* Sort<T>::insertsort(T arr[], int len){
	if(len < 0) return NULL;
	int* ind = new int[len];
	for(int i = 0; i < len; i++)
		ind[i] = i;

	for(int i = 1; i < len; i++){
		for(int j = i; j > 0; j--){
			if(arr[j] < arr[j-1]){
				swap(arr[j], arr[j-1]);
				swap(ind[j], ind[j-1]);
			}
		}
	}

	return ind;
}

template <typename T> 
void Sort<T>::quicksort(T arr[], int left, int right, int* sortInd){
	int pivot_ind;
	int len = right - left + 1;

	if (left < right){
		pivot_ind = partition(arr, left, right, sortInd);
		quicksort(arr, left, pivot_ind-1, sortInd);
		quicksort(arr, pivot_ind+1, right, sortInd);
	}
}

template <typename T>
int Sort<T>::partition(T arr[], int left, int right, int* sortInd){
	T pivot = arr[right];
	int stored_ind = left;
	for (int i = left; i < right; i++){
		if (arr[i] < pivot){
			swap(arr[stored_ind], arr[i]);
			swap(sortInd[stored_ind], sortInd[i]);

			stored_ind++;
		}
	}
	swap(arr[stored_ind], arr[right]);
	swap(sortInd[stored_ind], sortInd[right]);

	return stored_ind;
}

template <typename T>
void Sort<T>::mergesort(T arr[], int left, int right){
	if(left >= right)
		return;

	int mid = (left + right) / 2;
	mergesort(arr, left, mid);
	mergesort(arr, mid+1, right);
	merge(arr, left, mid, right);
}

template <typename T>
void Sort<T>::merge(T arr[], int left, int mid, int right){
	int ind1 = left;
	int ind2 = mid+1;
	int i = 0;
	int N = right - left + 1;
	T* result = new T[N];
	
	while (ind1 <= mid && ind2 <= right){
		if (arr[ind1] < arr[ind2]){
			result[i] = arr[ind1];
			i++; ind1++;
		}
		else{
			result[i] = arr[ind2];
			i++; ind2++;
		}
	}

	if (ind1 > mid)
		for (int j = ind2; j<= right; j++, i++)
			result[i] = arr[j];
	else if (ind2 > right)
		for (int j = ind1; j<= mid; j++, i++)
			result[i] = arr[j];
	
	for (int j = 0; j< N; j++)
		arr[j+left] = result[j];
}