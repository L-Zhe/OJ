/*===================================================================================
A1090 Highest Price in Supply Chain (25)（25 分）
=====================================================================================
A supply chain is a network of retailers（零售商）, distributors（经销商）, and
suppliers（供应商）-- everyone involved in moving a product from supplier to customer.
Starting from one root supplier, everyone on the chain buys products from one's
supplier in a price P and sell or distribute them in a price that is r% higher than
P. It is assumed that each member in the supply chain has exactly one supplier except
the root supplier, and there is no supply cycle.
Now given a supply chain, you are supposed to tell the highest price we can expect
from some retailers.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, The first line contains three
positive numbers: N (<=10^5^), the total number of the members in the supply chain
(and hence they are numbered from 0 to N-1); P, the price given by the root supplier;
and r, the percentage rate of price increment for each distributor or retailer.
Then the next line contains N numbers, each number S~i~ is the index of the supplier
for the i-th member. S~root~ for the root supplier is defined to be -1. All the
numbers in a line are separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line the highest price we can expect from some
retailers, accurate up to 2 decimal places, and the number of retailers that sell
at the highest price. There must be one space between the two numbers. It is guaranteed
that the price will not exceed 10^10^.
-------------------------------------------------------------------------------------
Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6

Sample Output:
1.85 2
===================================================================================*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 100010;
struct node{
	double price;
	vector<int> child;
}n[maxn];
int a[maxn];
int N, totalNum = 0;
double P, r, maxP = 0;

void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int index = q.front();
		q.pop();
		if(n[index].child.size() == 0){
			if(n[index].price > maxP){
				maxP = n[index].price;
				totalNum = 1;
			}
			else if(n[index].price == maxP){
				++totalNum;
			}
		}
		for(int i = 0; i < n[index].child.size(); ++i){
			int temp = n[index].child[i];
			q.push(temp);
			n[temp].price = n[index].price * (1 + r/100);
		}
	}
}

int main(){
	cin >> N >> P >> r;
	int root;
	for(int i = 0; i < N; ++i){
		cin >> a[i];
		if(a[i] != -1)
			n[a[i]].child.push_back(i);
		else
			root = i;
	}
	n[root].price = P;
	BFS(root);
	printf("%.2f %d", maxP, totalNum);
	return 0;
}