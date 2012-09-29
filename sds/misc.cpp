#include "StdAfx.h"


#include "misc.h"
#include "IString.h"
#include "IStack.h"
#include "IQueue.h"


using namespace std;

int fibonacci(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	else return fibonacci(n-1)+fibonacci(n-2);
}

int fibonacci2(int n){
     int a = 1; 
     int b = 1;
     int c = 0;
     for(int i = 1; i < n; i++){
         c = a+b; 
         a = b;
         b = c;
     }   
    
    return a;
}

int count2(int n){
	int count = 0;
	for (int cn = 0; cn <= n; cn++){
		int remain = cn;
		while(remain > 1){
			if (remain%10 == 2){
				count++;
				break;
			}
			remain = remain / 10;
		}
	}

	return count;
}

bool isLineIntersect(double line1[], double line2[]){
	//expressed in a1*x1 + a2*x2 + an = 0,  the length of line1 and line2 should be nDim +£±
	double a1 = line1[0]; double b1 = line1[1]; double c1 = line1[2];
	double a2 = line1[0]; double b2 = line1[1]; double c2 = line1[2];

	//if paralell 
	if(a1 * b2 == a2 * b1){
		// if same line
		if(c1 == c2)
			return true;
		else
			return false;
	}
	else
		return true;

}

int addTwoNumWithoutArithmeticOp(int a, int b){
	int temp_carry = 0;
	while(a != 0){
		temp_carry = a;
		a = (a&b)<<1;
		b = temp_carry^b;
	}

	return b;
}

int circus(double heights[], double weights[], int len, double* cHeights, double* cWeights){
	// sort heighs ascendingly
	int* sortInd = new int[len];
	double* h = new double[len];
	for(int k = 0; k < len; k++){
		sortInd[k] = k;
		h[k] = heights[k];
	}

	Sort<double> sort;
	sort.quicksort(h, 0, len-1, sortInd);

	for(int k = 0; k < len; k++){
		cout<< heights[k]<<" ";
		cout<< sortInd[k]<<" ";
	}

	double* w = new double[len];
	for(int k = 0; k < len; k++){
		w[k] = weights[sortInd[k]];
		cout<<w[k]<<" ";
	}


	//denote max ascending sequence in weights as q, q[i] denotes the max sequence until i's element in weights
	int* q = new int[len]; 
	for(int k = 0; k < len; k++)
		q[k] = 0;

	int* preInd = new int[len];
	for(int k = 0; k < len; k++)
		preInd[k] = -1;

	for(int i = 0; i < len; i++){
		int max = 0;
		for(int j = 0; j < i; j++){
			if (w[j] < w[i] && q[j] > max){
				max = q[j];	
				preInd[i] = j;
			}
		}
		q[i] = max + 1;
	}

	int max = 0;
	int maxInd = 0;
	for(int k = 0; k < len; k++)
		if (q[k] > max){
			max = q[k];
			maxInd = k;
		}

	for(int k = max-1; k >= 0; k--){
		cWeights[k] = w[maxInd];
		cHeights[k] = h[maxInd];


		maxInd = preInd[maxInd];
	}
	
	return max;
}

void removeDuplicate(char* str){
	int len = strlen(str);
	Sort<char> sort;
	sort.heapsort(str, len);

	char* ptr1 = str;
	char* ptr2 = str+1; 
	while(*ptr2 != '\0' ){
		if(*ptr1 != *ptr2){
			ptr1++;
			*ptr1 = *ptr2;
		}
		ptr2++;
	}

	ptr1++;
	*ptr1 = '\0';
}

double findMaxSumSeq(double* arr, int len){
	
	double maxSum = -numeric_limits<double>::min();
	int maxStartIndex = 0; 
	int maxEndIndex = 0;
    double currentMaxSum = 0;
    int currentStartIndex = 0;
    for (int currentEndIndex = 0;  currentEndIndex < len; currentEndIndex++){
        currentMaxSum = currentMaxSum + arr[currentEndIndex];
        if (currentMaxSum > maxSum){
            maxSum = currentMaxSum;
			maxStartIndex = currentStartIndex;
			maxEndIndex = currentEndIndex;
		}

        if ( currentMaxSum < 0) {
            currentMaxSum = 0;
			currentStartIndex = currentEndIndex + 1;
		}
	}

	return maxSum;
}


