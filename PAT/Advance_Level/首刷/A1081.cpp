/*===================================================================================
A1081 Rational Sum (20)£¨20 ·Ö£©
=====================================================================================
Given N rational numbers in the form "numerator/denominator", you are supposed to
calculate their sum.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case starts with a positive integer
N (<=100), followed in the next line N rational numbers "a1/b1 a2/b2 ..." where
all the numerators and denominators are in the range of "long int". If there is
a negative number, then the sign must appear in front of the numerator.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, output the sum in the simplest form "integer numerator/denominator"
where "integer" is the integer part of the sum, "numerator" < "denominator", and
the numerator and the denominator have no common factor. You must output only the
fractional part if the integer part is 0.
-------------------------------------------------------------------------------------
Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3

Sample Output 1:
3 1/3
------------------
Sample Input 2:
2
4/3 2/3

Sample Output 2:
2
------------------
Sample Input 3:
3
1/3 -1/6 1/8

Sample Output 3:
7/24
===================================================================================*/

#include<iostream>
#include<cmath>
using namespace std;

struct fra{
	int up, down;
};

int gcd(int a, int b){
	return !b ? a : gcd(b, a%b);
}

fra reduc(fra f){
	fra ans = f;
	if(ans.down < 0){
		ans.down *= -1;
		ans.up *= -1;
	}
	if(ans.up == 0){
		ans.down = 1;
	}else{
		int d = gcd(abs(ans.up), abs(ans.down));
		ans.up /= d;
		ans.down /= d;
	}
	return ans;
}

fra add(fra f1, fra f2){
	fra ans;
	ans.up = f1.up * f2.down + f2.up * f1.down;
	ans.down = f1.down * f2.down;
	return reduc(ans);
}

void print(fra f){
	f = reduc(f);
	if(f.down == 1)	printf("%lld", f.up);
	else if(abs(f.up) > f.down){
		printf("%d %d/%d", f.up/f.down, abs(f.up)%f.down, f.down);
	}else{
		printf("%d/%d", f.up, f.down);
	}
	
}

int main(){
	int n;
	scanf("%d", &n);
	fra ans;
	ans.up = 0; ans.down = 1;
	for(int i = 0; i < n; ++i){
		fra temp;
		scanf("%d/%d", &temp.up, &temp.down);
		ans = add(reduc(ans), reduc(temp));
	}
	print(ans);
	return 0;
}