#include <iostream>
#include <string>
#include <sstream>
#include "assert.h"
#include "IBST.h"
#include "ILinkedList.h"
#include "IStack.h"
//#include "IQueue.h"
//#include "KVNode.h"
//#include "IGraph.h"
#include "IHashMap.h"
//#include "IHeap.h"
//#include "ISet.h"
//#include "IMatrix.h"

using namespace std;

int print_arr(int arr[], int len);
void run_test_suites();
int testILinkedList();
int testIHashMap();
int testIStack();
int testIBST();

//bool myfunction (int i,int j) { return (i<j); }
//
//struct myclass {
//  bool operator() (int i,int j) { return (i<j);}
//} myobject;

//class node{
//public:
//	int i ;
//	int j;
//	node(){i = 1; j = 2;}
//};
//
//template <typename T>
//class SmartPtr{
//protected:
//	T* ptr;
//	int ref;
//public:
//	
//	SmartPtr(T* ptr){ref = 0; this->ptr = ptr;}
//	SmartPtr(SmartPtr<T>& sptr){
//		this->ptr = sptr.ptr;
//		this->ref = sptr.ref;
//		this->ref++;
//	}
//
//	~SmartPtr(){
//		this->ref--;
//		if(ref == 0){
//			delete ptr;
//			ptr = NULL;
//		}
//	}
//
//	SmartPtr& operator+(SmartPtr<T>& sptr){
//		if(this == &sptr)
//			return *this;
//
//		this->ptr = sptr.ptr;
//		this->ref = sptr.ref;
//		this->ref++;
//		return *this;
//	}
//
//	T* operator->(){
//		return ptr;
//	}
//	T operator*(){
//		return *ptr;
//	}
//	
//};


