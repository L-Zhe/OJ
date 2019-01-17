/*===================================================================================
A1050 String Subtraction (20)£®20 ∑÷£©Ã·Œ 
=====================================================================================
Given two strings S~1~ and S~2~, S = S~1~ - S~2~ is defined to be the remaining
string after taking all the characters in S~2~ from S~1~. Your task is simply to
calculate S~1~ - S~2~ for any given strings. However, it might not be that simple
to do it fast.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case consists of two lines which gives
S~1~ and S~2~, respectively. The string lengths of both strings are no more than
10^4^. It is guaranteed that all the characters are visible ASCII codes and white
space, and a new line character signals the end of a string.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print S~1~ - S~2~ in one line.
-------------------------------------------------------------------------------------
Sample Input:
They are students.
aeiou

Sample Output:
Thy r stdnts.
===================================================================================*/

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

/* const int maxn = 10010;
char s1[maxn], s2[maxn];
char s[130];

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%s%s", s1, s2);
	for(int i = 0; i < strlen(s2); ++i){
		s[s2[i]] = 1;
	}
	for(int i = 0; i < strlen(s1); ++i){
		if(s[s1[i]] == 0)
			printf("%c", s1[i]);
	}
	return 0;
} */

string s1, s2;
char s[128];

int main(){
	//freopen("data.txt", "r", stdin);
	getline(cin, s1);
	getline(cin, s2);
	for(int i = 0; i < s2.size(); ++i){
		s[s2[i]] = 1;
	}
	for(int i = 0; i < s1.size(); ++i){
		if(s[s1[i]] == 0)
			printf("%c", s1[i]);
	}
	return 0;
}