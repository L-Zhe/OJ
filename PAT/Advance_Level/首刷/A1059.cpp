/*===================================================================================
A1059 Prime Factors (25)£¨25 ·Ö£©
=====================================================================================
Given any positive integer N, you are supposed to find all of its prime factors,
and write them in the format N = p~1~\^k~1~ * p~2~\^k~2~ *¡­*p~m~\^k~m~.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case which gives a positive integer N in the range
of long int.
-------------------------------------------------------------------------------------
Output Specification:
Factor N in the format N = p~1~\^k~1~ * p~2~\^k~2~ *¡­*p~m~\^k~m~, where p~i~'s
are prime factors of N in increasing order, and the exponent k~i~ is the number
of p~i~ -- hence when there is only one p~i~, k~i~ is 1 and must NOT be printed
out.
-------------------------------------------------------------------------------------
Sample Input:
97532468

Sample Output:
97532468=2^2*11*17*101*1291
===================================================================================*/

#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 1e5 + 10;
struct node{
	int p, cnt;
}fac[10];
long N;
int prime[maxn];
bool p[maxn];

void findPrime(){
	int index = 0;
	for(int i = 2; i < maxn; ++i){
		if(p[i] == false){
			prime[index++] = i;
			for(int j = i + i; j < maxn; j += i){
				p[j] = true;
			}
		}
	}
}

int main(){
	findPrime();
	scanf("%ld", &N);\
	long n = N;
	if(n == 1){
		printf("1=1");
		return 0;
	}
	int m = (int)sqrt(1.0 * n);
	int i = 0, j = 0;
	while(prime[i] <= m){
		if(n % prime[i] == 0){
			fac[j].p = prime[i];
			fac[j].cnt = 0;
			while(n % prime[i] == 0){
				fac[j].cnt++;
				n /= prime[i];
			}
			++j;
		}
		++i;
	}
	if(n != 1){
		fac[j].p = n;
		fac[j++].cnt = 1;
	}
	printf("%ld=", N);
	for(int i = 0; i < j; ++i){
		if(i != 0)	printf("*");
		printf("%d", fac[i].p);
		if(fac[i].cnt != 1)
			printf("^%d", fac[i].cnt);
	}
	return 0;
}