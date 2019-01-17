#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 105;
const int inf = 0x3fffffff;
struct Wait{
	int arrive, need, wait;
	bool VIP, vis;
}newWait;
vector<Wait> q;
int cntTable[maxn], endTime[maxn];
int cntVIP = 0, cnt = 0;
bool isVIP[maxn];

int exTime(int h, int m, int s){
	return h * 3600 + m * 60 + s;
}

int exNeed(int n){
	return min(exTime(2, 0, 0), exTime(0, n, 0));
}

bool cmp(Wait a, Wait b){
	return a.arrive < b.arrive;
}

bool cmp2(Wait a, Wait b){
	int aa = a.arrive + a.wait;
	int bb = b.arrive + b.wait;
	if(aa != bb)
		return aa < bb;
}

void print(int n){
	int h = n / 3600;
	int m = n % 3600 / 60;
	int s = n % 60;
	printf("%02d:%02d:%02d ", h, m, s);
}

int main(){
 	freopen("data.txt", "r", stdin);
	int n, k, m, mNum;
	const int maxTime = exTime(21, 0, 0);
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int h, m, s, need, vip;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &need, &vip);
		newWait.arrive = exTime(h, m, s);
		newWait.need = exNeed(need);
		newWait.VIP = vip;
		if(vip)	++cntVIP;
		q.push_back(newWait);
	}
	scanf("%d%d", &k, &m);
	for(int i = 0; i < m; ++i){
		int temp;
		scanf("%d", &temp);
		isVIP[temp] = true;
	}
	sort(q.begin(), q.end(), cmp);
	fill(endTime, endTime + maxn, exTime(8, 0, 0));
	for(int i = 0; i < n; ++i){
		int u = -1, MIN = inf;
		for(int j = 1; j <= k; ++j){
			if(endTime[j] < MIN)
				MIN = endTime[u = j];
		}
		if(endTime[u] >= maxTime)	break;
		int index;
		int uvip = -1; MIN = inf;
		for(int j = 0; j < k; ++j){
			if(isVIP[j] && endTime[j] < MIN)
				MIN = endTime[uvip = j];
		}
		for(index = 0; index < n; ++index){
			if(!q[index].vis && q[index].VIP)
				break;
		}
		if(uvip != -1 && endTime[u] <= index){
			--cntVIP;
		}else if(!isVIP[u] || cntVIP == 0){
			for(index = 0; index < n; ++index){
				if(q[index].vis == false)
					break;
			}
			if(q[index].VIP){
				--cntVIP;
			}
		}else{
			for(index = 0; index < n; ++index){
				if(q[index].VIP && !q[index].vis)
					break;
			}
			if(q[index].arrive <= endTime[u]){
				--cntVIP;
			}
			else{
				for(index = 0; index < n; ++index){
					if(q[index].vis == false)
						break;
				}
			}
		}

		//
		++cntTable[u];
		++cnt;
		Wait& w = q[index];
		w.vis = true;
		if(endTime[u] <= w.arrive){
			w.wait = 0;
		}else{
			w.wait = endTime[u] - w.arrive;
		}
		endTime[u] = w.arrive + w.need + w.wait;
	}
	sort(q.begin(), q.begin() + cnt, cmp2);
	for(int i = 0; i < cnt; ++i){
		print(q[i].arrive); print(q[i].arrive + q[i].wait); printf("%d\n", (int)round(q[i].wait / 60.0));
	}
	for(int i = 1; i <= k; ++i){
		if(i != 1)	printf(" ");
		printf("%d", cntTable[i]);
	}
	return 0;
}
