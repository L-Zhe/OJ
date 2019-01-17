/*===================================================================================
A1102 Invert a Binary Tree (25)（25 分）
=====================================================================================
The following is from Max Howell @twitter:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can't
invert a binary tree on a whiteboard so fuck off.
Now it's your turn to prove that YOU CAN invert a binary tree!
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive
integer N (<=10) which is the total number of nodes in the tree -- and hence the
nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node
from 0 to N-1, and gives the indices of the left and right children of the node.
If the child does not exist, a "-" will be put at the position. Any pair of children
are separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in the first line the level-order, and then in the second
line the in-order traversal sequences of the inverted tree. There must be exactly
one space between any adjacent numbers, and no extra space at the end of the line.
-------------------------------------------------------------------------------------
Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6

Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
===================================================================================*/

#include<iostream>
#include<queue>
#include<string> 
using namespace std;

const int maxn = 20;
int a[maxn][maxn] = {-1};
int n;
bool isRoot[maxn] = { true }; 
bool flag_in = false;

int toNum(string s){
	if(s == "-")
		return -1;
	int ans = 0; 
	for(int i = 0; i < s.length(); ++i)
		ans = ans*10 + (s[i] - '0');
	return ans;
} 

void BFS(int t){
	queue<int> q;
	q.push(t);
	bool flag = false;
	while(!q.empty()){
		if(flag)	cout << " ";
		flag = true;
		int temp = q.front();
		q.pop();
		cout << temp;
		if(a[temp][1] != -1)
			q.push(a[temp][1]);
		if(a[temp][0] != -1)
			q.push(a[temp][0]);
	}
}

void inOrder(int t){
	if(t == -1)
		return;
	inOrder(a[t][1]);
	if(flag_in)	cout << " ";
	flag_in = true;
	cout << t;
	inOrder(a[t][0]);
}

int main(){
	cin >> n;
	string sl, sr;
	fill(isRoot, isRoot+maxn, true);
	for(int i = 0; i < n; ++i){
		cin >> sl >> sr;
		int l = toNum(sl);
		int r = toNum(sr);
		a[i][0] = l;
		a[i][1] = r;
		if(l != -1)
			isRoot[l] = false;
		if(r != -1)
			isRoot[r] = false;
	}
	int root;
	for(int i = 0; i < n; ++i){
		if(isRoot[i]){
			root = i;
			break;
		}
	}
	//for(int i = 0; i < n; ++i)
	//	cout << a[i][0] << " " << a[i][1] << endl;
	
	BFS(root);
	cout << endl;
	inOrder(root);
	return 0;
} 