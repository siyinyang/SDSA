#include <iostream>
#include "util.h"

using namespace std;

int partition(int h[], int start, int end){
	int p = start;
	int pivot = h[end];
	for(int i = start; i < end; i++){
		if(h[i] <= pivot){
			swap(h[i], h[p]);
			p++;
		}
	}
	swap(h[p],h[end]);
	return p;
}

int quick_select(int h[], int start, int end, int k){
	int pivot_ind = partition(h, start, end);
	int n = pivot_ind - start + 1;
	if(n == k){
		return pivot_ind;
	}
	else if(n < k){
		return quick_select(h, pivot_ind+1, end, k-n);
	}
	else{
		return quick_select(h, start, pivot_ind-1, k);
	}
}

int quick_select(int h[], int len, int k){
	int pivot_ind = quick_select(h, 0, len-1, k);
	print_arr(h, pivot_ind+1);
	return 1;
}

int main(){
	int h[] = {3, 5, 4, 10, 30, 100, 8, 25, 1};
	int len = 9;
	quick_select(h, len, 1);
	print_arr(h, len);
	return 0;
}

