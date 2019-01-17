/*===================================================================================
A1096 Consecutive Factors (20)£¨20 ·Ö£©
=====================================================================================
Among all the factors of a positive integer N, there may exist several consecutive
numbers. For example, 630 can be factored as 3*5*6*7, where 5, 6, and 7 are the
three consecutive numbers. Now given any positive N, you are supposed to find the
maximum number of consecutive factors, and list the smallest sequence of the consecutive
factors.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case, which gives the integer N (1<N<2^31^).
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in the first line the maximum number of consecutive factors.
Then in the second line, print the smallest sequence of the consecutive factors
in the format "factor[1]*factor[2]*...*factor[k]", where the factors are listed
in increasing order, and 1 is NOT included.
-------------------------------------------------------------------------------------
Sample Input:
630

Sample Output:
3
5*6*7
===================================================================================*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;
vector<int> ans;
ll N;

int main(){
	scanf("%lld", &N);
	int Max = (int)sqrt(1.0 * N);
	for(int i = 2; i <= Max; ++i){
		int j = i;
		ll n = N;
		vector<int> temp;
		while(n % j == 0){
			temp.push_back(j);
			n /= j;
			++j;
		}
		if(temp.size() > ans.size())
			ans = temp;
	}
	if(ans.size() != 0){
		printf("%d\n", ans.size());
		for(int i = 0; i < ans.size(); ++i){
			if(i != 0)	printf("*");
			printf("%d", ans[i]);
		}
	}
	else{
		printf("1\n");
		printf("%lld", N);
	}
	return 0;
}