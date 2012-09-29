#pragma once
using namespace std;

template <typename key_type, typename value_type>
class IHashMap
{
	struct _Map_Node{
		key_type key;
		value_type value;
	} ;

	int MAX_LEN;
	int size;
	_Map_Node** elements;

	void resize(int new_max_len);
public:
	IHashMap(void):MAX_LEN(5),size(0){
		elements = new _Map_Node*[MAX_LEN];
	}
	~IHashMap(void){}

	int hash(key_type k);
	void insert(key_type k, value_type v);
};

template <typename key_type, typename value_type>
void IHashMap<key_type, value_type>::resize(int NEW_MAX_LEN){
	_Map_Node** new_map = new _Map_Node*[NEW_MAX_LEN];

	int new_hash_code = 0;
	for(int i = 0; i != MAX_LEN; ++i){
		if(elements[i]){
			new_hash_code = hash(elements[i]->key) % NEW_MAX_LEN;
			
			while(new_map[new_hash_code])
				new_hash_code++;

			new_map[new_hash_code] = elements[i];

		}
	}

	swap(elements, new_map);
	delete[] new_map;
}


template <typename key_type, typename value_type>
int IHashMap<key_type, value_type>::hash(key_type e){
	std::hash<key_type> hashfunc;
	return abs((int)hashfunc(e));
}



template <typename key_type, typename value_type>
void IHashMap<key_type, value_type>::insert(key_type k, value_type v){
	if(size > MAX_LEN/2){
		MAX_LEN *= 2;
		resize(MAX_LEN);
	}

	int hash_code = hash(k) % MAX_LEN;

	bool hasDuplicate = false;
	while(elements[hash_code]){
		if(elements[hash_code]->key == k){
			hasDuplicate = true;
			break;
		}

		hash_code++;
	}

	if(!hasDuplicate){
		elements[hash_code] = new _Map_Node();
		elements[hash_code]->key = k;
		elements[hash_code]->value = v;
		size++;
	}
}