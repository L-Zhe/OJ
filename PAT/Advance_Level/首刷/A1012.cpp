/*===================================================================================
A1012 The Best Rank (25)£¨25 ·Ö£©
=====================================================================================
To evaluate the performance of our first year CS majored students, we consider their
grades of three courses only: C - C Programming Language, M - Mathematics (Calculus
or Linear Algebra), and E - English. At the mean time, we encourage students by
emphasizing on their best ranks -- that is, among the four ranks with respect to
the three courses and the average grade, we print the best rank for each student.
For example, The grades of C, M, E and A - Average of 4 students are given as the
following:
StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the
best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in
English, and the last one in average.
-------------------------------------------------------------------------------------
Input
Each input file contains one test case. Each case starts with a line containing
2 numbers N and M (<=2000), which are the total number of students, and the number
of students who would check their ranks, respectively. Then N lines follow, each
contains a student ID which is a string of 6 digits, followed by the three integer
grades (in the range of [0, 100]) of that student in the order of C, M and E. Then
there are M lines, each containing a student ID.
-------------------------------------------------------------------------------------
Output
For each of the M students, print in one line the best rank for him/her, and the
symbol of the corresponding rank, separated by a space.
The priorities of the ranking methods are ordered as A > C > M > E. Hence if there
are two or more ways for a student to obtain the same best rank, output the one
with the highest priority.
If a student is not on the grading list, simply output "N/A".
-------------------------------------------------------------------------------------
Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999

Sample Output
1 C
1 M
1 E
1 A
3 A
N/A
===================================================================================*/

/*===================================================================================
A1012 The Best Rank (25)£¨25 ·Ö£©
=====================================================================================
To evaluate the performance of our first year CS majored students, we consider their
grades of three courses only: C - C Programming Language, M - Mathematics (Calculus
or Linear Algebra), and E - English. At the mean time, we encourage students by
emphasizing on their best ranks -- that is, among the four ranks with respect to
the three courses and the average grade, we print the best rank for each student.
For example, The grades of C, M, E and A - Average of 4 students are given as the
following:
StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the
best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in
English, and the last one in average.
-------------------------------------------------------------------------------------
Input
Each input file contains one test case. Each case starts with a line containing
2 numbers N and M (<=2000), which are the total number of students, and the number
of students who would check their ranks, respectively. Then N lines follow, each
contains a student ID which is a string of 6 digits, followed by the three integer
grades (in the range of [0, 100]) of that student in the order of C, M and E. Then
there are M lines, each containing a student ID.
-------------------------------------------------------------------------------------
Output
For each of the M students, print in one line the best rank for him/her, and the
symbol of the corresponding rank, separated by a space.
The priorities of the ranking methods are ordered as A > C > M > E. Hence if there
are two or more ways for a student to obtain the same best rank, output the one
with the highest priority.
If a student is not on the grading list, simply output "N/A".
-------------------------------------------------------------------------------------
Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999

Sample Output
1 C
1 M
1 E
1 A
3 A
N/A
===================================================================================*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 2010;
struct node{
	string id;
	int a, c, m, e;
	int ra, rc, re, rm;
};
vector<node> ans; 
int N, M;
//cmp
bool cmpa(node a, node b){
	return a.a > b.a;
}

bool cmpc(node a, node b){
	return a.c > b.c;
}

bool cmpe(node a, node b){
	return a.e > b.e;
}

bool cmpm(node a, node b){
	return a.m > b.m;
}

int fmin(int a, int b, int c, int d){
	int m = min(a, b), n = min(c, d);
	return min(m, n);
}
//Rank
void Rank(){
	sort(ans.begin(), ans.end(), cmpa);
	for(int i = 0; i < ans.size(); ++i){
		if(i > 0 && ans[i].a == ans[i - 1].a)
			ans[i].ra = ans[i - 1].ra;
		else ans[i].ra = i + 1;
	}
	sort(ans.begin(), ans.end(), cmpc);
	for(int i = 0; i < ans.size(); ++i){
		if(i > 0 && ans[i].c == ans[i - 1].c)
			ans[i].rc = ans[i - 1].rc;
		else ans[i].rc = i + 1;
	}
	sort(ans.begin(), ans.end(), cmpe);
	for(int i = 0; i < ans.size(); ++i){
		if(i > 0 && ans[i].e == ans[i - 1].e)
			ans[i].re = ans[i - 1].re;
		else ans[i].re = i + 1;
	}
	sort(ans.begin(), ans.end(), cmpm);
	for(int i = 0; i < ans.size(); ++i){
		if(i > 0 && ans[i].m == ans[i - 1].m)
			ans[i].rm = ans[i - 1].rm;
		else ans[i].rm = i + 1;
	}
}
//Find
int Find(string s){
	for(int i = 0; i < ans.size(); ++i)
		if(ans[i].id == s)
			return i;
}

int main(){
	//freopen("data.txt", "r", stdin);
	cin >> N >> M;
	for(int i = 0; i < N; ++i){
		node temp;
		string id;
		int c, m, e;
		cin >> id >> c >> m >> e;
		temp.id = id;
		temp.c = c;
		temp.m = m;
		temp.e = e;
		temp.a = (c + m + e) / 3;
		ans.push_back(temp);
	}
	Rank();
	/* 
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i].id << " " << ans[i].rc << " " << ans[i].rm << " " <<\
		ans[i].re << " " << ans[i].ra << endl; 
	*/
	for(int i = 0; i < M; ++i){
		string s;
		cin >> s;
		int index = Find(s);
		if(index == ans.size()){
			cout << "N/A" << endl;
			continue;
		}
		int temp = fmin(ans[index].rc, ans[index].ra, ans[index].rm, ans[index].re);
		cout << temp << " ";
		if(temp == ans[index].ra)	cout << "A";
		else if(temp == ans[index].rc)	cout << "C";
		else if(temp == ans[index].rm)	cout << "M";
		else	cout << "E";
		cout << endl;
	}
	return 0;
}

