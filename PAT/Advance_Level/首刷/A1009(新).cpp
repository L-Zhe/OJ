/*===================================================================================
A1009 Product of Polynomials (25)（25 分）
=====================================================================================
This time, you are supposed to find A*B where A and B are two polynomials.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line
contains the information of a polynomial: K N1 a~N1~ N2 a~N2~ ... NK a~NK~, where
K is the number of nonzero terms in the polynomial, Ni and a~Ni~ (i=1, 2, ..., K)
are the exponents and coefficients, respectively. It is given that 1 <= K <= 10,
0 <= NK < ... < N2 < N1 <=1000.
-------------------------------------------------------------------------------------
Output Specification:
For each test case you should output the product of A and B in one line, with the
same format as the input. Notice that there must be NO extra space at the end of
each line. Please be accurate up to 1 decimal place.
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output
3 3 3.6 2 6.0 1 1.6
===================================================================================*/

#include<iostream>
using namespace std;

const int maxn = 2020;
double a[maxn],b[maxn];
int k;

int main(){
	freopen("data.txt", "r", stdin);
	cin >> k;
	int maxa;
	for(int i = 0; i < k; ++i){
		int index;
		cin >> index;
		if(i == 0)	maxa = index;
		cin >> a[index];
	}
	cin >> k;
	int maxb = 0;
	for(int i = 0; i < k; ++i){
		int index;
		double temp;
		cin >> index >> temp;
		for(int j = 0; j <= maxa; ++j){
			int ne = j + index;
			b[ne] = b[ne] + a[j] * temp;
		}
	}
	int cnt = 0, max = 0;
	for(int i = 0; i < maxn; ++i){
		if(b[i] != 0){
			cnt++;	
			max = i;
		}
	}
	cout << cnt;
	for(int i = max; i >= 0; --i)
		if(b[i] != 0)
			printf(" %d %.1f", i, b[i]);
	return 0;
}