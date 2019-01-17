/*===================================================================================
A1025 PAT Ranking (25)（25 分）
=====================================================================================
Programming Ability Test (PAT) is organized by the College of Computer Science and
Technology of Zhejiang University. Each test is supposed to run simultaneously in
several places, and the ranklists will be merged immediately after the test. Now
it is your job to write a program to correctly merge all the ranklists and generate
the final rank.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains a
positive number N (<=100), the number of test locations. Then N ranklists follow,
each starts with a line containing a positive integer K (<=300), the number of testees,
and then K lines containing the registration number (a 13-digit number) and the
total score of each testee. All the numbers in a line are separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, first print in one line the total number of testees. Then print
the final ranklist in the following format:
registration_number final_rank location_number local_rank
The locations are numbered from 1 to N. The output must be sorted in nondecreasing
order of the final ranks. The testees with the same score must have the same rank,
and the output must be sorted in nondecreasing order of their registration numbers.
-------------------------------------------------------------------------------------
Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85

Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
===================================================================================*/

#include<iostream>
#include<algorithm> 
#include<cstring>
using namespace std;

const int maxn = 30010;
struct node{
	char num[15];
	int score;
	int loc_num;
	int loc_rank;
	int fin_rank;
}n[maxn];
int N, k;

bool cmp(node a, node b){
	if(a.score == b .score)	return  strcmp(a.num, b.num) < 0;
	return a.score > b.score;
}

int main(){
	cin >> N;
	int index = 0;
	for(int i = 1; i <= N; ++i){
		cin >> k;
		int len = 0;
		for(int j = 0; j < k; ++j){
			cin >> n[index].num >> n[index].score;
			n[index++].loc_num = i; 
			len++;
		}
		sort(n + (index - len), n + index, cmp);
		int rank = 1;
		n[0].loc_rank = 1;
		for(int i = index - len; i < index; ++i){
			if(n[i].score < n[i - 1].score)
				rank = i + 1 - (index - len);
			n[i].loc_rank = rank;
		}
	}
	sort(n, n + index, cmp);
	int rank = 1;
	n[0].fin_rank = 1;
	for(int i = 1; i <= index; ++i){
		if(n[i].score < n[i - 1].score)
			rank = i + 1;
		n[i].fin_rank = rank;
	}
	cout << index;
	for(int i = 0; i < index; ++i)
		cout << endl << n[i].num << " " << n[i].fin_rank << " " << n[i].loc_num << " " << n[i].loc_rank;
	return 0;
}