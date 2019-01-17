#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1e6 + 10;
struct node{
	int id;
	double c, a, m, e;
	int cr, mr, er, ar;
	node(int _id, int _c, int _m, int _e):id(_id), c(_c), m(_m), e(_e){}
};
vector<node> a;
bool Hash[maxn];
int n, m;

bool cmp1(node a, node b){
	return a.c > b.c;
}

bool cmp2(node a, node b){
	return a.m > b.m;
}

bool cmp3(node a, node b){
	return a.e > b.e;
}

bool cmp4(node a, node b){
	return a.a > b.a;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i){
		int id;
		double c, m, e;
		scanf("%d%lf%lf%lf", &id, &c, &m, &e);
		Hash[id] = true;
		node temp(id, c, m, e);
		temp.a = (c + m + e) / 3;
		a.push_back(temp);
	}
	sort(a.begin(), a.end(), cmp1);
	for(int i = 0; i < a.size(); ++i){
		if(i == 0)	a[i].cr = 1;
		else{
			if(a[i].c == a[i - 1].c)	a[i].cr = a[i-1].cr;
			else	a[i].cr = i + 1;
		}
	}
	sort(a.begin(), a.end(), cmp2);
	for(int i = 0; i < a.size(); ++i){
		if(i == 0)	a[i].mr = 1;
		else{
			if(a[i].m == a[i - 1].m)	a[i].mr = a[i-1].mr;
			else	a[i].mr = i + 1;
		}
	}
	sort(a.begin(), a.end(), cmp3);
	for(int i = 0; i < a.size(); ++i){
		if(i == 0)	a[i].er = 1;
		else{
			if(a[i].e == a[i - 1].e)	a[i].er = a[i-1].er;
			else	a[i].er = i + 1;
		}
	}
	sort(a.begin(), a.end(), cmp4);
	for(int i = 0; i < a.size(); ++i){
		if(i == 0)	a[i].ar = 1;
		else{
			if(a[i].a == a[i - 1].a)	a[i].ar = a[i-1].ar;
			else	a[i].ar = i + 1;
		}
	}
	for(int i = 0; i < m; ++i){
		int id;
		scanf("%d", &id);
		if(Hash[id] == false){
			printf("N/A\n");
			continue;
		}
		int j;
		for(j = 0; j < a.size(); ++j){
			if(a[j].id == id)	break;
		}
		int t1 = min(a[j].cr, a[j].mr);
		int t2 = min(a[j].er, a[j].ar);
		int t = min(t1, t2);
		printf("%d ", t);
		if(t == a[j].ar)	printf("A\n");
		else if(t == a[j].cr)	printf("C\n");
		else if(t == a[j].mr)	printf("M\n");
		else	printf("E\n");
	}
	return 0;
}