int sumPair(int* arr, int len, int req, int* a, int* b){
	Sort<int> sort;
	sort.insertsort(arr, len);

	int pairCount = 0;
	int p1 = 0; int p2 = len-1;
	while(p1 < p2){
		int sum = arr[p1] + arr[p2];

		if(sum < req)
			p1++;
		else if(sum > req)
			p2--;
		else{
			a[pairCount] = arr[p1];
			b[pairCount] = arr[p2];
			pairCount++;
			p1++;
			p2--;
		}
	}

	return pairCount;
}

int partition(int* arr, int start, int end){
	int pivot = arr[end];
	int ind = start;
	int pivotInd = start;
	while(ind < end){
		if(arr[ind] < pivot){
			swap(arr[ind], arr[pivotInd]);
			pivotInd++;
		}

		ind++;
	}

	swap(arr[pivotInd], arr[end]);

	return pivotInd;
}

void quicksort(int* arr, int start, int end){
	if(end - start >= 1){
		int pivotInd = partition(arr, start, end);
		quicksort(arr, start, pivotInd-1);
		quicksort(arr, pivotInd+1, end);
	}
	
}



int sumTriple(int* arr, int len, int req, int* a, int* b, int* c){
	// sort the arr by quick sort
	quicksort(arr, 0, len-1);
	for(int i = 0; i < len; i++){
		cout<<arr[i]<<" ";
	}
	//
	if(len >= 3){
		int count = 0;
		for(int k = 0; k < len-2; k++){
			int i = k+1;
			int j = len-1;
			int target = req - arr[k];
			while(i < j){
				int sum = arr[i] + arr[j];
				if(sum < target){
					i++;
				}
				else if(sum > target){
					j--;
				}
				else{
					a[count] = arr[k];
					b[count] = arr[i];
					c[count] = arr[j];
					count++;
					i++;
					j--;
				}
			}
		}

		return count;
	}
	else{
		return 0;
	}
}

int sumFour(int * arr, int len, int req, int* a, int* b, int* c, int* d){
	typedef pair<int,int> value;
	hash_map<int, value> map;
	for(int i = 0; i < len; i++){
		for(int j = i+1; j < len; j++){
			value p(i,j);
			map.insert(make_pair(arr[i] + arr[j], p));
		}
	}

	int count = 0;
	int* four = new int[4];
	hash_map<int, value>::iterator itr = map.begin();
	while(itr != map.end()){
		int target = req - (*itr).first;
		
		if(map.find(target) != map.end()){
			hash_map<int, value>::iterator itr2 = map.find(target);
			four[0] = (*itr).second.first;
			four[1] = (*itr).second.second;
			four[2] = (*itr2).second.first;
			four[3] = (*itr2).second.second;

			bool isDuplicate = false;
			for(int i = 0; i < 2; i++){
				for(int j = 2; j < 4; j++){
					if(four[i] == four[j]){
						isDuplicate = true;
						break;
					}
				}
			}
			if(!isDuplicate){
				a[count] = arr[four[0]];
				b[count] = arr[four[1]];
				c[count] = arr[four[2]];
				d[count] = arr[four[3]];
				count++;
			}
		}
		itr++;
	}

	return count;
}

int stepFloor(int nFloor){
	if (nFloor == 1)
		return 1;
	else if(nFloor == 2)
		return 2;
	else if(nFloor > 2 && nFloor < 5)
		return stepFloor(nFloor-1) + stepFloor(nFloor-2);
	else if(nFloor == 5)
		return 1 + stepFloor(nFloor-1) + stepFloor(nFloor-2);
	else
		return stepFloor(nFloor-1) + stepFloor(nFloor-2) +stepFloor(nFloor - 5);
}

