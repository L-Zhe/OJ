/*===================================================================================
A1079 Total Sales of Supply Chain (25)锛?5 鍒嗭級
=====================================================================================
A supply chain is a network of retailers锛堥浂鍞晢锛? distributors锛堢粡閿€鍟嗭級, and
suppliers锛堜緵搴斿晢锛?- everyone involved in moving a product from supplier to customer.
Starting from one root supplier, everyone on the chain buys products from one's
supplier in a price P and sell or distribute them in a price that is r% higher than
P. Only the retailers will face the customers. It is assumed that each member in
the supply chain has exactly one supplier except the root supplier, and there is
no supply cycle.
Now given a supply chain, you are supposed to tell the total sales from all the
retailers.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains three
positive numbers: N (<=10^5^), the total number of the members in the supply chain
(and hence their ID's are numbered from 0 to N-1, and the root supplier's ID is
0); P, the unit price given by the root supplier; and r, the percentage rate of
price increment for each distributor or retailer. Then N lines follow, each describes
a distributor or retailer in the following format:
K~i~ ID[1] ID[2] ... ID[K~i~]
where in the i-th line, K~i~ is the total number of distributors or retailers who
receive products from supplier i, and is then followed by the ID's of these distributors
or retailers. K~j~ being 0 means that the j-th member is a retailer, then instead
the total amount of the product will be given after K~j~. All the numbers in a line
are separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line the total sales we can expect from all the
retailers, accurate up to 1 decimal place. It is guaranteed that the number will
not exceed 10^10^.
-------------------------------------------------------------------------------------
Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3

Sample Output:
42.4
===================================================================================*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int maxn = 100010;
struct node{
	double price;
	int num;
	vector<int>	child;
}n[maxn];
int N;
double P, r, total = 0;

void BFS(){
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int index = q.front();
		q.pop();
		if(n[index].child.size() == 0)
			total += n[index].price * n[index].num;
		for(int i = 0; i < n[index].child.size(); ++i){
			int temp = n[index].child[i];
			q.push(temp);
			n[temp].price = n[index].price * (1 + r/100);
		}
	}
}

int main(){
	cin >> N >> P >> r;
	for(int i = 0; i < N; ++i){
		int k, temp;
		cin >> k;
		if(k == 0){
			cin >> temp;
			n[i].num = temp;
		}
		for(int j = 0; j < k; ++j){
			cin >> temp;
			n[i].child.push_back(temp);
		}
	}
	n[0].price = P;
	BFS();
	printf("%.1f", total);
	return 0;
}