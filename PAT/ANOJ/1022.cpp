#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 110;
const int maxv = 130;
int n, ans = 0;
char s[maxn];
bool h[maxv];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s", s);
		memset(h, 0, sizeof(h));
		for(int i = 0; i < strlen(s); ++i){
			if(((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) && !h[s[i]]){
				++ans;
				h[s[i]] = true;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
