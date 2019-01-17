#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;
struct node{
	string school;
	double tws;
	int cnt;
	node(){
		tws = 0;
		cnt = 0;
	}
}a[maxn];
map<string, int> str2int;
int n, numSchool = 0;

void change(string& s){
	for(int i = 0; i < s.size(); ++i)
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] += ('a' - 'A');
}

int getNum(string s){
	if(str2int.find(s) == str2int.end()){
		str2int[s] = numSchool;
		return numSchool++;
	}else{
		return str2int[s];
	}
}

bool cmp(node a, node b){
	if((int)a.tws != (int)b.tws)
		return (int)a.tws > (int)b.tws;
	else if(a.cnt != b.cnt)
		return a.cnt < b.cnt;
	else
		return a.school < b.school;
}

int main(){
	freopen("data.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> n;
	string s, id;
	double score;
	for(int i = 0; i < n; ++i){
		cin >> id >> score >> s;
		change(s);
		int index = getNum(s);
		a[index].school = s;	
		if(id[0] == 'T')	score *= 1.5;
		else if(id[0] == 'B')	score /= 1.5;
		a[index].tws += score;
		++a[index].cnt;
	}
	sort(a, a + numSchool, cmp);
	int rank = 1;
	cout << numSchool << endl;
	for(int i = 0; i < numSchool; ++i){
		if(i != 0 && (int)a[i].tws != (int)a[i - 1].tws)	rank = i + 1;
		cout << rank << " " << a[i].school << " " << (int)a[i].tws << " " << a[i].cnt << endl;
	}
	return 0;
}



