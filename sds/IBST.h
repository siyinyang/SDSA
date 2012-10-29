#pragma once

template<typename key_type, typename value_type>  
class IBST;

template<typename key_type, typename value_type>  
std::ostream& operator<< (std::ostream& output,  IBST<key_type, value_type>& bstree);

template<typename key_type, typename value_type>  
class IBST
{
public:
	struct TNode{
		key_type key;
		value_type value;
		TNode* left;
		TNode* right;
		TNode* parent;

		TNode(key_type k, value_type v):key(k),value(v),left(NULL),right(NULL),parent(NULL){}
		TNode(key_type k, value_type v, TNode* p):key(k),value(v),left(NULL),right(NULL),parent(p){}
		TNode(void){}
		~TNode(void){}
	};

	TNode* root;

	IBST(void){root = NULL; _size = 0;}
	IBST(key_type* keys, value_type* values, int nElems);
	IBST(key_type* infix, key_type* prefix, int nElems, value_type v);
	TNode* create_from_fix(key_type* infix, int start1, int end1, key_type* prefix, value_type v);
	~IBST(void);

	TNode* search(key_type key);
	void insert(key_type key, value_type value);
	void remove(key_type key);

	bool is_balanced();
	void set_balanced();
	bool is_subtree(IBST tree);
	bool is_symmetric();
	TNode* common_ancestor(TNode* n1, TNode* n2);

	TNode* next(TNode* node); // return inorder successor
	TNode* pre(TNode* node);
	
	int height();
	int size(){return this->_size;}
	
	std::ostream& outputTNode(std::ostream& output, TNode* node);
	friend std::ostream& operator<< <>(std::ostream& output,  IBST<key_type, value_type>& bstree);

private:
	int _size;
	bool is_symmetric(TNode* node);
	TNode* common_ancestor(TNode* root, TNode* n1, TNode* n2);
	bool is_balanced(TNode* root);
	void set_balanced(TNode* node);
	void replace_node(TNode* node, TNode* newTNode);
	int height(TNode* node);
};

template <typename key_type, typename value_type>
IBST<key_type, value_type>::IBST(key_type* keys, value_type* values, int nElems)
{
	if(keys == NULL)
		return;

	for(int i = 1; i < nElems; i++){
		insert(keys[i], values?values[i]:NULL);
	}
};

template <typename key_type, typename value_type>
IBST<key_type, value_type>::IBST(key_type* infix, key_type* prefix, int nElems, value_type v){
	this->root = create_from_fix(infix, 0, nElems-1, prefix, v);
};

template <typename key_type, typename value_type>
typename IBST<key_type, value_type>::TNode* IBST<key_type, value_type>::create_from_fix(key_type* infix, int startIn, int endIn, key_type* prefix, value_type v){
	static int preInd = 0;
	if(startIn - endIn <= 0){
		TNode* node = new TNode(prefix[preInd++] , v);

		int inInd = 0;
		for(int i = startIn; i <= endIn; i++){
			if(node->key == infix[i]){
				inInd = i;
				break;
			}
		}
		
		node->left = create_from_fix(infix, startIn, inInd-1, prefix, v);
		node->right = create_from_fix(infix, inInd+1, endIn, prefix, v);

		return node;
	}
	else{
		return NULL;
	}
};

template <typename key_type, typename value_type>
IBST<key_type, value_type>::~IBST(void)
{
};

template <typename key_type, typename value_type>
bool IBST<key_type, value_type>::is_symmetric(void)
{
	if(root != NULL)
		return is_symmetric(root);
	else
		return true;
};

template <typename key_type, typename value_type>
bool IBST<key_type, value_type>::is_symmetric(TNode* node)
{
	if((node->left == NULL) && (node->right == NULL)){
		return true;
	}
	else if(node->left != NULL && node->right != NULL){
		return is_symmetric(node->left) && is_symmetric(node->right);
	}else{
		return false;
	}
};

template <typename key_type, typename value_type>
bool IBST<key_type, value_type>::is_balanced(TNode* root)
{
	if(root == NULL)
		return true;
		
	if(abs(height(root->left) - height(root->right)) > 1)
		return false;
	else{
		return is_balanced(root->left) && is_balanced(root->right);
	}
};

template <typename key_type, typename value_type>
typename IBST<key_type, value_type>::TNode* IBST<key_type, value_type>::search(key_type key){
	TNode* next = this->root;

    while (next != NULL) {
        if (key == next->key) {
            return next;
        } else if (key < next->key) {
            next = next->left;   
        } else {
            next = next->right;
        }
    } 

	return NULL;
};

