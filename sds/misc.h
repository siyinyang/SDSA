#pragma once
#include "Sort.h"
#include "IString.h"


//laserfitch interview question
template <typename T>
int min_number_of_stamps (	T* arr, /* input array of sorted stamp values */
							size_t arr_size, /* number of elements in array */
							T request, /* desired value to of stamps */
							T* reqArr);

template <typename T>
T* reverseArray(T*orig, size_t b);

template <typename T>
int binarySearch(T elem, T* arr, size_t arr_size);

template <typename T>
T sumArray(T* arr, size_t arr_size);

// Career cup Applied Mathematics Question One
int fibonacci(int n);
int fibonacci2(int n);

// Career cup Applied Mathematics Question Two
int count2(int n);

// Career cup Applied Mathematics Question Three
int isLineIntersect(double line1[], double line2[], int nDim); 

//Career cup Applied Mathematics  Question Four 
//Write a function that adds two numbers. You should not use + 
//or any arithmetic operators.
int addTwoNumWithoutArithmeticOp(int a, int b);

//Career cup Applied Mathematics Question Nine
//A circus is designing an act consisting of a tower of people 
//standing atop one another¡®s shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter 
//than the person below her. Given the heights and weights of 
//each person in the circus, write a method to compute the largest possible number of people in such a tower?
int circus(double heights[], double weights[], int len, double* cHeights, double* cWeights);


//Arrays Question Two
//Design an algorithm and write code to remove the duplicate 
//characters in a string without using any additional buffer.
void removeDuplicate(char* arr);

//Arrays Question Three       
//You are given an array of integers (both positive and negative). 
//Find the continuous sequence with the largest sum.  Return the sum
double findMaxSumSeq(double* arr, int len);

//Question Four        SOLUTION
//Design an algorithm to find all pairs of integers within an array 
//which sum to a specified value.
int sumPair(int* arr, int len, int req, int* a, int* b);
int partition(int* arr, int start, int end);
void quicksort(int* arr, int start, int end);
int sumTriple(int * arr, int len, int req, int* a, int* b, int* c);
int sumFour(int * arr, int len, int req, int* a, int* b, int* c, int* d);

// google interview
// a man walk a stair of 100 floors, step can be 1, 2, 5, which is the possibilities
int stepFloor(int nFloor);

//ebay interview
//NumNode* point24(NumNode* node1, NumNode* node2, char op);
struct Op_Data{
	int data;
	char op;
	int flag;
	friend ostream& operator<<(ostream& output, const Op_Data& v);
};

//Design an algorithm to find the kth number divisible by only 3 
//or 5 or 7.  That is, the only factors of these numbers should be 
//3,5 and 7.  
int kth_divisible_by3(int k);

// 24 point game
const double esp = 1e-20;
char* int2str(int i);
void points24(int* a, int len);
void points24(int* a, int len, IString* expr);
bool isDigit(char c);
int op_s_priority(char op);
int op_c_priority(char op);
double expValue(char* exp);
double calc(double v1, double v2, int op);

// google code jam
//Minimum Scalar Product

template <typename T>
T** computeShortestPathArrays(T** c,int m, int n);

template <typename T>
void print2DArrays(T** arr, int m, int n);

template <typename T>
int min_number_of_stamps (	T* arr, /* input array of sorted stamp values */
							size_t arr_size, /* number of elements in array */
							T request, /* desired value to of stamps */
							T* reqArr)
{
	
	Sort<T> sort;
	sort.quicksort(arr, 0, arr_size-1);
	size_t min_num_of_stamps = request / arr[arr_size-1]; // possible minimum number of stamps
	size_t max_num_of_stamps = request / arr[0]; // possible minimum number of stamps

	int ind = binarySearch(request, arr, arr_size);

	if(ind != -1){
		reqArr[ind]++;
		return 1;
	}
	else{
		int cndPtr = 0;
		int* S = new int[request+1];

		for(int i = 1; i <= request; i++){
			if (i== arr[cndPtr]){
				S[i] = 1;
				cndPtr++;
			}
			else{
				int minVal = S[i-arr[0]];
				for(int j = 1; j < cndPtr; j++){
					if(S[i-arr[j]] < minVal){
						minVal = S[i-arr[j]];
					}
				}
				S[i] = 1 + minVal;
			}
			
		}

		return S[request];
	}
}


//This function is used to reverse an array
//return sorted array
template <typename T>
T* reverseArray(T*orig, size_t b)
{
    size_t a=0;
    
    for(a;a<--b;a++) //increment a and decrement b until they meet eachother
    {
        swap(orig[a], orig[b]);
    }
   
    return orig;    //return the new (reversed) string (a pointer to it)
}

//This function is used to search an already sorted array in acending order
//If element is found, return index of element, else return -1
template <typename T>
int binarySearch(T elem, T* arr, size_t arr_size){
	int mid = 0;
	int left = 0; int right = arr_size-1;
	
	while(left <= right){
		mid = left + (right-left)/2;
		if(arr[mid] == elem){
			return mid;
		}
		else if(arr[mid] < elem){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}

	return -1;
}

template <typename T>
T sumArray(T* arr, size_t arr_size){
	T sum = 0;       // Start the total sum at 0.
    for (size_t i=0; i < arr_size; i++) {
        sum = sum + arr[i];  // Add the next element to the total
    }

	return sum;
}


template <typename T>
T** computeShortestPathArrays(T** c,int m, int n){
	//initialize auxilliary matrix
	T** q = new T*[m];
	//shortest path matrix
	T** p = new T*[m];

	for(int y = 0; y < m; y++){
        q[y] = new T[n+2];
		p[y] = new T[n];
	}

	for(int x = 0; x<n; x++){
        q[0][x+1] = c[0][x];
		p[0][x] = 0;
	}
    for(int y = 0; y<n; y++){
        q[y][0] = numeric_limits<T>::max();
        q[y][n+1] = numeric_limits<T>::max();
	}

	//print2DArrays(q, m, n+2);

    for (int y = 1; y<n; y++)
        for (int x = 1; x<=n; x++){
            T v = min(q[y-1][x-1], min(q[y-1][x], q[y-1][x+1]));
            q[y][x] = v + c[y][x-1];
            if (v == q[y-1][x-1])
                p[y][x-1] = -1;
            else if (v == q[y-1][x])
                p[y][x-1] =  0;
            else
                p[y][x-1] =  1;
		}

	//print2DArrays(q, m, n+2);
	for(int y = 0; y < m; y++){
        delete[] q[y];
	}
	delete[] q;
	return p;
}

template <typename T>
void print2DArrays(T** arr, int m, int n){
	for (int y = 0; y<m; y++){
		for (int x = 0; x<n; x++){
			cout<<arr[y][x]<<'\t';
		}
		cout<<endl;
	}
}

void combine(char* arr, int len, int cLen);
void combine(char* arr, char* cmb, int* used, int len, int cLen, int startInd, int curInd, int& count);

void permute(char* arr,  char* pmt, int* used, int len, int curInd, int& count);


int longest_common_substr(char* s1, int len1, char* s2, int len2);

void print_parentheses(int N);
void print_parentheses(int ind, int N, int n_left, int n_right, char* arr);

void print_subset(char* set);
void print_subset(char* set, int len, bool* mask, int ind);

void print_subset(char* set, int len);

int knapsack0_1(int* weights, int* value, int len, int maxW);

double ISqrt(double a);