void permute(char* arr,  char* pmt, int* used, int len, int curInd, int& count){
	if(curInd == len){
		for(int i = 0; i < len; i++)
			cout<<pmt[i];
		cout<<endl;
		count++;
		return;
	}

	for(int i = 0; i < len; i++){
		if(!used[i]){
			pmt[curInd] = arr[i];
			used[i] = 1;
			permute(arr, pmt, used, len, curInd+1, count);
			used[i] = 0;
		}	
	}

}

void combine(char* arr, int len, int cLen){
	char* cmb = new char[len];
	int* used = new int[len];
	for(int i = 0; i < len; i++){
		used[i] = 0;
	}
	int curInd = 0;
	int count = 0;

	combine(arr, cmb, used, len, cLen, 0, curInd, count);

	cout<<count<<endl;
}

void combine(char* arr, char* cmb, int* used, int len, int cLen, int startInd, int curInd, int& count){
	if(curInd == cLen){
		for(int i = 0; i < cLen; i++)
			cout<<cmb[i];
		cout<<endl;
		count++;
		return;
	}

	for(int i = startInd; i < len; i++){
		if(!used[i]){
			cmb[curInd] = arr[i];
			used[i] = 1;
			combine(arr, cmb, used, len, cLen, i+1, curInd+1, count);
			used[i] = 0;
		}	
	}
}

// 3 ,5 ,7,    3*3, 5*3, 7*3,      
int kth_divisible_by3(int k){
	IQueue<int> queue3; int out3 = 0;
	IQueue<int> queue5; int out5 = 0;
	IQueue<int> queue7; int out7 = 0;

	queue3.enqueue(3); 
	queue5.enqueue(5); 
	queue7.enqueue(7); 

	int cur_max;
	int cur_max_ind;
	while(k>0){
		 cur_max = *queue3.peek();
		 cur_max_ind = 3;

		if(*queue5.peek() < cur_max){
			cur_max_ind = 5;
			cur_max = *queue5.peek();
		}
		if(*queue7.peek() < cur_max){
			cur_max_ind = 7;
			cur_max = *queue7.peek();
		}

		if(cur_max_ind == 3){
			queue3.dequeue();
			queue3.enqueue(cur_max * 3);
			queue5.enqueue(cur_max * 5);
			queue7.enqueue(cur_max * 7);
		}
		else if(cur_max_ind == 5){
			queue5.dequeue();
			queue5.enqueue(cur_max * 5);
			queue7.enqueue(cur_max * 7);
		}
		else{
			queue7.dequeue();
			queue7.enqueue(cur_max * 7);
		}
		
		cout<<cur_max<<endl;
		k--;
	}

	return cur_max;
}

char* int2str(int i){
	IString s("\0");
	int remain = i;
	while(remain >= 1){
		char bit = '0' + (remain%10);
		char* appStr = new char[2];
		appStr[0] = bit; appStr[1] = '\0';
		s.append(appStr);
		remain = remain / 10;
	}

	s.reverse();

	return s.charStr();
}



double expValue(char* exp){
	IQueue<Op_Data> postfix;
	IStack<char> op_stack;

	IString expStr(exp);
	int len = expStr.length();

	int cur_value;
	char cur_op;

	// scan the string
	// example  (5+6*8*4)/(3+5) 
	// 568*4*
	
	for(int i = 0; i < len; i++){ // put data in postfix
		if(isDigit(expStr.charAt(i))){
			if(expStr.readInt(i, cur_value)){
				Op_Data v;
				v.data = cur_value; v.flag = 0;
				postfix.enqueue(v);
			}
		}
		else{
			cur_op = expStr.charAt(i);

			if(cur_op == ')'){
				while((cur_op = *op_stack.pop()) != '('){
					Op_Data v;
					v.op = cur_op; v.flag = 1;
					postfix.enqueue(v);
				}
			}
			else{
				while((!op_stack.empty()) && (op_c_priority (cur_op) < op_s_priority(*op_stack.peek()))){
					Op_Data v;
					v.op = *op_stack.pop();; v.flag = 1;
					postfix.enqueue(v);
				}

				op_stack.push(cur_op);
			}
			
		}
		//cout<<postfix<<endl;
		//cout<<op_stack<<endl;

	}

	

	while(!op_stack.empty()){
		Op_Data v;
		v.op = *op_stack.pop();; v.flag = 1;
		postfix.enqueue(v);
	}

	//cout<<postfix<<endl;

	IStack<double> run_stack;
	// calculation
	while(!postfix.empty()){
		Op_Data v = *postfix.dequeue();
		if(v.flag == 0){// data{
			run_stack.push(v.data);
		}
		else// operator
		{
			double v1 = *run_stack.pop();
			double v2 = *run_stack.pop();
			run_stack.push(calc(v1, v2, v.op));
		}
	}

	
	return *run_stack.pop();
}