int main()
{
	//smart pointer
	/*node* a = new node();
	SmartPtr<node> ptr1(a);
	SmartPtr<node> ptr2(ptr1);
	SmartPtr<node> ptr3 = ptr2;
	
	cout<<ptr1->i<<ptr1->j<<endl;
	cout<<(*ptr3).i<<ptr2->j<<endl;*/
	
	////quick sort test 
	//int N = 10;
	//Node<int, int>* arr = new Node<int, int>[N]; 
	//for (int i = 0; i < N; i++){
	//	arr[i] = Node<int, int>(rand()%N, 0);
	//	cout<<arr[i]<<' ';
	//}
	//cout<<endl;
	//Sort<Node<int,int>> S;
	//S.quicksort(arr, 0, N-1);

	//for (int i = 0; i < N; i++){
	//	cout<<arr[i]<<' ';
	//}
	//cout<<endl;

	////merge sort test 
	//for (int i = 0; i < N; i++){
	//	arr[i] = Node<int, int>(rand()%N, 10);
	//	cout<<arr[i]<<' ';
	//}
	//cout<<endl;
	//S.mergesort(arr, 0, N-1);

	//for (int i = 0; i < N; i++){
	//	cout<<arr[i]<<' ';
	//}
	//cout<<endl;

	/*const int LEN = 20;
	int myints[LEN];
	for(int i = 0; i != LEN; ++i)
		myints[i] = rand()%1000;
	
	Sort<int> sort;
	sort.heapsort(myints, LEN);
	for(int i = 0; i < LEN; i++)
		cout<<myints[i]<<" ";
	cout<<endl;*/







	//IQueue Test
	/*int arr[] = { 1, 2, 3 } ;
	IQueue<int> queue(arr);
	cout <<queue<<endl;
	for(int i = 0; i < 2; i++)
		cout<<queue.dequeue()<<' ';
	for(int i = 0; i < 6; i++)
		queue.enqueue(5);
	cout<<queue<<endl;

	for(int i = 0; i < 10; i++)
		queue.enqueue(i);

	cout<<queue<<endl;
	while(!queue.empty())
		cout<<queue.dequeue()<<' ';*/

	//// IGraph
	//IGraph<char, int> graph(10);
	//graph.insertVertex('A');
	//graph.insertVertex('B'); 
	//graph.insertEdge('A','B',300);
	//graph.insertVertex('C'); 
	//graph.insertEdge('A','C',200);
	//graph.insertVertex('E'); 
	//graph.insertEdge('A','E',250); 

	//graph.insertVertex('D'); 
	//graph.insertEdge('B','D',250); 
	//graph.insertVertex('F'); 
	//graph.insertEdge('B','F',250);
	//graph.insertEdge('E','F',250);  
	//graph.insertVertex('G'); 
	//graph.insertEdge('C','G',250); 
	//graph.insertVertex('H');
	//graph.insertEdge('G','H', 100);
	//graph.insertVertex('I');
	//cout<<"The graph's edge matrix is "<< endl<< graph<<endl;

	//cout<<"DFS"; graph.DFS(); cout<<endl;
	//cout<<"BFS"; graph.BFS(); cout<<endl;
	//cout<<"IDFS"; graph.IDFS(); cout<<endl;
	//
	//cout<<"has path between 2 nodes test:"<<endl; 
	//for(char i = 'A'; i <= 'H'; i++)
	//	for(char j = i+1; j <= 'H'; j++){
	//		cout<<i<<" and " <<j<<" ";
	//		cout<<graph.hasPath(i, j)<<endl;
	//	}

	//for(char i = 'A'; i <= 'H'; i++){
	//	cout<<i<<" and H"<<" ";
	//	cout<<graph.hasPath(i, 'I')<<endl;
	//}


	//// graph diksjira 数学建模
	///*struct IGraphEdge{
	//	int weight;
	//	int type;
	//};*/

	//ifstream inFile;
	//ofstream outFile;
	//inFile.open("graph.txt");

	//if (!inFile) {
	//	cerr << "Unable to open file datafstopile.txt";
	//	exit(1);   // call system to 
	//}

	////int N = 0;
	////inFile>>N;
	//int nV = 0;
	//inFile>>nV;
	//IGraph<IString, int> map(50);
	//
	//for(int i = 0; i < nV; i++){
	//	char* nodeName = new char[5];
	//	inFile>>nodeName;
	//	IString s(nodeName);
	//	map.insertVertex(s);
	//}

	//int nE = 0;
	//inFile>>nE;
	//
	//char* s1 = new char[5];
	//char* s2 = new char[5];
	//int distance = 0;
	//for(int j = 0; j < nE; j++){
	//	inFile>>s1;
	//	inFile>>s2;
	//	inFile>> ;
	//	inFile>> ;
	//	IString v1(s1);
	//	IString v2(s2);
	//	map.insertEdge(v1, v2, );
	//}
	//

	//inFile.close();
	//
	////IGraph<IString, IGraphEdge> map("graph.txt"); 
	//
	//cout<<map;


	////dynamic programming
	//int arr[] = {90,30,24,15,12,10,5,3,2,1};
	//int n = 10;
	//int request = 1000;
	//int* reqArr;
	//reqArr = new int[n];

	//int num = min_number_of_stamps<int>(arr, n, request, reqArr);
	//cout<<num<<endl;
	

	//cout<<fibonacci(2);

	//// substring search by kmp method
	//char* S = "ABC ABABAB ABCDABCDABDE";
	//char* W = "ABCDA";
	//cout<<MyString::kmpSearch(S, W);

	//swap string
	//char str[] = "abcdefghijklmn";
	//char* s = str;
	//MyString::swapAt_2(str, 3, 0, strlen(str)-1);
	//cout<< str;

	//MyString::swapAt_3(str, 3);
	//cout<<str;
	

	////dynamic programming
	//int m = 5; int n = 5;
	//int** c = new int*[m];
	//for(int y = 0; y < m; y++){
	//	c[y] = new int[n];
	//	for(int x = 0; x < n; x++)
	//		c[y][x] = rand()%10;
	//}

	//print2DArrays<int>(c, m, n);

	//int** p = computeShortestPathArrays(c, m, n);

	//cout<<endl;
	//print2DArrays<int>(p, m, n);


	//// google jam questions
	//ifstream inFile;
	//ofstream outFile;
	//inFile.open("A-large-practice.in");
	//outFile.open ("output.txt", ios::out);

	//if (!inFile) {
	//	cerr << "Unable to open file datafile.txt";
	//	exit(1);   // call system to stop
	//}
	//Sort<int> sort;

	//int N = 0;
	//inFile >> N;
	//int C = 0; int I = 0;
	//for(int i = 0; i < N; i++){
	//	outFile<<"Case #"<<i+1<<": ";
	//	inFile >> C;
	//	inFile >> I;
	//	int * P = new int[I];
	//	int *ind;
	//	for(int j = 0; j < I; j++)
	//		inFile>>P[j];
	//	
	//	

	//	ind = sort.insertsort(P, I);

	//	int ptr1 = 0; int ptr2 = I-1;
	//	while(ptr1 < ptr2){
	//		if(P[ptr1]+P[ptr2]==C){
	//			int ind1 = min(ind[ptr1], ind[ptr2]);
	//			int ind2 = max(ind[ptr1], ind[ptr2]);
	//			outFile<<ind1+1<<" "<<ind2+1;
	//			break;
	//		}
	//		else if(P[ptr1]+P[ptr2]<C)
	//			ptr1++;
	//		else
	//			ptr2--;
	//	}
	//	outFile<<endl;
	//}

	//inFile.close();
	//outFile.close();

	//// get all prime numbers in fibonacci array
	//int n = 50;
	//int*  fib = new int[n];
	//for(int i = 0; i < n; i++){
	//	// generate
	//	if (i==0) fib[i]=0;
	//	else if(i==1) fib[i]=1;
	//	else fib[i] = fib[i-1]+fib[i-2];

	//	//test if prime
	//	bool isPrime = true;
	//	for(int j = 2; j <= (fib[i]/2); j++)
	//		if(fib[i]%j==0){
	//			isPrime = false;
	//			break;
	//		}

	//	if(isPrime)
	//		cout<< fib[i]<<" ";
	//}
	
	// google jam - city tour problem
	// IGraph
	//ifstream inFile;
	//ofstream outFile;
	//inFile.open("B-large-practice.in");
	//outFile.open ("output.txt", ios::out);

	//if (!inFile) {
	//	cerr << "Unable to open file datafile.txt";
	//	exit(1);   // call system to stop
	//}

	//int N = 0;
	//inFile>>N;
	//int nV = 0;
	//int v1 = 0; int v2 = 0;
	//for(int i = 0; i < N; i++){
	//	inFile>>nV;
	//	IGraph<char, int> graph(nV);
	//	for(int j = 1;  j<= nV; j++)
	//		graph.insertVertex(char(j+'0'));

	//	graph.insertEdge('1','2',1);
	//	graph.insertEdge('1','3',1);
	//	graph.insertEdge('3','2',1);

	//	for(int j = 4; j<=nV; j++){
	//		inFile>>v1;
	//		inFile>>v2;
	//		graph.insertEdge(char(v1+'0'), char(j+'0'),1);
	//		graph.insertEdge(char(v2+'0'), char(j+'0'),1);
	//	}
	//	
	//	//cout<<graph;
	//	outFile<<"Case #"<<i+1<<": "<<graph.MaxRing()<<endl;
	//}

	//inFile.close();
	//outFile.close();

	
	// find the request word in the sorted dictionary with unknown size
	// if the request word can be found , return index number
	// otherwise return -1;
	/*int im_width = 3;
	int im_height = 3;
	double* filtered = new double[9];
	
	int num_bins = 5;
	double* response = new double[num_bins];
	int MAX_INTENSITY = 5;
	double mult = (double)num_bins / MAX_INTENSITY;
	double half_num = (double)num_bins / 2;
	for (int i = 0; i < num_bins; i++)
		response[i] = 0;

	for (int i = 0; i < im_width * im_height; i++)
	{
		filtered[i] = (int)(rand()%MAX_INTENSITY);
		cout<< filtered[i]<<' ';
		int index = mult * filtered[i];
		response[index] = response[index] + 1;
	}
	cout<<endl;

	for (int i = 0; i < num_bins; i++)
		cout<< response[i]<<' ';*/
	
	//int myints[] = {32,71,12,45,26,80,53,33};
	//vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33
	//vector<int>::iterator it;

	//sort(myvector.begin(), myvector.begin()+4, myobject);

	//myobject(1,2);
	//myfunction(1,2);

	//cout << "myvector contains:";
	//for (it=myvector.begin(); it!=myvector.end(); ++it)
 //   cout << " " << *it;

	//cout << endl;

	

	//cout<<fibonacci2(10)<<fibonacci(10);
	//cout<<count2(35);

	//cout<<addTwoNumWithoutArithmeticOp(45, 291);

	/*int len = 16;
	double heights[] = {1, 2 ,3, 4,  5, 6,  7, 8,  9 ,10,11,12, 13,14, 15,16};
	double weights[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

	double* cHeights = new double[len];
	double* cWeights = new double[len];

	int cCircus = circus(heights, weights, len, cHeights, cWeights);
	cout<<cCircus<<endl;

	for(int i = 0; i < cCircus; i++){
		cout<<"("<<cHeights[i]<<","<<cWeights[i]<<")"<<endl;
	}*/

	/*char str[] = "Iamagoooooodguy";
	char* str1 = str;
	removeDuplicate(str);
	
	cout<<str;*/

	//double arr[] =  {2, -8, 3, -2, 4, -10};
	//cout<<findMaxSumSeq(arr, 6);
	/*int arr[] = {10, 2, 4, 5, 8, 11, 13, 3, 16, 18, 1, 6, 6};
	int req = 17;
	int* a  = new int[100];
	int* b = new int[100];
	int* c = new int[100];
	int* d = new int[100];
	int count = sumFour(arr, 13, req, a, b, c, d);
	
	for(int i = 0; i < count; i ++){
		cout<<"("<<a[i]<<","<<b[i]<<","<<c[i]<<","<<d[i]<<")"<<endl;
	}*/

	/*for(int i = 1; i < 8; i++)
		cout<<stepFloor(i)<<endl;*/

	///*A *pA; 
	//B b; 
	//const A *pcA; 
	//pA=&b; 
	//pA->func(1); 
	//pA->func("test"); 
	//A().func(1); 
	//pcA=&b; 
	//pcA->func(2); */
	
	//Derived* p = new Derived;
	//delete p;

	/*int len = 7;
	char* str = new char[len];
	char* pmt = new char[len];
	int* used = new int[len];
	for(int i = 0; i < len; i++){
		str[i] = (char)(i + 'a');
		used[i] = 0;
	}
	int curInd = 0;
	int count = 0;
	permute(str, pmt, used, len, curInd, count);
	cout<<count<<endl;*/

	/*int len = 7;
	char* str = new char[len];

	for(int i = 0; i < len; i++){
		str[i] = (char)(i + 'a');
	}
	combine(str, len, 4);*/
	

	//// point 24
	//int arr[] = {2, 10, 3, 4};
	//int* a = arr;
	//points24(a, 4);
	
	
	//points24(a, 4);
	//cout<<expValue("2*((3+4)*2)+10*3");
	 
	
	/*int arr[4];
	for (int i = 0; i < 4; i++){
		cout<<rand()%10 + 1<<endl;
	}*/

	//int arr[] = {1,1,1,2,3,4};
	//cout<<binarySearch<int>( 1,arr, 6);



	/*IHeap<int> heap;

	cout<< "random numbers"<<endl;
	for(int i = 0; i != 200; ++i){
		int rand_num = rand()%1000;
		heap.insert(rand_num);
		cout<<rand_num<<" ";
	}
	cout<<endl;

	cout<<"heap structure"<<endl<<heap<<endl;

	cout<<"heap sort"<<endl;
	while( !heap.is_empty()){
		cout<<heap.get_top()<<" ";
		heap.remove_top();
	}*/

	//test ISet
    
	////randomly generate N unique numbers
	//int n = 100;
	//int m = 0;
	//int MAX = 1000;
	//

	//ISet<int> set_int;
	////randomly generate N unique numbers
	//cout<<"random numbers"<<endl;
	//while(m < n){
	//	int v = rand()% MAX;
	//	cout<<v<<" ";
	//	set_int.add(v); 
	//	m = set_int.size();
	//}

	//cout<<endl;
	//cout<<"set numbers"<<endl<<set_int<<endl;

	////test generic set
	//ISet<char*> set_string;
	//char* str1 = "hello";
	//char* str2 = "world";
	//char* str3 = "siyin";
	//set_string.add(str1);
	//set_string.add(str2);
	//set_string.add(str3);

	//cout<<set_string;
	//char* s1 = "travelling"; int len1 = 10;
	//char* s2 = "traveling"; int len2 = 9;
	//cout<<longest_common_substr(s1, len1, s2,  len2);
	
	// print numbers whose only factors are 3, 5, 7
	//kth_divisible_by3(20);

	// print equal number of parentheses
	//print_parentheses(5);
	
	//print all subsets of a set
	//print_subset("abcd");
	//print_subset("abcd", 4);
	
	//test knapsack 0 -1 problem
	/*const int len = 4;
	int maxW = 10;
	int v[len] = {10, 40 , 30, 50};
	int w[len] = {5, 4, 6, 3};
	cout<<knapsack0_1(w, v, len, maxW);*/
	

	//sqrt root test
	//cout<<ISqrt(2);
	
	//char* ptr = (char*)malloc(10*sizeof(char));
	
	//IMatrix test
	 /*double temp[3][4] = { {  1, 2, -1,  -4 },
                     {  2, 3, -1, -11 },
                     { -2, 0, -3,  22 } };
	  double** M = new double*[3];
	  for(int i = 0; i < 3; i++){
		M[i] = new double[4];
		for(int j = 0; j < 4; j++){
			M[i][j] = temp[i][j];
		}
	  }
	  IMatrix<double> Mat(M,3,4);
	  Mat.to_reduced_row_echelon_form();
	  for (int i = 0; i < 3; ++i)
	  {
			for (int j = 0; j < 4; ++j){
				printf("%f\t",Mat.element(i,j));
			}
			printf("\r\n");
	  }
	  printf("success!");
	  cout<<Mat.rank();

	bool hi = true;
	hi &= false;
	cout<<hi;
	*/

	// write and read binary file
	/*FILE *fp = fopen("binary.txt","wb");
    if(fp == NULL) {
        printf("error creating file");
        return;
    }
    const char* val = "hello"; 
	
    fwrite((const void*)val,sizeof(char),1,fp);
    fclose(fp);

	fp = fopen("binary.txt", "rb");
	char fuck[10];
	int size = fread((void*)fuck, sizeof(char), 10, fp);
	cout<<size<<endl;
	fclose(fp);*/

	
    run_test_suites();
	return 0;
}

