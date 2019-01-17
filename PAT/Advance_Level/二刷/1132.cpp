#include<iostream>
#include<cstring>
using namespace std;

int n;
char s[35];

void judge(char* s){
	int num1 = 0, num2 = 0, num = 0;
	for(int i = 0; i < strlen(s); ++i)
		num = num * 10 + s[i] - '0';
	for(int i = 0; i < strlen(s) / 2; ++i)
		num1 = num1 * 10 + s[i] - '0';
	for(int i = strlen(s) / 2; i < strlen(s); ++i)
		num2 = num2 * 10 + s[i] - '0';
	if(num1 * num2 != 0 && num % (num1 * num2) == 0)	printf("Yes\n");
	else	printf("No\n");
} 

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s", s);
		judge(s);
	}
	return 0;
}
