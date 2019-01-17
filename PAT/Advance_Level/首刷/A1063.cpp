/*===================================================================================
A1063 Set Similarity (25)
=====================================================================================
Given two sets of integers, the similarity of the sets is defined to be N~c~/N~t~*100%,
where N~c~ is the number of distinct common numbers shared by the two sets, and
N~t~ is the total number of distinct numbers in the two sets. Your job is to calculate
the similarity of any given pair of sets.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case first gives a positive integer
N (<=50) which is the total number of sets. Then N lines follow, each gives a set
with a positive M (<=10^4^) and followed by M integers in the range [0, 10^9^].
After the input of sets, a positive integer K (<=2000) is given, followed by K lines
of queries. Each query gives a pair of set numbers (the sets are numbered from 1
to N). All the numbers in a line are separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each query, print in one line the similarity of the sets, in the percentage
form accurate up to 1 decimal place.
-------------------------------------------------------------------------------------
Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3

Sample Output:
50.0%
33.3%
===================================================================================*/

#include<iostream>
#include<set>
using namespace std;

const int maxn = 55;

set<int> s[maxn];
int n, m, k;

void cmp(int a, int b){
	int totalNum = s[b].size(), sameNum = 0;
	set<int>::iterator it;
	for(it = s[a].begin(); it != s[a].end(); ++it){
		if(s[b].find(*it) != s[b].end())
			sameNum++;
		else totalNum++;
	}
	printf("%.1f%\n", sameNum * 100.0 / totalNum);
}

int main(){
	ios::sync_with_stdio(false);
	freopen("data.txt", "r", stdin);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> m;
		for(int j = 0; j < m; ++j){
			int temp;
			cin >> temp;
			s[i].insert(temp);
		}
	}
	cin >> k;
	for(int i = 0; i < k; ++i){
		int a, b;
		cin >> a >> b;
		cmp(a, b);
	}
	return 0;
}