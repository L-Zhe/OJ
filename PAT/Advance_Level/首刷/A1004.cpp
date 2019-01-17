/*===================================================================================
A1004 Counting Leaves (30)（30 分）
=====================================================================================
A family hierarchy is usually presented by a pedigree tree. Your job is to count
those family members who have no child.
-------------------------------------------------------------------------------------
Input
Each input file contains one test case. Each case starts with a line containing
0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf
nodes. Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number
of its children, followed by a sequence of two-digit ID's of its children. For the
sake of simplicity, let us fix the root ID to be 01.
-------------------------------------------------------------------------------------
Output
For each test case, you are supposed to count those family members who have no child
for every seniority level starting from the root. The numbers must be printed in
a line, separated by a space, and there must be no extra space at the end of each
line.
-------------------------------------------------------------------------------------
The sample case represents a tree with only 2 nodes, where 01 is the root and 02
is its only child. Hence on the root 01 level, there is 0 leaf node; and on the
next level, there is 1 leaf node. Then we should output "0 1" in a line.
Sample Input
2 1
01 1 02

Sample Output
0 1
===================================================================================*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 110;
struct node{
	int layer;
	vector<int> child;
}n[maxn];
int N, M, maxLayer = 0;
int num[maxn], noChild[maxn];

void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int index = q.front();
		q.pop();
		if(n[index].layer > maxLayer)
			maxLayer = n[index].layer; 
		if(n[index].child.size() == 0)
			noChild[n[index].layer]++;
		for(int i = 0; i < n[index].child.size(); ++i){
			int temp = n[index].child[i];
			n[temp].layer = n[index].layer + 1;
			q.push(temp);
		}
	}
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < M; ++i){
		int ID, k, temp;
		cin >> ID >> k;
		for(int j = 0; j < k; ++j){
			cin >> temp;
			n[ID].child.push_back(temp);
		}
	}
	n[1].layer = 1;
	BFS(1);
	bool flag = false;
	for(int i = 1; i <= maxLayer; ++i){
		if(flag)
			cout << " ";
		flag = true;
		cout << noChild[i];
	}
	return 0;
}