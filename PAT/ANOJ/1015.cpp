#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

const int maxn = 35;
struct node{
	char s[3];
	int left, right;
	node(){
		left = right = -1;
	}
}a[maxn];
int n;
bool h[maxn]; 

int change(char* s){
	int ans = 0;
	for(int i = 0; i < strlen(s); ++i){
		ans = ans * 10 + s[i] - '0';
	}
	return ans;
}

int root;
int ans = 0;
void inOrder(int index){
	if(index == -1)	return;
	if(index != root && a[index].left != -1 && a[index].right != -1)	printf("(");
	if(a[index].left != -1)
		inOrder(a[index].left);
	printf("%s", a[index].s);
	if(a[index].right != -1)
		inOrder(a[index].right);
	if(index != root && a[index].left != -1 && a[index].right != -1)	printf(")");
}

double cal(int index){
	if(a[index].left == -1 && a[index].right == -1)	
		return change(a[index].s);
	if(strcmp(a[index].s, "+") == 0)	return cal(a[index].left) + cal(a[index].right);
	if(strcmp(a[index].s, "-") == 0)	return cal(a[index].left) - cal(a[index].right);
	if(strcmp(a[index].s, "*") == 0)	return cal(a[index].left) * cal(a[index].right);
	if(strcmp(a[index].s, "/") == 0)	return cal(a[index].left) / cal(a[index].right);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s", a[i].s);
	}
	char left[3], right[3];
	for(int i = 0; i < n; ++i){
		scanf("%s %s", left, right);
		if(strcmp(left, "-") != 0){
			int temp = change(left);
			a[i].left = temp;
			h[temp] = true;
		}
		if(strcmp(right, "-") != 0){
			int temp = change(right);
			a[i].right = temp;
			h[temp] = true;
		}
	}
	for(root = 0; root < n; ++root){
		if(!h[root])	break;
	}
	inOrder(root);
	printf(" %.2f", cal(root));
	return 0;
}
