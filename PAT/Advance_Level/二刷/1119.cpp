#include<iostream>
#include<queue>
using namespace std;

const int maxn = 35;
int pre[maxn], post[maxn], in[maxn];
int n, len = 0;
bool flag = true;
struct node{
	int data;
	node *left, *right;
	node(int _data){
		data = _data;
		left = right = NULL;
	}
};

bool space = false;

void inOrder(int preL, int preR, int postL, int postR){
	if(preL > preR)	return;
	if(preL == preR){
		in[len++] = pre[preL];
		return;
	}
	int mid;
	for(mid = postL; mid <= postR - 1; ++mid){
		if(post[mid] == pre[preL + 1])	break;
	}
	if(mid == postR - 1)	flag = false;
	int leftNum = mid - postL + 1;
	inOrder(preL + 1, preL + leftNum, postL, mid);
	in[len++] = pre[preL];
	inOrder(preL + leftNum + 1, preR, mid + 1, postR - 1);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", pre + i);
	for(int i = 0; i < n; ++i)
		scanf("%d", post + i);
	inOrder(0, n - 1, 0, n - 1);
	if(flag)	printf("Yes\n");
	else	printf("No\n");
	for(int i = 0; i < len; ++i){
		if(i != 0)	printf(" ");
		printf("%d", in[i]);
	}
	printf("\n");
	return 0;
}
