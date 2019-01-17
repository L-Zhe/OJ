/*===================================================================================
A1144 The Missing Number（20 分）
=====================================================================================
Given N integers, you are supposed to find the smallest positive integer that is
NOT in the given list.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive
integer N (<=10^
^5). Then N integers are given in the next line, separated by spaces. All the numbers
are in the range of int.
-------------------------------------------------------------------------------------
Output Specification:
Print in a line the smallest positive integer that is missing from the input list.
-------------------------------------------------------------------------------------
Sample Input:
10
5 -25 9 6 1 3 4 2 5 17

Sample Output:
7
===================================================================================*/

#include<iostream>
using namespace std;

const int maxn = 100010;
int n;
int a[maxn];

int main(){
	cin >> n;
	for(int i = 0; i < maxn; ++i)
		a[i] = 0;
	for(int i = 0; i < n; ++i){
		int temp;
		cin >> temp;
		if(temp > 0 && temp < maxn)
			a[temp]++;
	}
	for(int i = 1; i < maxn; ++i){
		if(a[i] == 0){
			cout << i;
			break;
		}
	}
	return 0;
}