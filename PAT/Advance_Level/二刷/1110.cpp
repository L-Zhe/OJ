#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 25;
struct node{
	int left, right;
	node(){
		left = right = -1;
	}
}a[maxn];
int n;
int isRoot[maxn];
int lay[maxn];

void BFS(int root){
	queue<int> q;
	q.push(root);
	int len = 1;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		lay[len++] = top;
		if(a[top].left != -1)
			q.push(a[top].left);
		if(a[top].right != -1)
			q.push(a[top].right);
	}
}


bool judge(int root){
	for(int i = 1; i <= n / 2; ++i){
		int index = lay[i];
		if(2 * i <= n && lay[2 * i] != a[index].left)
			return false;
		if(2 * i + 1 <= n && lay[2 * i + 1] != a[index].right)
			return false;
	}
	return true;
}

int change(char* s){
	int ans = 0;
	for(int i = 0; i < strlen(s); ++i){
		ans = ans * 10 + s[i] - '0';
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		char left[3], right[3];
		scanf("%s %s", left, right);
		if(strcmp(left, "-") != 0){
			a[i].left = change(left);
			++isRoot[a[i].left];
		}
		if(strcmp(right, "-") != 0){
			a[i].right = change(right);
			++isRoot[a[i].right];
		}
	}
	int root;
	for(root = 0; root < n; ++root){
		if(isRoot[root] == 0)	break;
	}
	BFS(root);
	if(judge(root))
		printf("YES %d\n", lay[n]);
	else
		printf("NO %d\n", root);
	return 0;
}

