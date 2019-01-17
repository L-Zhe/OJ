/*===================================================================================
A1010 Radix (25)（25 分）
=====================================================================================
Given a pair of positive integers, for example, 6 and 110, can this equation 6 =
110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.
Now for any pair of positive integers N1 and N2, your task is to find the radix
of one number while that of the other is given.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case occupies a line which contains
4 positive integers:\ N1 N2 tag radix\ Here N1 and N2 each has no more than 10 digits.
A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent
the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number
"radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line the radix of the other number so that the
equation N1 = N2 is true. If the equation is impossible, print "Impossible". If
the solution is not unique, output the smallest possible radix.
-------------------------------------------------------------------------------------
Sample Input 1:
6 110 1 10

Sample Output 1:
2
------------------
Sample Input 2:
1 ab 1 2

Sample Output 2:
Impossible
===================================================================================*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;
const int maxn = 50;
int tag, r;
char n1[15], n2[15];

int num(char s){
	if(s >= '0' && s <= '9')
		return s - '0';
	else
		return s - 'a' + 10;
}

ll change(char n[], ll r){
	ll ans = 0;
	for(int i = 0; i < strlen(n); ++i){
		ans = ans * r +num(n[i]);
		if(ans < 0)
			return -1;
	}
	return ans;
}

int binarySearch(ll left, ll right, ll x){
	while(left < right){
		ll mid = left + (right - left) / 2;
		ll num = change(n2, mid);
		if(num == -1 || num >= x)	right = mid;
		else left = mid + 1;
	}
	return left;
}

int main(){
	scanf("%s%s%d%d", n1, n2, &tag, &r);
	if(tag == 2)	swap(n1, n2);
	ll num1 = change(n1, r);
	int radix = 2;
	for(int i = 0; i < strlen(n2); ++i){
		radix = max(radix, num(n2[i]) + 1);
	}
	ll left = radix, right = num1 + 1;
	radix = binarySearch(left, right, num1);
	if(change(n2, radix) == num1)	printf("%lld\n", radix);	
	else	printf("Impossible\n");
	return 0;
}