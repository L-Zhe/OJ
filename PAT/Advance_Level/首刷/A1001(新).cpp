/*===================================================================================
A1001 A+B Format (20)（20 分）
=====================================================================================
Calculate a + b and output the sum in standard format -- that is, the digits must
be separated into groups of three by commas (unless there are less than four digits).
-------------------------------------------------------------------------------------
Input
Each input file contains one test case. Each case contains a pair of integers a
and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.
-------------------------------------------------------------------------------------
Output
For each test case, you should output the sum of a and b in one line. The sum must
be written in the standard format.
-------------------------------------------------------------------------------------
Sample Input
-1000000 9

Sample Output
-999,991
===================================================================================*/

#include<iostream>
#include<stack>
using namespace std;

stack<char> s;
int a, b;

int main(){
	cin >> a >> b;
	int num = a + b;
	if(num == 0){
		cout << "0";
		return 0;
	}
	if(num < 0){
		cout << '-';
		num *= -1;
	}
	int cnt = 0;
	while(num > 0){
		s.push('0' + num % 10);
		num /= 10;
		cnt++;
		if(cnt == 3){
			cnt = 0;
			s.push(',');
		}
	}
	if(s.top() == ',')
		s.pop();
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
	return 0;
}