/*===================================================================================
A1005 Spell It Right (20)（20 分）
=====================================================================================
Given a non-negative integer N, your task is to compute the sum of all the digits
of N, and output every digit of the sum in English.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case occupies one line which contains
an N (<= 10^100^).
-------------------------------------------------------------------------------------
Output Specification:
For each test case, output in one line the digits of the sum in English words. There
must be one space between two consecutive words, but no extra space at the end of
a line.
-------------------------------------------------------------------------------------
Sample Input:
12345

Sample Output:
one five
===================================================================================*/

#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main(){
	int sum;
	char n[110];
	while(scanf("%s", &n) == 1){
		if(!strcmp(n, "0")){
			cout << "zero";
			continue;
		}
		sum = 0;
		for(int i = 0; i < strlen(n); ++i){
			sum += (n[i] - '0'); 
		}
		stack<int> s;
		while(sum > 0){
			s.push(sum % 10);
			sum /= 10;
		}
		bool flag = false;
		while(!s.empty()){
			int temp = s.top();
			s.pop();
			if(flag)	cout <<" ";
			if(temp == 0)	cout << "zero";
			if(temp == 1)	cout << "one";
			if(temp == 2)	cout << "two";
			if(temp == 3)	cout << "three";
			if(temp == 4)	cout << "four";
			if(temp == 5)	cout << "five";
			if(temp == 6)	cout << "six";
			if(temp == 7)	cout << "seven";
			if(temp == 8)	cout << "eight";
			if(temp == 9)	cout << "nine";
			flag = true;
		}
	}
	return 0;
} 