double calc(double v1, double v2, int op){
	switch(op){
		case '+':
			return v1 + v2;
		case '-':
			return v2 - v1;
		case '*':
			return v1 * v2;
		case '/':
			if(v1 != 0)
				return 1.0 * v2 / v1;
			else
				return std::numeric_limits<int>::max();
	}
}

int op_c_priority(char op){
	if(op == '+' || op == '-')
		return 1;
	else if(op == '*' || op == '/')
		return 2;
	else if(op == '(')
		return 3;
	else
		return -1;
}

int op_s_priority(char op){
	if(op == '+' || op == '-')
		return 1;
	else if(op == '*' || op == '/')
		return 2;
	else if(op == '(')
		return -1;
	else
		return -1;
}

ostream& operator<<(ostream& output, const Op_Data& v){
	if(v.flag == 0)
		output<<v.data;
	else
		output<<v.op;

	return output;
}

bool isDigit(char c){
	if(c >= '0'  && c <= '9'){
		return true;
	}

	return false;
}

// 1 2 3 4
// ((1+2)+(3+4))
// 


void points24(int* a, int len){
	IString* expr = new IString[len];
	for(int i = 0; i < len; i++){
		IString e(int2str(a[i]));
		expr[i] = e;
	}
	
	points24(a,  len, expr);
}


void points24(int* a, int len, IString* exp){
	// + - * / 

	if(len == 1){
		/*if(exp[0] == "(((2-5)+3)*4)"){
			int k = 0;
		}*/
		if(abs(expValue(exp[0].charStr()) - 24) < esp)
			cout<<exp[0].charStr()<<endl;
	}
	else{ // n >= 2
		for(int i = 0; i < len; i++){
			for(int j = i+1; j < len; j++){
				{
					IString exp_i = exp[i];
					IString exp_j = exp[j];
					IString result("");
					exp[j] = exp[len-1];
					
					//+ 
					result = "(" + exp_i + "+" + exp_j + ")";
					exp[i] = result;
					points24(a, len-1, exp);

					//-
					result = "(" + exp_i + "-" + exp_j + ")";
					exp[i] = result;
					
					points24(a, len-1, exp);

					//-
					result = "(" + exp_j + "-" + exp_i + ")";
					exp[i] = result;
					points24(a, len-1, exp);

					//*
					result = "(" + exp_i + "*" + exp_j + ")"; 
					exp[i] = result;
					points24(a, len-1, exp);

					//  /
					result = "(" + exp_i + "/" + exp_j + ")";
					exp[i] = result;
					points24(a, len-1, exp);

					//  /
					result = "(" + exp_j + "/" + exp_i + ")";
					exp[i] = result;
					exp[j] = exp[len-1];
					points24(a, len-1, exp);
					
					exp[i] = exp_i;
					exp[j] = exp_j;
				}
			}
		}
	}
}


