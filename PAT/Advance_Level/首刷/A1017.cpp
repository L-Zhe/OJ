#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int k = 111;
const int inf = 0x3fffffff;
struct customer{
	int comeTime, serveTime;
}newcustomer;
vector<customer> custom;
int changeT(int h, int m, int s){
	return h * 3600 + m * 60 + s;
}

bool cmp(customer a, customer b){
	return a.comeTime < b.comeTime;
}
int endTime[k];
int main(){
	freopen("data.txt", "r", stdin);
	int c, w, totTime = 0;
	int stTime = changeT(8, 0, 0);
	int edTime = changeT(17, 0, 0);
	scanf("%d%d", &c, &w);
	for(int i = 0; i < w; ++i)	endTime[i] = stTime;
	for(int i = 0; i < c; ++i){
		int h, m, s, serveTime;
		scanf("%d:%d:%d %d", &h, &m, &s, &serveTime);
		int comeTime = changeT(h, m, s);
		if(comeTime > edTime)	continue;
		newcustomer.comeTime = comeTime;
		newcustomer.serveTime = serveTime <= 60 ? serveTime * 60 : 3600;
		custom.push_back(newcustomer);
	}
	sort(custom.begin(), custom.end(), cmp);
	for(int i = 0; i < custom.size(); ++i){
		int index = -1, minEdTime = inf;
		for(int j = 0; j < w; ++j){
			if(endTime[j] < minEdTime)
				minEdTime = endTime[index = j];
		}
		if(endTime[index] <= custom[i].comeTime){
			endTime[index] = custom[i].comeTime + custom[i].serveTime;
		}else{
			totTime += (endTime[index] - custom[i].comeTime);
			endTime[index] += custom[i].serveTime;
		}
	}
	if(custom.size() == 0)	printf("0.0");
	else	printf("%.1f", totTime / 60.0 / custom.size());
	return 0;
}
