/*===================================================================================
A1067 Sort with Swap(0,*) (25)£¨25 ·Ö£©ÌáÎÊ
=====================================================================================
Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them
in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed
to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in
the following way:
Swap(0, 1) => {4, 1, 2, 0, 3}\ Swap(0, 3) => {4, 1, 2, 3, 0}\ Swap(0, 4) => {0,
1, 2, 3, 4}
Now you are asked to find the minimum number of swaps need to sort the given permutation
of the first N nonnegative integers.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case, which gives a positive N (<=10^5^) followed
by a permutation sequence of {0, 1, ..., N-1}. All the numbers in a line are separated
by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each case, simply print in a line the minimum number of swaps need to sort the
given permutation.
-------------------------------------------------------------------------------------
Sample Input:
10 3 5 7 2 6 4 9 0 8 1

Sample Output:
9
===================================================================================*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 20;
int n, total = 0;
int num[maxn];
vector<int> seq;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		seq.push_back(temp);
		num[temp] = i;
	}
	int index = 0;
	if(seq[0] == 0){
		for(; index < n; ++index){
			if(seq[index] != index){
				int data = seq[index];
				swap(seq[0], seq[index]);
				num[0] = index;
				num[data] = 0;
				total++;
				break;
			}
		}
	} 
	while(seq[0] != 0){
		int j = num[0];
		int k = num[j];
		swap(seq[j], seq[k]);
		num[j] = j;
		num[0] = k;
		total++;
		if(seq[0] == 0){
			for(; index < n; ++index){
				if(seq[index] != index){
					int data = seq[index];
					swap(seq[0], seq[index]);
					num[0] = index;
					num[data] = 0;
					total++;
					break;
				}
			}
		} 
	}
/* 	for(int i = 0; i < n; ++i)
		cout << seq[i] << " "; */
	printf("%d", total);
	return 0;
}