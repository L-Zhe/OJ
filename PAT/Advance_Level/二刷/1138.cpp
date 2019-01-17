#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> pre, in;
bool flag = true;

void postOrder(int preL, int preR, int inL, int inR){
	if(preL > preR || !flag)	return;
	int mid;
	for(mid = inL; mid <= inR; ++mid){
		if(in[mid] == pre[preL])	break;
	}
	int leftNum = mid - inL;
	postOrder(preL + 1, preL + leftNum, inL, mid - 1);
	postOrder(preL + leftNum + 1, preR, mid + 1, inR);
	if(flag)		printf("%d", pre[preL]);
	flag = false;
}

int main(){
	scanf("%d", &n);
	pre.resize(n);
	in.resize(n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &pre[i]);
	for(int i = 0; i < n; ++i)
		scanf("%d", &in[i]);
	postOrder(0, n - 1, 0, n - 1);
	return 0;
}
