/*===================================================================================
A1015 Reversible Primes (20)��20 �֣�
=====================================================================================
A reversible prime in any number system is a prime whose "reverse" in that number
system is also a prime. For example in the decimal system 73 is a reversible prime
because its reverse 37 is also a prime.
Now given any two positive integers N (< 10^5^) and D (1 < D <= 10), you are supposed
to tell if N is a reversible prime with radix D.
-------------------------------------------------------------------------------------
Input Specification:
The input file consists of several test cases. Each case occupies a line which contains
two integers N and D. The input is finished by a negative N.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line "Yes" if N is a reversible prime with radix
D, or "No" if not.
-------------------------------------------------------------------------------------
Sample Input:
73 10
23 2
23 10
-2

Sample Output:
Yes
Yes
No
===================================================================================*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

const int maxn = 1e5 + 10;
bool p[maxn];

void findPrime(){
	p[1] = true;
	for(int i = 2; i < maxn; ++i){
		if(p[i] == false){
			for(int j = i + i; j < maxn; j += i){
				p[j] = true;
			}
		}
	}
}

int change(int n, int r){
	int ans = 0;
	vector<int> s;
	while(n > 0){
		s.push_back(n % r);
		n /= r;
	}
	for(int i = 0; i < s.size(); ++i){
		ans = ans * r + s[i];
	}
	return ans;
}

int main(){
	freopen("data.txt", "r", stdin);
	findPrime();
	int n, r;
	scanf("%d", &n);
	while(n >= 0){
		scanf("%d", &r);
		int num = change(n, r);
		//cout << num << endl;
		if(p[num] == false && p[n] == false)
			printf("Yes\n");
		else
			printf("No\n");	
		scanf("%d", &n);
	}
	return 0;
}