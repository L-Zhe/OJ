/*===================================================================================
A1001 A+B Format (20)（20 分）
=====================================================================================
Calculate a + b and output the sum in standard format -- that is, the digits must
be separated into groups of three by commas (unless there are less than four digits).
-------------------------------------------------------------------------------------
Input
Each input file contains one test case. Each case contains a pair of integers a
and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.
-------------------------------------------------------------------------------------
Output
For each test case, you should output the sum of a and b in one line. The sum must
be written in the standard format.
-------------------------------------------------------------------------------------
Sample Input
-1000000 9

Sample Output
-999,991
===================================================================================*/


#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 10;
int M[maxn], N[maxn];
void print(int l) {
	int j = l % 3;
	j = (j == 0 ? 3 : j);
	for (int i = l - 1; i >= 0; --i) {
		cout << M[i];
		j--;
		if (j == 0 && i != 0) {
			cout << ',';
			j = 3;
		}
	}
}
int def( int m, int n) {
	int lm = 0, ln = 0;
	m = abs(m);
	n = abs(n);
	while (m >= 1) {
		M[lm++] = m % 10;
		m /= 10;
	}
	while (n >= 1) {
		N[ln++] = n % 10;
		n /= 10;
	}
	int l = max(lm, ln);
	return l;
}
int main() {
	int m, n;
	while (scanf_s("%d%d", &m, &n) == 2) {
		if (m + n == 0) {
			cout << '0';
			continue;
		}
		int cm = 1, cn = 1;
		memset(M, 0, sizeof(M));
		memset(N, 0, sizeof(N));
		if (m != abs(m))	cm = -1;
		if (n != abs(n))	cn = -1;
		if ((cm == -1) && (cn == -1))	cout << '-';
		if ((cm != cn) && (m + n < 0)) cout << '-';
		if (cm != cn) {
			int ans = m + n;
			ans = abs(ans);
			int l = 0;
			while (ans >= 1) {
				M[l++] = ans % 10;
				ans /= 10;
			}
			print(l);
			continue;
		}
		int l = def(m, n);
		int c = 0;
		for (int i = 0; i < l; ++i) {
			int ans = cm * M[i] + cn * N[i] + c;
			M[i] = abs(ans) % 10;
			c = ans / 10;
		}
		if (c != 0)
			M[l++] = abs(c);
		print(l);
	}
	system("pause");
	return 0;
}