#pragma once

#include <iostream>
using namespace std;


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
	IBST(TNode* elems, int nElems);
	IBST(key_type* infix, key_type* prefix, int nElems);
	TNode* createFromFix(key_type* infix, int start1, int end1, key_type* prefix);
	~IBST(void);

	TNode* search(key_type key);
	bool insert(TNode& node);
	bool remove(key_type key);
	void replaceTNodeInParent(TNode* node, TNode* newTNode);
	bool isBalanced();
	void setBalanced();

	bool isSubTree(IBST tree);

	bool isSymmetric();
	bool isSymmetric(TNode* node);

	TNode* leftMostChild(TNode* node);
	TNode* next(TNode* node); // return inorder suc

	int height();
	int height(TNode* node);
	int size(){return this->_size;}

	TNode* common_ancestor(TNode* n1, TNode* n2);
	TNode* common_ancestor(TNode* root, TNode* n1, TNode* n2);
	
	ostream& outputTNode(ostream& output, TNode* node);
	friend ostream& operator<< <>(ostream& output,  IBST<key_type, value_type>& bstree);

private:
	int _size;
};




template <typename key_type, typename value_type>
IBST<key_type, value_type>::IBST(TNode* elems, int nElems)
{
	if(elems == NULL)
		return;
	else
		root = &elems[0];

	for(int i = 1; i < nElems; i++){
		this->insert(elems[i]);
	}
};

template <typename key_type, typename value_type>
IBST<key_type, value_type>::IBST(key_type* infix, key_type* prefix, int nElems){
	this->root = createFromFix(infix, 0, nElems-1, prefix);
};

template <typename key_type, typename value_type>
typename IBST<key_type, value_type>::TNode* IBST<key_type, value_type>::createFromFix(key_type* infix, int startIn, int endIn, key_type* prefix){
	static int preInd = 0;
	if(startIn - endIn <= 0){
		TNode* node = new TNode(prefix[preInd++] ,NULL);
		cout<<"create root" <<node->key<<endl;

		int inInd = 0;
		for(int i = startIn; i <= endIn; i++){
			if(node->key == infix[i]){
				inInd = i;
				break;
			}
		}
		
		node->left = createFromFix(infix, startIn, inInd-1, prefix);
		node->right = createFromFix(infix, inInd+1, endIn, prefix);

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
bool IBST<key_type, value_type>::isSymmetric(void)
{
	if(root != NULL)
		return isSymmetric(root);
	else
		return true;
};

template <typename key_type, typename value_type>
bool IBST<key_type, value_type>::isSymmetric(TNode* node)
{
	if((node->left == NULL) && (node->right == NULL)){
		return true;
	}
	else if(node->left != NULL && node->right != NULL){
		return isSymmetric(node->left) && isSymmetric(node->right);
	}else{
		return false;
	}
};

template <typename key_type, typename value_type>
bool IBST<key_type, value_type>::isBalanced(void)
{
	if(height(root->left) == height(root->right))
		return true;
	else
		return false;
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
void IBST<key_type, value_type>::setBalanced(){
	if(!isBalanced())
	{

	}
}

template <typename key_type, typename value_type>
bool IBST<key_type, value_type>::insert(TNode& node){
	if(this->root == NULL){
		this->root = &node;
		_size++;
		return true;
	}
	
	TNode* next = this->root;
	key_type key = node.key;
	while(next != NULL){
		if (key < next->key)
		{
			if(next->left == NULL){
				next->left = &node;
				node.parent = next;
				_size++;
				setBalanced();
				return true;
			}
			else
				next = next->left;
		}
		else if (key > next->key)
		{
			if(next->right == NULL){
				next->right = &node;
				node.parent = next;
				setBalanced();
				_size++;
				return true;
			}
			else
				next = next->right;
		}
		else
			break;
	}

	return false;
};

template <typename key_type, typename value_type>
void IBST<key_type, value_type>::replaceTNodeInParent(TNode* node, TNode* newTNode){
	TNode* parent = node->parent;

	if(parent){
		if(parent->left == node)
			parent->left = newTNode;
		else
			parent->right = newTNode;
	}
	else
		root = newTNode;

	if(newTNode)
		newTNode->parent = parent;
};

template <typename key_type, typename value_type>
bool IBST<key_type, value_type>::remove(key_type key){
	if(this->root == NULL){
		return false;
	}
	
	TNode* next = this->root;
	TNode* newTNode = NULL;

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
			//TNode* parent = next->parent;

			if((next->left != NULL) && (next->right != NULL)){// delete node with 2 children
				newTNode = leftMostChild(next->right);

				next->key = newTNode->key;
				next->value = next->value;
				
				replaceTNodeInParent(newTNode, newTNode->right);
			}
			else if(next->left || next->right){// delete node with one child
				newTNode =  (next->left == NULL)?next->right:next->left;
				replaceTNodeInParent(next, newTNode);
			}
			else{ // delete a leaf
				replaceTNodeInParent(next, NULL);
			}
			

			setBalanced();
			_size--;
			return true;
		}

	}

	return false;
	
};

template <typename key_type, typename value_type>
ostream& IBST<key_type, value_type>::outputTNode(ostream& output, TNode* node){
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
ostream& operator<< <>(ostream& output, IBST<key_type, value_type>& bstree){
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
	if(root ==NULL || root->left == n1 || root->left == n2 || root->right==n1 || root->right == n2){
		return root;
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

//template<typename key_type, typename value_type>
//typename IBST<key_type, value_type>::TNode* IBST<key_type, value_type>::common_ancestor(TNode* n1, TNode* n2){
//	TNode* ancestor = root;
//
//	while(ancestor){
//		if(n1->key < ancestor->key && n2->key < ancestor->key)
//			ancestor = ancestor->left;
//		else if(n1->key > ancestor->key && n2->key > ancestor->key)
//			ancestor = ancestor->right;
//		else{
//			return ancestor;
//		}
//	}
//
//	return NULL;
//};

template <typename key_type, typename value_type>
typename IBST<key_type, value_type>::TNode* IBST<key_type, value_type>::next(TNode* node)
{
	

	if(node == root || node->right != NULL){
		return leftMostChild(node->right);
	}
	else{
		IBST<key_type, value_type>::TNode* parent;
		while((parent = node->parent) != NULL){
			if(parent-> left == node)
				return parent;

			node = parent;
		}

		return NULL;
	}
};


template <typename key_type, typename value_type>
typename IBST<key_type, value_type>::TNode* IBST<key_type, value_type>::leftMostChild(TNode* node)
{
	IBST<key_type, value_type>::TNode* temp;

	while((temp = node->left) != NULL){
		node = temp;
	}

	return node;
}