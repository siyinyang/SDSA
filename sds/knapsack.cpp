#include <stdio.h>
#include <iostream>

using namespace std;

void _ukp(int w[], int v[], int n, int W){
	int* m = new int[W+1];
	m[0] = 0;
	for(int i = 1; i <= W; i++){
		m[i] = 0;
  		for(int j = 0; j < n; j++){
			if(i >= w[j])
				m[i] = max(m[i], m[i-w[j]]+v[j]);
		}
	}
	cout<<m[W]<<endl;
}

void _01ukp(int w[], int v[], int n, int W){
	int** m = new int*[n+1];
	for(int j = 0; j <= n; j++){
		m[j] = new int[W+1];
		m[j][0] = 0;	
	}
	for(int k = 0; k <= W; k++)
		m[0][k] = 0;
	
	for(int k = 1; k <= n; k++){
		for(int cw = 1; cw <= W; cw++){
			if(cw<w[k-1]){
				m[k][cw] = m[k-1][cw];
			}
			else{
				m[k][cw] = max(m[k-1][cw], m[k-1][cw-w[k-1]]+v[k-1]);
			}
		}	
	}
	cout<<m[n][W]<<endl;
}

int main(){
	//cout<<"hello world!";
	int n = 5;
 	int w[] = {1,2,3,4,5};
	int v[] = {2,3,7,8,100};
	for(int W = 1; W <= 5; W++)
		_ukp(w, v, n, W);

	for(int W = 1; W <=5; W++)
		_01ukp(w, v, n, W);
	
	return 0;
}
