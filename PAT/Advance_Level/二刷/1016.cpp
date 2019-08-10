#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

struct node{
	char id[21];
	int mm, day, hour, min;
	int total;
	bool flag;
	node(char _id[21], int _mm, int _day, int _hour, int _min, char f[21]){
		strcpy(id, _id);
		mm = _mm;
		day = _day;
		hour = _hour;
		min = _min;
		if(!strcmp(f, "on-line"))	flag = true;
		else	flag = false;
		total = ((day * 24) + hour) * 60 + min;
	}
};
vector<node> a;
int rate[24];
int n;

bool cmp(node a, node b){
	if(strcmp(a.id, b.id) != 0)
		return strcmp(a.id, b.id) < 0;
	else
		return a.total < b.total;
}

double print(int i){
	double ans = 0;
	int cnt = 0;
	int d1 = a[i].day, d2 = a[i + 1].day;
	int h1 = a[i].hour, h2 = a[i + 1].hour;
	int m1 = a[i].min, m2 = a[i + 1].min;
	printf("%02d:%02d:%02d %02d:%02d:%02d ", d1, h1, m1, d2, h2, m2);
	while(d1 != d2 || h1 != h2 || m1 != m2){
		++cnt;
		ans += rate[h1];
		if(++m1 == 60){
			m1 = 0;
			++h1;
			if(h1 == 24){
				h1 = 0;
				++d1;
			}
		}
	}
	ans /= 100;
	printf("%d $%.2f\n", cnt,  ans);
	return ans;
}

int main(){
	freopen("data.txt", "r", stdin);
	for(int i = 0; i < 24; ++i){
		scanf("%d", rate + i);
	}
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		char id[21], f[10];
		int mm, day, hour, min;
		scanf("%s%d:%d:%d:%d%s", id, &mm, &day, &hour, &min, f);
		//node temp(id, mm, day, hour, min, f);
		a.push_back(node{id, mm, day, hour, min, f});
	}
	sort(a.begin(), a.end(), cmp);
//	for(int i = 0; i < a.size(); ++i){
//		printf("%s", a[i].id);
//		cout << " " << a[i].mm << ":" << a[i].day << ":" << a[i].hour << ":" << a[i].min << " " << a[i].flag << endl;
//
//	}
	int i = 0;
	while(i < a.size()){
		if(a[i].flag == true && i != a.size() - 1 && a[i + 1].flag == false && strcmp(a[i].id, a[i + 1].id) == 0){
			i += 2;
		}else{
			a.erase(a.begin() + i);
		}
	}
	double total_cost = 0;
	i = 0;
	while(i < a.size()){
		total_cost = 0;
		bool flag = true;
		printf("%s %02d\n", a[i].id, a[i].mm);
		while(flag || i < a.size() && strcmp(a[i].id, a[i - 1].id) == 0){
			total_cost += print(i);
			flag = false;
			i += 2;
		}
		printf("Total amount: $%.2f\n", total_cost);
	}
	return 0;
}
