/*===================================================================================
A1085 Perfect Sequence (25)（25 分）提问
=====================================================================================
Given a sequence of positive integers and another positive integer p. The sequence
is said to be a "perfect sequence" if M <= m * p where M and m are the maximum and
minimum numbers in the sequence, respectively.
Now given a sequence and a parameter p, you are supposed to find from the sequence
as many numbers as possible to form a perfect subsequence.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains two
positive integers N and p, where N (<= 10^5^) is the number of integers in the sequence,
and p (<= 10^9^) is the parameter. In the second line there are N positive integers,
each is no greater than 10^9^.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line the maximum number of integers that can be
chosen to form a perfect subsequence.
-------------------------------------------------------------------------------------
Sample Input:
10 8
2 3 20 4 5 1 6 7 8 9

Sample Output:
8
===================================================================================*/


#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int maxn = 1e5 + 10;
int n;
int p;
int ans[maxn];

int binarySearch(int index, long long x){
	/* if(ans[n - 1] < x)
		return n; */
	int l = index, r = n;
	while(l < r){
		int mid = (l + r) / 2;
		if(x >= ans[mid])
			l = mid;
		else 
			r = mid + 1;
	}
	return l;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; ++i){
		scanf("%d", ans + i);
	}
	sort(ans, ans + n);
	int res = 1;
	for(int i = 0; i < n; ++i){
		int temp = binarySearch(i, (long long)p*ans[i]);
		//int temp = lower_bound(ans + i + 1, ans + n, (long long)p * ans[i]) - ans;
		res = max(res, temp - i);
	}
	printf("%d", res);
	freopen("CON", "r", stdin);
	system("pause");
	return 0;
}

/* 
函数法，注意识别用lower_bound还是upper_bound
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
int a[maxn];
int n, p;



int main(){
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; ++i){
		scanf("%d", a + i);
	}
	sort(a, a + n);
	int num = 1;
	for(int i = 0; i < n; ++i){
		int pos = upper_bound(a + i, a + n, (ll)a[i] * p) - a;
		num = max(num, pos - i);
	}
	printf("%d", num);
	return 0;
}
 */
 
/* 
双指针方法， 会超时
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
int a[maxn];
int n, p;

int main(){
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; ++i){
		scanf("%d", a + i);
	}
	sort(a, a + n);
	int num = 1;
	for(int i = 0; i < n - num; ++i){
		int j = i;
		while(j < n && a[j] <= (ll)a[i] * p)	++j;
		num = max(num, j - i);
	}
	printf("%d", num);
	return 0;
} */
