#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 25;
const int maxs = 15;
struct node{
	char s[maxs];
	int left, right;
}tree[maxn];
bool isRoot[maxn];
int n, root;

void inOrder(int index){
	if(index == -1)	return;
	if(index != root && (tree[index].left != -1 || tree[index].right != -1))
		printf("(");
	if(tree[index].left != -1)	inOrder(tree[index].left);
	printf("%s", tree[index].s);
	if(tree[index].right != -1) inOrder(tree[index].right);
	if(index != root && (tree[index].left != -1 || tree[index].right != -1))
		printf(")");	
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%s %d %d", tree[i].s, &tree[i].left, &tree[i].right);
		if(tree[i].left != -1)	isRoot[tree[i].left] = true;
		if(tree[i].right != -1)	isRoot[tree[i].right] = true;
	}
	for(root = 1; root <= n; ++root){
		if(!isRoot[root])	break;
	}
	inOrder(root);
	return 0;
}
