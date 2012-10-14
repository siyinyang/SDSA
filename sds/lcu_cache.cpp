#include <iostream>
#include <map>


using namespace std;

int find_odd_freq(int arr[], int len){
	map<int, int> m;

	for(int i = 0; i < len; i++){
		if(m.find(arr[i]) != m.end()){
			m[arr[i]] += 1;
		}
		else{
			pair<int, int> p(arr[i], 1);
			m.insert(p);
		}
	}

	for(map<int, int>::iterator itr = m.begin(); itr != m.end(); itr++){
		if((*itr).second & 1){
			return (*itr).first;
		}
	}
	
	throw 0;
}

struct _unit{
	int v;
};

typedef struct _unit unit;

class hash_map{
public: 
	int find(int v, unit& addr);
	int remove(int v);
};

class dlist{
public:
	int pop_back(const unit& v);
	int push_front(const unit& v);
};

class lcu_cache{
	private:
		hash_map map;
		dlist list;
		int capacity;					
	public:
		int access(int v);
		int add(int v);	
};

int main(){
	int arr[] = {10, 2, 2, 4, 10, 4, 4, 4};
	int len = 8;
	try{
		cout<<find_odd_freq(arr, len);
	}
	catch(int e){
		cout<<"no match!"<<endl;
	}
	return 0;
}
