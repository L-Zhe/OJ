#include<iostream>
#include<cstring>
using namespace std;

struct node{
	int a, b, c;
	node(){
		a = 0;
		b = 0;
		c = 0;
	}
};
int n;
char s[32];

node change(char s[]){
	int len = strlen(s) / 2;
	node ans;
	for(int i = 0; i < len; ++i){
		ans.a = ans.a * 10 + s[i] - '0';
	}
	for(int i = len; i < strlen(s); ++i){
		ans.b = ans.b * 10 + s[i] - '0';
	}
	for(int i = 0; i < strlen(s); ++i){
		ans.c = ans.c * 10 + s[i] - '0';
	}
	return ans;
}

bool judge(node ans){
	if(ans.a * ans.b == 0)
		return false; 
	if(ans.c % (ans.a * ans.b))
		return false;
	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s", s);
		node ans = change(s);
		if(judge(ans))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
