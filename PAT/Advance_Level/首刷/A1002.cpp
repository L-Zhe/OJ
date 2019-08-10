/*===================================================================================
A1002 A+B for Polynomials (25)（25 分）
=====================================================================================
This time, you are supposed to find A+B where A and B are two polynomials.
-------------------------------------------------------------------------------------
Input
Each input file contains one test case. Each case occupies 2 lines, and each line
contains the information of a polynomial: K N1 a~N1~ N2 a~N2~ ... NK a~NK~, where
K is the number of nonzero terms in the polynomial, Ni and a~Ni~ (i=1, 2, ..., K)
are the exponents and coefficients, respectively. It is given that 1 <= K <= 10，0
<= NK < ... < N2 < N1 <=1000.
-------------------------------------------------------------------------------------
Output
For each test case you should output the sum of A and B in one line, with the same
format as the input. Notice that there must be NO extra space at the end of each
line. Please be accurate to 1 decimal place.
-------------------------------------------------------------------------------------
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output
3 2 1.5 1 2.9 0 3.2
===================================================================================*/

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn = 1010;
double p[maxn];
int main() {
	int k = 0;
	int exp;
	double cop;
	int len = 0, maxexp = 0;
	memset(p, 0, sizeof(p));
	while (scanf_s("%d", &k) == 1) {
		for (int i = 1; i <= 2; ++i) {
			for (int j = 1; j <= k; ++j) {
				cin >> exp >> cop;
				if (p[exp] == 0)	len++;
				if (exp > maxexp)	maxexp = exp;
				p[exp] += cop;
				if (p[exp] == 0)	len--;
			}
			if(i == 1)	cin >> k;
		}
		cout << len;
		for (int i = maxexp; i >= 0; --i)
			if (p[i] != 0)
				printf(" %d %.1f", i, p[i]);
	}
	system("pause");
	return 0;
}