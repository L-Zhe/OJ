#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 21;
const int inf = 0x3fffffff;
const int maxTime = 9 * 60;

struct window{
	int popTime, endTime;
	queue<int> q;
}w[maxn];
vector<int> needTime;
int n, m, k, q;
int t[1001];

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &k, &q);
	int inIndex = 0;
	for(int i = 0; i < k; ++i){
		int temp;
		scanf("%d", &temp);
		needTime.push_back(temp);
	}
	for(int i = 0; i < min(n * m, k); ++i){
		w[inIndex % n].q.push(inIndex);
		w[inIndex % n].endTime += needTime[inIndex];
		if(inIndex < n)	w[inIndex].popTime = needTime[inIndex];
		t[inIndex] = w[inIndex % n].endTime;
		inIndex++;
	}
	for(; inIndex < k; ++inIndex){
		int u = -1, MIN = inf;
		for(int i = 0; i < n; ++i){
			if(w[i].popTime < MIN){
				MIN = w[u = i].popTime;
			}
		}
		window& W = w[u];
		W.q.pop();
		W.q.push(inIndex);
		W.endTime += needTime[inIndex];
		W.popTime += needTime[W.q.front()];
		t[inIndex] = W.endTime;
	}
	for(int i = 0; i < q; ++i){
		int index;
		scanf("%d", &index);
		if(t[index - 1] - needTime[index - 1] >= maxTime){
			printf("Sorry\n");
		}else{
			int h = t[index - 1] / 60;
			int m = t[index - 1] % 60;
			printf("%02d:%02d\n", 8 + h, m);	
		}
	}
}

