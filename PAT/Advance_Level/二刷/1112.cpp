#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 130;
const int maxs = 1010;
int k;
bool h[maxn], appear[maxn];
char s[maxs];

int main(){
	fill(h, h + maxn, true);
	fill(appear, appear + maxn, false);
	scanf("%d%s", &k, s);
	int i = 0;
	while(i < strlen(s)){
		int j = i + 1;
		appear[s[i]] = true;
		while(s[j] == s[i])	++j;
		if((j - i) % k)	h[s[i]] = false;
		i = j;
	}
	for(int i = 0; i < strlen(s); ++i){
		if(appear[s[i]] && h[s[i]]){
			printf("%c", s[i]);
			appear[s[i]] = false;
		}
			
	}
	printf("\n");
	for(int i = 0; i < strlen(s); ++i){
		printf("%c", s[i]);
		if(h[s[i]])	i += (k - 1);
	}
	return 0;
}
