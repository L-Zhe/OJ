/*===================================================================================
A1086 Tree Traversals Again (25)（25 分）
=====================================================================================
An inorder binary tree traversal can be implemented in a non-recursive way with
a stack. For example, suppose that when a 6-node binary tree (with the keys numbered
from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3);
pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique
binary tree (shown in Figure 1) can be generated from this sequence of operations.
Your task is to give the postorder traversal sequence of this tree.
\ Figure 1
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains a
positive integer N (<=30) which is the total number of nodes in a tree (and hence
the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack
operation in the format: "Push X" where X is the index of the node being pushed
onto the stack; or "Pop" meaning to pop one node from the stack.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print the postorder traversal sequence of the corresponding
tree in one line. A solution is guaranteed to exist. All the numbers must be separated
by exactly one space, and there must be no extra space at the end of the line.
-------------------------------------------------------------------------------------
Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop

Sample Output:
3 4 2 6 5 1
===================================================================================*/

#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

vector<int> in, post, pre;
int n;
stack<int> s;
struct node{
	int data;
	node *left, *right;
};
bool flag = false;

node* creat(int inL, int inR, int preL, int preR){
	if(preL > preR)
		return NULL;
	node *t = new node;
	t->data = pre[preL];
	int mid;
	for(mid = inL; mid <= inR; ++mid)
		if(in[mid] == pre[preL])
			break;
	int num = mid - inL;
	t->left = creat(inL, mid-1, preL+1, preL+num);
	t->right = creat(mid+1, inR, preL+num+1, preR);
	return t;
}

void postOrder(node *t){
	if(t == NULL)
		return;
	postOrder(t->left);
	postOrder(t->right);
	if(flag)	cout << " ";
	flag = true;
	cout << t->data;
}

int main(){
	cin >> n;
	int data;
	string str;
	for(int i = 0; i < n;){
		cin >> str;
		if(str == "Push"){
			cin >> data;
			pre.push_back(data);
			s.push(data);
		}
		else{
			in.push_back(s.top());
			s.pop();
			++i;
		}
	}
	node *root = creat(0, n-1, 0, n-1);
	postOrder(root);
	return 0;
}