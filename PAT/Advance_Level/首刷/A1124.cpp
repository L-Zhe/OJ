#include<iostream>
#include<cstring>
#include<map>
using namespace std;

const int maxn = 1e3 + 10;
char s[maxn][21];
int m, n, k, numPerson = 0;
bool Hash[maxn];
map<string, int> str2int;

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d%d", &m, &n, &k);
	for(int i = 1; i <= m; ++i){
		scanf("%s", s[i]);
		if(str2int.find(s[i]) == str2int.end()){
			str2int[s[i]] = numPerson++;
		}
	}
	int cnt = 0;
	bool flag = false;
	for(int i = k; i <= m; ++i){
		if(cnt % n == 0){
			int index = str2int[s[i]];
			if(!Hash[index]){
				Hash[index] = true;
				printf("%s\n", s[i]);
				++cnt;
				flag = true;
			}
		}else{
			++cnt;
		}
	}
	if(!flag)
		printf("Keep going...\n");
	return 0;
}
