#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int maxn = 410;
int n, k, p;
int power[maxn];
vector<int> ans, temp;
int Msum = 0;
bool flag = false;

int Pow(int a, int n){
	int ans = 1;
	while(n > 0){
		if(n & 1){
			ans *= a;
		}
		a *= a;
		n >>= 1;
	}
	return ans;
}

int init(){
	int MAX = sqrt(n);
	for(int i = 0; i <= MAX; ++i){
		power[i] = Pow(i, p);
	}
	return MAX;
}

void DFS(int index, int total){
	if(temp.size() > k || total > n || index < 1)	return;
	if(total == n){
		if(temp.size() != k)	return;
		int sum = 0;
		for(int i = 0; i < temp.size(); ++i){
			sum += temp[i];
		}
		if(sum > Msum){
			ans = temp;
			Msum = sum;
		}
	}
	temp.push_back(index);
	DFS(index, total + power[index]);
	temp.pop_back();
	DFS(index - 1, total);
}

int main(){
	scanf("%d%d%d", &n, &k, &p);
	int len = init();
	DFS(len, 0);
	if(ans.size() == 0){
		printf("Impossible\n");
	}
	else{
		printf("%d =", n);
		for(int i = 0; i < ans.size(); ++i){
			if(i != 0)	printf(" +");
			printf(" %d^%d", ans[i], p);
		}	
	}
	return 0;
}

