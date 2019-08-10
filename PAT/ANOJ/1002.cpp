#include<iostream>
#include<cstring>
using namespace std;

int change(char* s){
	if(strcmp(s, "one") == 0)	return 1;
	else if(strcmp(s, "two") == 0)	return 2;
	else if(strcmp(s, "three") == 0)	return 3;
	else if(strcmp(s, "four") == 0)	return 4;
	else if(strcmp(s, "five") == 0)	return 5;
	else if(strcmp(s, "six") == 0)	return 6;
	else if(strcmp(s, "seven") == 0)	return 7;
	else if(strcmp(s, "eight") == 0)	return 8;
	else if(strcmp(s, "nine") == 0)	return 9;
	else return 0;
}

bool judge(int a[]){
	if(a[0] + a[1] > a[2] && a[1] + a[2] > a[0] && a[2] + a[0] > a[1])
		return true;
	else
		return false;
}

int main(){
	int a[3];
	for(int i = 0; i < 3; ++i){
		int k, ans = 0;
		char s[7];
		scanf("%d", &k);
		for(int j = 0; j < k; ++j){
			scanf("%s", s);
			ans = ans * 10 + change(s);
		}
		a[i] = ans;
	}
	if(judge(a))	printf("YES");
	else	printf("NO");
	return 0;
}
