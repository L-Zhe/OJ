#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 1e4 + 10;
char t[maxn], p[maxn];
bool h[130];

int main(){
	fgets(t, maxn, stdin);
	fgets(p, maxn, stdin);
	t[strlen(t) - 1] = '\0';
	p[strlen(p) - 1] = '\0';
	for(int i = 0; i < strlen(p); ++i){
		h[p[i]] = true;
	}
	for(int i = 0; i < strlen(t); ++i){
		if(h[t[i]])	continue;
		printf("%c", t[i]);
	}
	return 0;
}
