#include<iostream>
#include<vector>
using namespace std;

const int maxn = 1e4 + 10;
bool p[maxn];
int num[maxn];
int size, n, m;
vector<int> ans;

void findPrime(){
	p[0] = true;
	p[1] = true;
	for(int i = 2; i < maxn; i++){
		if(!p[i]){
			for(int j = i + i; j < maxn; j += i)
				p[j] = true;
		}
	}
}

int main(){
	freopen("data.txt", "r", stdin);
	findPrime();
	scanf("%d%d%d", &size, &n, &m);
	while(p[size])	++size;
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		int q;
		for(q = 0; q < size; ++q){
			int index = (temp + q * q) % size;
			if(num[index] == 0){
				num[index] = temp;
				break;
			}
		}
		if(q == size){
			printf("%d cannot be inserted.\n", temp);
		}
	}
	double cnt = 0;
	for(int i = 0; i < m; ++i){
		int temp;
		scanf("%d", &temp);
		int q;
		for(q = 0; q < size; ++q){
			int index = (temp + q * q) % size;
			if(num[index] == temp || num[index] == 0){
				break;
			}
		}
		cnt += ++q;
	}
	printf("%.1lf", cnt / m);
	return 0;
}
