#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 1010;
struct Node{
	string name, ID;
	int score;
}node[maxn];
int n;

bool cmp(Node a, Node b){
	return a.score > b.score;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> node[i].name >> node[i].ID >> node[i].score; 
	}
	sort(node, node + n, cmp);
	cout << node[0].name << " " << node[0].ID << endl;
	cout << node[n-1].name << " " << node[n-1].ID;
	return 0;
}