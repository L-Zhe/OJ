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

const int maxn = 1010;
const int maxnn = 2010;
double a[maxn] = {0}, b[maxn] = {0}, c[maxnn] = {0};
int k1, k2, max1 = -1, max2 = -1, max3 = -1;

int main(){
	cin >> k1;
	for(int i = 0; i < k1; ++i){
		int index;
		cin >> index;
		cin >> a[index];
		if(index > max1)	max1 = index;
	}
	cin >> k2;
	for(int i = 0; i < k2; ++i){
		int index;
		cin >> index;
		cin >> b[index];
		if(index > max2)	max2 = index;
	}
	
	
	int count = 0;
	for(int i = 0; i <= max1; ++i){
		for(int j = 0; j <= max2; ++j){
			if(a[i] != 0 && b[j] != 0){
				if(c[i + j] == 0)	count++;
				c[i + j] += a[i] * b[j];
				if(c[i + j] == 0) count--;
				if(i + j > max3)
					max3 = i + j;
			}		 
		}
	}
	cout << count;
	for(int i = max3; i >= 0; --i)
		if(c[i] != 0)
			printf(" %d %0.1f", i, c[i]);
	return 0; 
}