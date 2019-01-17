/*===================================================================================
A1073 Scientific Notation (20)（20 分）
=====================================================================================
Scientific notation is the way that scientists easily handle very large numbers
or very small numbers. The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+
which means that the integer portion has exactly one digit, there is at least one
digit in the fractional portion, and the number and its exponent's signs are always
provided even when they are positive.
Now given a real number A in scientific notation, you are supposed to print A in
the conventional notation while keeping all the significant figures.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, there is one line containing
the real number A in scientific notation. The number is no more than 9999 bytes
in length and the exponent's absolute value is no more than 9999.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line the input number A in the conventional notation,
with all the significant figures kept, including trailing zeros,
-------------------------------------------------------------------------------------
Sample Input 1:
+1.23400E-03

Sample Output 1:
0.00123400
------------------
Sample Input 2:
-1.2E+10

Sample Output 2:
-12000000000
===================================================================================*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string s;
vector<char> num;
int exp = 0;

int main(){
	cin >> s;
	int i;
	if(s[0] == '-')	cout << '-';
	for(i = 1; i < s.size(); ++i){
		if(s[i] == 'E')	break;
		if(s[i] == '.')	continue;
		num.push_back(s[i]);
	}
	int index = 1;
	if(s[++i] == '-')	index = -1;
	for(++i; i < s.size(); ++i){
		exp = exp * 10 + s[i] - '0';
	}
	exp *= index;
	if(exp < 0){
		exp *= -1;
		for(int i = 0; i < exp; ++i){
			cout << 0;
			if(i == 0)	cout << ".";
		}
		for(int i = 0; i < num.size(); ++i)
			cout << num[i];
	}
	else{
		if(exp <= num.size() - 2){
			for(int i = 0; i < num.size(); ++i){
				cout << num[i];
				if(exp == i)	cout << ".";
			}
		}
		else{
			for(int i = 0; i < num.size(); ++i)
				cout << num[i];
			for(int i = 0; i < exp - num.size() + 1; ++i)
				cout << 0;
		}
	}
	return 0;
}