template <typename key_type, typename value_type>
void IBST<key_type, value_type>::set_balanced(TNode* root){
	if(!is_balanced(root))
	{
		
	}
}

template <typename key_type, typename value_type>
void IBST<key_type, value_type>::insert(key_type key, value_type value){
	if(this->root == NULL){
		this->root = new TNode(key,value,NULL);
		_size++;
		return;
	}
	
	TNode* node = root;
	while(node != NULL){
		if (key < node->key)
		{
			if(node->left == NULL){
				node->left = new TNode(key,value,node);
				_size++;
				//set_balanced();
				return;
			}
			else
				node = node->left;
		}
		else if (key > node->key)
		{
			if(node->right == NULL){
				node->right = new TNode(key,value,node);
				//set_balanced();
				_size++;
				return;
			}
			else
				node = node->right;
		}
		else{
			node->value = value;
		}
	}
};

template <typename key_type, typename value_type>
void IBST<key_type, value_type>::replace_node(TNode* node, TNode* newNode){
	TNode* parent = node->parent;

	if(parent){
		if(parent->left == node)
			parent->left = newNode;
		else
			parent->right = newNode;
	}
	else
		root = newNode;

	if(newNode)
		newNode->parent = parent;
};

template <typename key_type, typename value_type>
void IBST<key_type, value_type>::remove(key_type key){
	if(this->root == NULL)
		return;
	
	TNode* next = this->root;
	TNode* newNode = NULL;

	while(next != NULL){
		if (key < next->key)
		{
			next = next->left;
		}
		else if (key > next->key)
		{
			next = next->right;
		}
		else{// delete node here
			if((next->left != NULL) && (next->right != NULL)){// delete node with 2 children
				//find left most child of right branch
				newNode = next->right;
				while(newNode->left)
					newNode = newNode->left;

				next->key = newNode->key;
				next->value = next->value;
				
				replace_node(newNode, newNode->right);
			}
			else if(next->left || next->right){// delete node with one child
				newNode =  (next->left == NULL)?next->right:next->left;
				replace_node(next, newNode);
			}
			else{ // delete a leaf
				replace_node(next, NULL);
			}

			//set_balanced();
			_size--;
			delete next;
			return;
		}

	}
};

// need to be refactored
template <typename key_type, typename value_type>
std::ostream& IBST<key_type, value_type>::outputTNode(std::ostream& output, TNode* node){
	if(node != NULL){
		output<< "(" <<  node->key << ", " << node->value <<")";
		if (node->left != NULL)
			outputTNode(output, node->left);
		if (node->right != NULL)
			outputTNode(output, node->right);
	}
	return output;  // for multiple << operators.
}

template <typename key_type, typename value_type>
std::ostream& operator<< (std::ostream& output, IBST<key_type, value_type>& bstree){
	return bstree.outputTNode(output, bstree.root);
}

template <typename key_type, typename value_type>
int IBST<key_type, value_type>::height(TNode* node)
{
	if(node == NULL)
		return 0;
	else
		return 1 + max(height(node->left), height(node->right));
};

template <typename key_type, typename value_type>
int IBST<key_type, value_type>::height()
{
	return height(root);
};

template <typename key_type, typename value_type>
typename IBST<key_type, value_type>::TNode* IBST<key_type, value_type>::common_ancestor(TNode* n1, TNode* n2){
	return common_ancestor(root, n1, n2);
};

template <typename key_type, typename value_type>
typename IBST<key_type, value_type>::TNode* IBST<key_type, value_type>::common_ancestor(TNode* root, TNode* n1, TNode* n2){
	if(root ==NULL){
		return root;
	}else if(root == n1){
		return n1;
	}else if(root == n2){
		return n2;
	}
	else{
		TNode* left = common_ancestor(root->left, n1, n2);
		TNode* right = common_ancestor(root->right, n1, n2);

		if(left!= NULL && right!=NULL)
			return root;
		else
			return (left==NULL)?right:left;
	}
};

template <typename key_type, typename value_type>
typename IBST<key_type, value_type>::TNode* IBST<key_type, value_type>::next(TNode* node)
{
	if(node == root || node->right != NULL){
		TNode* left;
		while((left = node->left) != NULL){
			node = left;
		}

		return node;
	}
	else{
		TNode* parent;
		while((parent = node->parent) != NULL){
			if(parent-> left == node)
				return parent;

			node = parent;
		}

		return NULL;
	}
};