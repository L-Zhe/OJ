/*===================================================================================
A1078 Hashing (25)£¨25 ·Ö£©
=====================================================================================
The task of this problem is simple: insert a sequence of distinct positive integers
into a hash table, and output the positions of the input numbers. The hash function
is defined to be "H(key) = key % TSize" where TSize is the maximum size of the hash
table. Quadratic probing (with positive increments only) is used to solve the collisions.
Note that the table size is better to be prime. If the maximum size given by the
user is not prime, you must re-define the table size to be the smallest prime number
which is larger than the size given by the user.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains two
positive numbers: MSize (<=10^4^) and N (<=MSize) which are the user-defined table
size and the number of input numbers, respectively. Then N distinct positive integers
are given in the next line. All the numbers in a line are separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print the corresponding positions (index starts from 0) of the
input numbers in one line. All the numbers in a line are separated by a space, and
there must be no extra space at the end of the line. In case it is impossible to
insert the number, print "-" instead.
-------------------------------------------------------------------------------------
Sample Input:
4 4
10 6 4 15

Sample Output:
0 1 4 -
===================================================================================*/

#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 1e4 + 1;
bool p[maxn], h[maxn];
int m, n;

/* void findPrime(){
	p[0] = true;
	p[1] = true;
	for(int i = 2; i < maxn; ++i){
		if(p[i] == false){
			for(int j = i + i; j < maxn; j += i){
				p[j] = true;
			}
		}
	}
} */

bool isPrime(int n){
	if(n <= 1)
		return false;
	int Max = (int)sqrt(1.0 * n);
	for(int i = 2; i <= Max; ++i){
		if(n % i == 0)
			return false;
	}
	return true;
}

int main(){
	freopen("data.txt", "r", stdin);
	//findPrime();
	scanf("%d%d", &n, &m);
	while(isPrime(n) == false){
		++n;
	}
	for(int i = 0; i < m; ++i){
		int index;
		bool flag = false;
		scanf("%d", &index);
		if(i != 0)	printf(" ");
		for(int j = 0; j < n; ++j){
			if(h[(index + j * j) % n] == false){
				index = (index + j * j) % n;
				flag = true;
				break;
			}
		}
		if(flag){
			printf("%d", index);
			h[index] = true;
		}
		else{
			printf("-");
		}
	}
	return 0;
}