#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

const int maxs = 26 * 26 * 26 * 10 + 5;
map<string, int> str2int;
vector<int> a[maxs];
int n, k, numC = 0;

int change(string s){
	if(str2int.find(s) == str2int.end()){
		str2int[s] = numC;
		return numC++;
	}else{
		return str2int[s];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	int index, num;
	for(int i = 0; i < k; ++i){
		cin >> index >> num;
		for(int j = 0; j < num; ++j){
			string s;
			cin >> s;
			int u = change(s);
			a[u].push_back(index);
		}
	}
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		int u = change(s);
		sort(a[u].begin(), a[u].end());
		cout << s << " " << a[u].size();
		for(int j = 0; j < a[u].size(); ++j){
			cout << " " << a[u][j];
		}
		cout << endl;
	}
	return 0;
}
