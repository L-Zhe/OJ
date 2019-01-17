/*===================================================================================
A1038 Recover the Smallest Number (30)£®30 ∑÷£©Ã·Œ 
=====================================================================================
Given a collection of number segments, you are supposed to recover the smallest
number from them. For example, given {32, 321, 3214, 0229, 87}, we can recover many
numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different
orders of combinations of these segments, and the smallest number is 0229-321-3214-32-87.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case gives a positive integer N (<=10000)
followed by N number segments. Each segment contains a non-negative integer of no
more than 8 digits. All the numbers in a line are separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print the smallest number in one line. Do not output leading
zeros.
-------------------------------------------------------------------------------------
Sample Input:
5 32 321 3214 0229 87

Sample Output:
22932132143287
===================================================================================*/

#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 10010;
string num[maxn];
string ans;
int n;

bool cmp(string a, string b){
	return a+b < b+a;
}


int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		cin >> num[i];
	sort(num, num + n, cmp);
	for(int i = 0; i < n; ++i)
		ans += num[i];
	while(ans.size() != 0 && ans[0] == '0')
		ans.erase(ans.begin());
	if(ans.size() == 0)
		cout << 0;
	else 
		cout << ans;
	return 0;
}