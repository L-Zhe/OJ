#include<iostream>
#include<cstring>
using namespace std;

char s[81];

int main(){
	scanf("%s", s);
	int len = strlen(s);
	int m = (len + 2) / 3;
	int n = len + 2 - 2 * m;
	for(int i = 0; i < m - 1; ++i){
		printf("%c", s[i]);
		for(int j = 0; j < n - 2; ++j){
			printf(" ");
		}
		printf("%c\n", s[len - 1 - i]);
	}
	for(int i = 0; i < n; ++i){
		printf("%c", s[m + i - 1]);
	}
	return 0;
}
