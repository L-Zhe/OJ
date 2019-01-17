#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

const int maxn = 1e5 + 10;
struct sch{
	int total, tws;
	string id;
	double score;
	sch(){
		total = 0;
		score = 0.0;
	}
}a[maxn];
int n, numSch = 0;
map<string, int> mp;

bool cmp(const sch &a, const sch &b){
	if(a.tws != b.tws)
		return a.tws > b.tws;
	else if(a.total != b.total)
		return a.total < b.total;
	else
		return a.id < b.id;
}

int main(){
	freopen("data.txt", "r", stdin);
	cin >> n;
	for(int i = 0; i < n; ++i){
		string id, s;
		int index;
		double p, score;
		cin >> id >> score >> s;
		for(int j = 0; j < s.size(); ++j){
			if(s[j] >= 'A' && s[j] <= 'Z')
				s[j] += 32;
		}
		if(mp.find(s) == mp.end()){
			mp[s] = numSch;
			index = numSch++;
			a[index].id = s;
		}else{
			index = mp[s];
		}
		if(id[0] == 'B')	p = 1 / 1.5;
		else if(id[0] == 'A')	p = 1;
		else p = 1.5;
		a[index].score += p * score;
		++a[index].total;
	}
	for(int i = 0; i < numSch; ++i){
		a[i].tws = a[i].score;
	}
	sort(a, a + numSch, cmp);
	cout <<  numSch << endl;
	int rank = 0, pre = -1;
	for(int i = 0; i < numSch; ++i){
		if(a[i].tws != pre)	rank = i + 1;
		pre = a[i].tws;
		cout << rank << " " << a[i].id << " " << a[i].tws << " " << a[i].total << endl;
	}
	return 0;
}
