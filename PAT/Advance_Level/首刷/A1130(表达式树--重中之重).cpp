#include<iostream>
using namespace std;

const int maxn = 25;
struct node{
	char s[11];
	int left, right;	
}t[maxn];
int n, root[maxn];

void inOrder(int root, int depth){
	if(root == -1){
		return;
	}
	if(!(depth == 0 || t[root].left == -1 && t[root].right == -1))
		printf("(");
	inOrder(t[root].left, depth + 1); 
	printf("%s", t[root].s);
	inOrder(t[root].right, depth + 1);
	if(!(depth == 0 || t[root].left == -1 && t[root].right == -1))
		printf(")");
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int left, right;
		scanf("%s%d%d", t[i].s, &left, &right);
		t[i].left = left;
		t[i].right = right;
		++root[left];
		++root[right];
	}
	int index;
	for(index = 1; index <= n; ++index){
		if(root[index] == 0)
			break;
	}
	inOrder(index, 0);
	return 0;
}
