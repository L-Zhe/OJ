/*===================================================================================
A1074 Reversing Linked List (25)（25 分）
=====================================================================================
Given a constant K and a singly linked list L, you are supposed to reverse the links
of every K elements on L. For example, given L being 1→2→3→4→5→6, if K = 3,
then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains the
address of the first node, a positive N (<= 10^5^) which is the total number of
nodes, and a positive K (<=N) which is the length of the sublist to be reversed.
The address of a node is a 5-digit nonnegative integer, and NULL is represented
by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position
of the next node.
-------------------------------------------------------------------------------------
Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line,
and is printed in the same format as in the input.
-------------------------------------------------------------------------------------
Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
===================================================================================*/

#include<iostream>
#include<algorithm>
#include<cstdio> 
using namespace std;

const int maxn = 100010;
struct Node{
	int adress, data, next, rank;
	bool flag;
}node[maxn];

bool cmp1(Node a, Node b){
	if(a.flag == false || b.flag == false)
		return a.flag > b.flag;
	return a.rank < b.rank;
}

bool cmp2(Node a, Node b){
	return a.rank > b.rank;
}

int main(){
	for(int i = 0; i < maxn; ++i){
		node[i].flag = false;
		node[i].rank = maxn;
	}
	int begin = -1, n, k;
	cin >> begin >> n >> k;
	for(int i = 0; i < n; i++){
		int adress;
		scanf("%d", &adress);
		node[adress].adress = adress;
		scanf("%d%d", &node[adress].data, &node[adress].next);
	}
	int rank = 0;
	for(int p = begin; p != -1; p = node[p].next){
		node[p].flag = true;	
		node[p].rank = rank++;
	}
	sort(node, node+maxn, cmp1);
	for(int i = 0; i+k <= rank; i = i+k){
		sort(node+i, node+i+k, cmp2);
	}
	bool b = false;
	for(int i = 0; i < rank; ++i){
		if(b)	cout << endl;
		b = true;
		printf("%05d %d ", node[i].adress, node[i].data);
		if(i != rank-1)
			printf("%05d", node[i+1].adress);
		else
			cout << "-1";
	}
	return 0;
}