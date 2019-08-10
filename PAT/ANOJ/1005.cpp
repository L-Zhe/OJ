#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 35;
int layer[maxn], in[maxn];
bool flag;
int n;


void preOrder(int inL, int inR){
	if(inL > inR)	return;
	int mid, MIN = maxn; 
	for(int i = inL; i <= inR; ++i){
		int u = in[i];
		if(layer[u] < MIN ){
			mid = i;
			MIN = layer[u];
		}
	}
	if(flag)	printf(" ");
	flag = true;
	printf("%d", in[mid]);	
	preOrder(inL, mid - 1);
	preOrder(mid + 1, inR);	
}

void postOrder(int inL, int inR){
	if(inL > inR)	return;
	int mid, MIN = maxn; 
	for(int i = inL; i <= inR; ++i){
		int u = in[i];
		if(layer[u] < MIN ){
			mid = i;
			MIN = layer[u];
		}
	}	
	postOrder(inL, mid - 1);
	postOrder(mid + 1, inR);	
	if(flag)	printf(" ");
	flag = true;
	printf("%d", in[mid]);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		layer[temp] = i;	
	}
	for(int i = 0; i < n; ++i)
		scanf("%d", &in[i]);
	flag = false;
	preOrder(0, n - 1);
	printf("\n");
	flag = false;
	postOrder(0, n - 1);
	return 0;
}
