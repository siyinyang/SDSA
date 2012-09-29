#pragma once
#include "ILinkedList.h"
#include "IStack.h"
#include <iostream>
using namespace std;

const int MaxNumEdges = 100;
const int MaxNumVertices = 50;

template <typename VT, typename ET>
class IGraph
{
private:
	ILinkedList<VT> verticesList;
	ET Edge[MaxNumVertices][MaxNumVertices];
	int currentEdges;
	int currentVertices;
	int findVertex(ILinkedList<VT> &l, const VT & vertex){return l.find(vertex);}
	int getVertexPos(const VT & vertex){return findVertex(verticesList, vertex);}

	bool hasPath(const int v1, const int v2, IStack<int>& path);
	void DFS(const int v, bool* visited);
	void DFS(const int v, bool* visited, int depth);
	void IDFS(const int v, int depth);
public:
	IGraph(const int sz = MaxNumVertices);
	IGraph(const char* filePath);
	~IGraph(void);
	//int IGraphEmpty() const{return verticesList.isEmpty();}
	//int graphFull() const{return verticesList.isFull() || currentEdges == MaxNumEdges;}
	int numberOfVertices(){return verticesList.last;}
	int numberOfEdges() {return currentEdges;}
	VT getValue(const int i){return i>=0 && i<currentVertices? verticesList.get(i):NULL;}
	ET getWeight(const int v1, const int v2);
	int getFirstNeighbor(const int v);
	int getNextNeighbor(const int v1, const int v2);
	void insertVertex(const VT & vertex){verticesList.push_back(vertex); currentVertices++;}
	void insertEdgeByInd(const int v1, const int v2, ET weight);
	void insertEdge(const VT v1, const VT v2, ET weight);
	void removeVertex(const int v);
	void removeVertex(const int v1, const int v2);
	bool hasPath(const VT& v1, const VT& v2);
	

	//search functions
	void DFS();
	void BFS();
	void IDFS();// iterative depth first search
	void AStarS(); // heuristic search, A* algorithm

	int MaxRing();
	int MaxRing(int x, int y, int& best_so_far);

	int maxPath(const VT v1, const VT v2);
	int maxPathByInd(const int x, const int y);

	void minPathFloyd();

	friend ostream& operator<< <>(ostream& outpur, const IGraph<VT,ET>& graph);
};

//template <typename VT, typename ET>
//IGraph<VT, ET>::minPathFloyd(){
//    for(int k = 0; k < n to n)
//       for i := 1 to n
//          for j := 1 to n
//             if path[i][k] + path[k][j] < path[i][j] then
//                path[i][j] := path[i][k]+path[k][j];
//                next[i][j] := k;
// }




template <typename VT, typename ET>
IGraph<VT, ET>::IGraph(const char* filePath)
{
	
}

template <typename VT, typename ET>
IGraph<VT, ET>::IGraph(const int sz)
{
	for(int i = 0; i < sz; i++)
		for(int j = 0; j < sz; j++)
			Edge[i][j] = 0;

	currentVertices = 0;
	currentEdges = 0;
}

template <typename VT, typename ET>
IGraph<VT, ET>::~IGraph(void)
{
}

template <typename VT, typename ET>
ET IGraph<VT, ET>::getWeight(const int v1, const int v2)
{
	if (v1 != -1 && v2 != -1)
		return Edge[v1][v2];
	else
		return 0;
}

template <typename VT, typename ET>
int IGraph<VT, ET>::getFirstNeighbor(const int v)
{
	if (v != -1){
		for (int col = 0; col < currentVertices; col++)
			if (Edge[v][col] > 0)
				return col;
	}
	return -1;
}

template <typename VT, typename ET>
int IGraph<VT, ET>::getNextNeighbor(const int v1, const int v2)
{
	if (v1 != -1){
		for (int col = v2+1; col < currentVertices; col++)
			if (Edge[v1][col] > 0)
				return col;
	}
	return -1;
}

template <typename VT, typename ET>
void IGraph<VT, ET>::insertEdgeByInd(const int v1, const int v2, ET weight)
{
	Edge[v1][v2] = weight;
	Edge[v2][v1] = weight;
	currentEdges++;
}

template <typename VT, typename ET>
void IGraph<VT, ET>::insertEdge(const VT v1, const VT v2, ET weight)
{
	int v1ind = getVertexPos(v1);
	int v2ind = getVertexPos(v2);
	if (v1ind >= 0 && v2ind >= 0)
		insertEdgeByInd(v1ind, v2ind, weight);
}

template <typename VT, typename ET>
void IGraph<VT, ET>::DFS(const int v, bool* visited)
{
	cout<<getValue(v)<<' ';
	visited[v] = 1;
	int w = getFirstNeighbor(v);
	while(w != -1){
		if (!visited[w])
			DFS(w,visited);
		w = getNextNeighbor(v,w);
	}
}

template <typename VT, typename ET>
void IGraph<VT, ET>::DFS(const int v, bool* visited, int depth)
{
	if (depth >= 0){
		cout<<getValue(v)<<' ';
		visited[v] = 1;
		int w = getFirstNeighbor(v);
		while(w != -1){
			if (!visited[w])
				DFS(w,visited, depth-1);
			w = getNextNeighbor(v,w);
		}
	}
}

