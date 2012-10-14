#include <queue>
#include "util.h"

using namespace std;


struct _hnode{
	int n;
	char v;
	struct _hnode* left;
	struct _hnode* right;
};

typedef struct _hnode hnode;

class hnode_cmp{
public:
 bool operator() ( hnode*  node1, hnode*  node2){
	 node1->n >  node2->n;
 }
};

/*void print_queue(priority_queue<hnode*, vector<hnode*>, hnode_cmp >  queue){
	while(!queue.empty()){
		hnode* node  = queue.top();
		queue.pop();
		cout<<node->v<<" "<<node->n<<endl;
	}
	cout<<endl;

}*/

void print_tree(hnode* root){
	if(root != NULL){
		cout<<root->v<<" "<<root->n<<endl;
		print_tree(root->left);
		print_tree(root->right);
	}
}

void init_huffman(char* str, int len){
	char freq[256];
	memset(freq, 0, 256);
	int c = 0;
	for(int i = 0; i < len; i++){
		if(!freq[str[i]])c++;
		freq[str[i]]++;
	}
	
		
	priority_queue<hnode*, vector<hnode*>, hnode_cmp > queue;
	int i = 0;
	for(int j = 0; j < 256; j++){
		if(freq[j]>0){
			hnode* node = new hnode;
			node->n = freq[j];
			node->v = j;
			node->left = NULL;
			node->right = NULL;
			queue.push(node); 
		}
	}

	while(queue.size()>1){
		hnode* node1 = queue.top(); queue.pop();
		hnode* node2 = queue.top(); queue.pop();
		
		
		hnode* sum_node = new hnode;
		sum_node->n = node1->n + node2->n;
		sum_node->v = 0;
		sum_node->left = node1;
		sum_node->right = node2;
	
		queue.push(sum_node);
	}	

	hnode* root = queue.top();
	print_tree(root);
}

int main(){
	//char _str[] = "hello I am siyin yang. what are you talking about. believe me\0";
	char _str[] = "hello";
	char* str = _str;
	int len = strlen(str);
	init_huffman(str, len);
	return 0;	
}

