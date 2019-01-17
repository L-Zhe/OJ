#include<iostream>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;

const int maxn= 1e5 + 10;
const int maxB = 317;
int block[maxB], table[maxn];
stack<int> s;

void PeekMedian(){
	if(s.empty()){
		printf("Invalid\n");
		return;
	}
	int k;
	if(s.size() & 1)	k = (s.size() + 1) / 2;
	else	k = s.size() / 2;
	int sum = 0;
	int index = 0;
	while(sum + block[index] < k){
		sum += block[index++];
	}
	int num = index * maxB;
	while(sum + table[num] < k){
		sum += table[num++];
	}
	printf("%d\n", num);
}

void Push(int x){
	s.push(x);
	++block[x / maxB];
	++table[x];
}

void Pop(){
	if(s.empty()){
		printf("Invalid\n");
		return;
	}
	int x = s.top();
	printf("%d\n", x);
	s.pop();
	--block[x /maxB];
	--table[x];
}

int main(){
	freopen("data.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; ++i){
		char cmd[11];
		scanf("%s", cmd);
		if(strcmp(cmd, "PeekMedian") == 0){
			PeekMedian();
		}else if(strcmp(cmd, "Pop") == 0){
			Pop();
		}else{
			int num;
			scanf("%d", &num);
			Push(num);
		}
	}
	return 0;
}
