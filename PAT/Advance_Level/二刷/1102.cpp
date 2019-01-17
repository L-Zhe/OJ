#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int maxn = 15;
struct node{
	int left, right;
	int layer;
	node(){
		left = right = -1;
	}
}a[maxn];
int n;
bool isRoot[maxn];

void BFS(int root){
	bool flag = false;
	queue<int> q;
	q.push(root);
	a[root].layer = 1;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(flag)	printf(" ");
		printf("%d", top);
		flag = true;
		if(a[top].right != -1){
			q.push(a[top].right);
			a[a[top].right].layer = a[top].layer + 1;
		}
		if(a[top].left != -1){
			q.push(a[top].left);
			a[a[top].left].layer = a[top].layer + 1;
		}
	}
	printf("\n");
}

bool flag = false;
void inOrder(int root){
	if(root == -1)	return;
	inOrder(a[root].right);
	if(flag)	printf(" ");
	flag = true;
	printf("%d", root);
	inOrder(a[root].left);
}


int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		char left, right;
		getchar();
		scanf("%c %c", &left, &right);
		if(left != '-'){
			a[i].left = left - '0';
			isRoot[a[i].left] = true;
		}
		if(right != '-'){
			a[i].right = right - '0';
			isRoot[a[i].right] = true;
		}
	}
	int root;
	for(root = 0; root < n; ++root){
		if(!isRoot[root])	break;
	}
	BFS(root);
	inOrder(root);
	return 0;
	
}