template <typename VT, typename ET>
void IGraph<VT, ET>::DFS()
{
	bool* visited = new bool[currentVertices];
	for(int i = 0; i < currentVertices; i++)
		visited[i] = 0;

	DFS(0,visited);
	delete[] visited;
}

template <typename VT, typename ET>
void IGraph<VT, ET>::IDFS()
{
	int depth = 0;

	IDFS(0, depth);
}

template <typename VT, typename ET>
void IGraph<VT, ET>::IDFS(const int v, int depth)
{
	//cout<< getValue(v)<<endl;
	bool* visited = new bool[currentVertices];
	int allVisited = 0;
	for(int i = 0; i < currentVertices; i++)
		visited[i] = 0;

	IQueue<int> queue;

	while (!allVisited){
		allVisited = 1;
		for(int i = 0; i < currentVertices; i++){
			if(!visited[i]){
				queue.enqueue(i);
				break;
			}
		}

		
		while(!queue.empty()){
			int cur = queue.dequeue();
			cout<<getValue(cur)<<" ";
			visited[cur] = true;

			int ngb = getFirstNeighbor(cur);
			while(ngb != -1){
				if(!visited[ngb])
					queue.enqueue(ngb);

				ngb = getNextNeighbor(cur, ngb);
			}
		}
		

		allVisited = 1;
		for(int i = 0; i < currentVertices; i++)
			allVisited *=  visited[i];
	}

	delete[] visited;
}

template <typename VT, typename ET>
void IGraph<VT, ET>::BFS()
{
	bool* visited = new bool[currentVertices];
	for(int i = 0; i < currentVertices; i++){
		visited[i] = 0;
	}
	
	int arr[] = {0}; 
	IQueue<int> queue(arr);
	visited[0] = 1;
	
	while (!queue.empty())
	{
		int v = queue.dequeue();
		cout<<getValue(v)<<" ";
		//cout<<"after dequeue " <<queue<<endl;

		int w = getFirstNeighbor(v);

		while(w != -1){
			if(!visited[w]){
				visited[w] = 1;
				queue.enqueue(w);
				//cout<<"after enqueue "<<queue<<endl;
			}

			w = getNextNeighbor(v,w);
		}
	}
}


template <typename VT, typename ET>
bool IGraph<VT, ET>::hasPath(const VT& v1, const VT& v2)
{	
	IStack<int> path;
	path.push(verticesList.find(v1));
	bool hPath = hasPath(verticesList.find(v1), verticesList.find(v2), path);
	if(hPath){
		cout<<"The path is ";
		while(!path.empty())
			cout<<getValue(path.pop());
		return true;
	}
	else
		return false;
}

template <typename VT, typename ET>
bool IGraph<VT, ET>::hasPath(const int v1, const int v2, IStack<int>& path)
{
	if(Edge[v1][v2]){
		return true;
	}

	for(int i = 0; i < currentVertices; i++){
		if((path.find(i) == -1) && (i!=v2) && Edge[v1][i]){
			path.push(i);
			if(hasPath(i, v2, path)){
				return true;
			}
			else{
				path.pop();
			}
		}
	}

	return false;
}

template <typename VT, typename ET>
ostream& operator<<<>(ostream& output, const IGraph<VT,ET>& graph){
	for (int i = 0; i < graph.currentVertices; i++){
		for(int j = 0; j < graph.currentVertices; j++){
			output<<graph.Edge[i][j]<<' ';	
		}
		output<<endl;
	}
	return output;
}

template <typename VT, typename ET>
int IGraph<VT, ET>::MaxRing(){
	int best_so_far = 0;
	MaxRing(0, 1, best_so_far);
	return best_so_far;
}


template <typename VT, typename ET>
int IGraph<VT, ET>::MaxRing(int x, int y, int& best_so_far){
    int max_len = 2;
    int second_max_len = -1;
    for (int i = max(x, y) + 1; i < currentVertices; i++) {
      if (Edge[x][i] * Edge[y][i] > 0) {
        int len =  MaxRing(x, i, best_so_far) + MaxRing(y, i, best_so_far) - 1;
        if (len > max_len) {
          second_max_len = max_len;
          max_len = len;
        } else if (len > second_max_len) {
          second_max_len = len;
        }
      }
    }
    best_so_far = max(max_len, best_so_far);
    best_so_far = max(max_len + second_max_len - 2,
                           best_so_far);
    return max_len;
}

template <typename VT, typename ET>
int IGraph<VT, ET>::maxPathByInd(int ind1, int ind2){
	VT* vs = verticesList.toArray();
	int* visited = new int[currentVertices];
	for(int i =0; i<currentVertices; i++)
		visited[i] = 0;
	IStack<VT> stack;
	
	stack.push(vs[ind1]);
	visited[ind1] = 1;

	for(int i = 1; i<currentVertices; i++){
		
	}
}

template <typename VT, typename ET>
int IGraph<VT, ET>::maxPath(const VT v1, const VT v2){
	int v1ind = getVertexPos(v1);
	int v2ind = getVertexPos(v2);
	if (v1ind >= 0 && v2ind >= 0)
		return maxPathByInd(v1ind, v2ind);

	return 0;
}