int longest_common_substr(char* s1, int len1, char* s2, int len2){
	//L is the prefix table , storing the length of longest substring in the prefix string 
	int** L = new int*[len1];
	for(int j = 0 ; j < len1; j++)
		L[j] = new int[len2];

    
	int cur_max = 0; // The variable is used to hold the length of the longest common substring found so far
	int ml = max(len1, len2); 
    int* max_last_ind = new int[ml]; // The set remax_last_ind saves the index i, which is the last character of the longest common substring (of size cur_max) 
	int count = 0; // the size of max_last_ind
    for (int i = 0 ; i < len1; i++){
        for (int j = 0 ; j < len2; j++){
            if (s1[i] == s2[j]){
				if( i == 0 || j == 0)
                    L[i][j] = 1;
                else
                    L[i][j] = L[i-1][j-1] + 1;
                
				if (L[i][j] > cur_max){// find a longer substring, replace fomer one
                    cur_max = L[i][j];
					count = 0;
					max_last_ind[count] = i;
				}
                if (L[i][j] == cur_max){// find a equally longest substring, record it
					count++;
					max_last_ind[count] = i;
				}
			}
			else
				L[i][j] = 0;
		}
	}
	

	//print result
	for(int k = 0; k <= count; k++){
		for(int m = max_last_ind[k] - cur_max + 1; m <= max_last_ind[k]; m++){
			cout<<s1[m];
		}
		cout<<endl;
	}

	//return max_substring length
	return cur_max;
}


void print_parentheses(int N){
	char* arr = new char[2*N];
	int n_left = N;
	int n_right = N;
	int ind = 0;
	print_parentheses(ind, N, n_left, n_right, arr);
}

void print_parentheses(int ind, int N, int n_left, int n_right, char* arr){
	if(n_left == 0 && n_right == 0){
		for(int i = 0; i < 2*N; i++)
			cout<<arr[i];
		cout<<endl;
	}
	else{
		if(n_left > 0){
			arr[ind] = '(';
			print_parentheses(ind+1, N, n_left-1, n_right, arr);
		}

		if(n_right > n_left){
			arr[ind] = ')';
			print_parentheses(ind+1, N, n_left, n_right-1, arr);
		}
	}
}

void print_subset(char* set){
	int len = strlen(set);
	bool* mask = new bool[len];
	int ind = 0;
	print_subset(set, len, mask, ind);
}

void print_subset(char* set, int len, bool* mask, int ind){
	if(ind == len){
		for(int i = 0; i < len; i++){
			if(mask[i]){
				cout<<set[i];
			}
		}
		cout<<endl;
	}
	else{
		mask[ind] = true;
		print_subset(set, len, mask, ind+1);
		
		mask[ind] = false;
		print_subset(set, len, mask, ind+1);
	}
}

void print_subset(char *A, int n) { 
   int i; 
   long c = 1 << n; // This is computing 2^n 
   for (i = 1; i <= c; ++i) { 
      int tmp = i; 
      int index = 0; 
      while(tmp > 0)  { 
         if(tmp & 1) { 
            printf("%c", A[index]);  
         } 
         tmp >>= 1; 
		 ++index; 
      } 
      printf("\n"); 
    } 
    
} 

int knapsack0_1(int* weights, int* value, int len, int maxW){
	int** c = new int*[len+1];
	
	for(int i = 0; i < len+1; i++){
		c[i] = new int[maxW+1];
		c[i][0] = 0;
	}
	for(int i = 0; i < len+1; i++){
		for(int w = 1; w < maxW+1; w++){
			if(i == 0){
				c[0][w] = 0;
			}
			else{
				if(weights[i-1] > w){
					c[i][w] = c[i-1][w];
				}
				else{
					c[i][w] = max(c[i-1][w], c[i-1][w-weights[i-1]] + value[i-1]);
				}
			}
		}
	}

	for(int i = 0; i < len+1; i++){
		for(int j = 0; j < maxW+1; j++){
			cout<<c[i][j]<<'\t';
		}
		cout<<endl;
	}

	return c[len][maxW];
}


double ISqrt(double a){
	double epsilon = 1E-20;
	double x_pre = 0;
	double x = a / 2;
	while(abs(x - x_pre) > epsilon){
		x_pre = x;
		x = (x_pre + (a/x_pre))/2.0;
	}
	
	return x;
}