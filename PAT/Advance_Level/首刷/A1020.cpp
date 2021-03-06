/*===================================================================================
A1020 Tree Traversals (25)（25 分）
=====================================================================================
Suppose that all the keys in a binary tree are distinct positive integers. Given
the postorder and inorder traversal sequences, you are supposed to output the level
order traversal sequence of the corresponding binary tree.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive
integer N (<=30), the total number of nodes in the binary tree. The second line
gives the postorder sequence and the third line gives the inorder sequence. All
the numbers in a line are separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line the level order traversal sequence of the
corresponding binary tree. All the numbers in a line must be separated by exactly
one space, and there must be no extra space at the end of the line.
-------------------------------------------------------------------------------------
Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7

Sample Output:
4 1 6 3 5 7 2
===================================================================================*/

#include<iostream>
#include<queue>
using namespace std;

const int maxn = 35;
struct node{
	int data;
	node *left;
	node *right;
};
int in[maxn], pre[maxn], post[maxn];
int n;

node* creat(int inL, int inR, int postL, int postR){
	if(postL > postR)
		return NULL;
	node* T = new node;
	T->data = post[postR];
	int mid;
	for(mid = inL; mid <= inR; ++mid)
		if(in[mid] == post[postR])
			break;
	int num = mid - inL;
	T->left = creat(inL, mid-1, postL, postL+num-1);
	T->right = creat(mid+1, inR, postL+num, postR-1);
	return T;
}

void BFS(node* T){
	queue<node*> q;
	q.push(T);
	bool flag = false;
	while(!q.empty()){
		T = q.front();
		q.pop();
		if(flag)	cout << " ";
		flag = true;
		cout << T->data;
		if(T->left != NULL)
			q.push(T->left);
		if(T->right != NULL)
			q.push(T->right);
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> post[i];
	for(int i = 0; i < n; ++i)
		cin >> in[i];
	node* root = creat(0, n-1, 0, n-1);
	BFS(root);
	return 0;
}