int print_arr(int arr[], int len){
	for(int i = 0; i < len; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void run_test_suites(){
	testILinkedList();
	testIHashMap();
	testIStack();
	testIBST();
}

int testILinkedList(){
	cout<<"************Start Testing ILinkelinkedlist************"<<endl;   
	int len = 8; 
	int arr[] = { 4, 6, 8, 32, 19, 100, 2, 24} ;
	
	cout<<"build array"<<endl;
	print_arr(arr, len);
 	
	cout<<"build linked list from array"<<endl;
	ILinkedList<int> linkedlist(arr);
	cout<<linkedlist<<endl;

	cout<<"get 4th element:";
	cout<< linkedlist.get(3)<<endl;
	assert(linkedlist.get(3)==32);
	cout<<"get 4th last element:";
	cout<< linkedlist.get_last(3)<<endl;
	assert(linkedlist.get_last(3)==19);
	
	cout<<"push back element 11"<<endl;
	linkedlist.push_back(11);    
	cout<<linkedlist<<endl;
	
	cout<<"remove element 4 8 11"<<endl;
	linkedlist.remove(4);
	linkedlist.remove(8);
	linkedlist.remove(11);
    cout<<linkedlist<<endl;
	
	cout<<"find if list has 6:";
	cout<< linkedlist.find(6)<<endl;
	assert(linkedlist.find(6)>=0);
	
	cout<<"find if list has 11:";
	cout<< linkedlist.find(11)<<endl;
	assert(linkedlist.find(11)==-1);

	cout<<"convert linkedlist to array"<<endl;
	print_arr(linkedlist.to_array(), linkedlist.size);
	
	cout<<"reverse linkedlist"<<endl;
	linkedlist.reverse();
	cout<<linkedlist<<endl;
	linkedlist.reverse();
	cout<<linkedlist<<endl;
}

int testIHashMap(){
	cout<<"************Start Testing IHashMap************"<<endl;   
	IHashMap<string, int> hash_map;
	
	hash_map.put("siyin", 10);
	hash_map.put("ucla", 5);
	hash_map.put("siyin", 20);
	hash_map.put("didi", 100);
	cout<<hash_map<<endl;
	
	cout<<"find if hash table has siyin:";
	cout<<hash_map.exist("siyin")<<endl;
	cout<<"find if hash table has stanford:";
	cout<<hash_map.exist("stanford")<<endl;

	cout<<"add 100 elements to hash table"<<endl;
	for(int i = 0; i < 100; i++){
		stringstream key;
		key<<"test"<<i;
		hash_map.put(key.str(), i);
	}
	cout<<"capacity: "<<hash_map.MAX_LEN<<" "<<hash_map.size<<" elements:"<<hash_map<<endl;
}

int testIStack(){	
	cout<<"************Start Testing IStack************"<<endl; 
	int len = 8; 
	int arr[] = {  4, 6, 8, 32, 19, 100, 2, 24 } ;
	cout<<"build array"<<endl;
	print_arr(arr, len);
 	
	cout<<"build linked list from array"<<endl;
		IStack<int> stack(arr);
	cout<<stack<<endl;
	
	cout<<"push 11 to stack"<<endl;
	stack.push(11);
	assert(*(stack.peek())==11);
	cout<<stack<<endl;
	cout<<"pop all elements from stack"<<endl;
	while(!stack.empty())
		cout<<*(stack.pop())<<' ';
	cout<<endl;
	
	cout<<"push 150 elements to stack"<<endl;
	for(int i = 0; i < 150; i++)
		stack.push(i);
	
	while(!stack.empty())
		stack.pop();
}

int testIBST(){
	cout<<"************Start Testing IBST************"<<endl; 
	cout<<"start building tree from prefix&infix"<<endl;
	/** 
						D
					/		\
				B				F
			  /	  \           /   \
			A	 	C 		E		G
	*/
	const int len = 7;
	char infix[len] = {'A', 'B' , 'C' , 'D', 'E', 'F', 'G'};
	char prefix[len] = {'D', 'B' , 'A' , 'C', 'F', 'E', 'G'};
	
	IBST<char, int> tree(infix, prefix, len, 1);
	cout<<tree<<endl;
	cout<<"is tree symmetric: " <<tree.is_symmetric()<<endl;
	
	cout<<"does element 'F' exists: "<<(tree.search('F') != NULL)<<endl;
	cout<<"remove F"<<endl;
	tree.remove('F');
	cout<<"does element 'F' exists: "<<(tree.search('F') != NULL)<<endl;
	cout<<tree<<endl;
	
	cout<<"commone ancestor of A and E: "<<endl;
	IBST<char, int>::TNode* ancestor = tree.common_ancestor(tree.search('A'), tree.search('E'));
	if(ancestor)
		cout<<ancestor->key<<endl;
	
	/*cout<<"add 10 more elements"
	for (int i = 0; i < 10; i++){
		char key = (char)('H'+i);
		int value = i;
		tree.insert(key, value);
	}
	assert(tree.is_balanced());*/
}
