/*===================================================================================
A1115 Counting Nodes in a BST��30 �֣�����
=====================================================================================
A Binary Search Tree (BST) is recursively defined as a binary tree which has the
following properties:
The left subtree of a node contains only nodes with keys less than or equal to the
node's key.
The right subtree of a node contains only nodes with keys greater than the node's
key.
Both the left and right subtrees must also be binary search trees.
Insert a sequence of numbers into an initially empty binary search tree. Then you
are supposed to count the total number of nodes in the lowest 2 levels of the resulting
tree.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive
integer N (��1000) which is the size of the input sequence. Then given in the next
line are the N integers in [-1000, 1000] which are supposed to be inserted into an
initially empty binary search tree.
-------------------------------------------------------------------------------------
Output Specification:
For each case, print in one line the numbers of nodes in the lowest 2 levels of
the resulting tree in the format:
n1 + n2 = n
where n1 is the number of nodes in the lowest level, n2 is that of the level above,
and n is the sum.
-------------------------------------------------------------------------------------
Sample Input:
9
25 30 42 16 20 20 35 -5 28

Sample Output:
2 + 4 = 6
===================================================================================*/


#include<iostream>
#include<queue>
using namespace std;

const int maxn = 2000;
struct node{
	int data, layer;
	node *left, *right;
};
int num[maxn];
int n, maxLayer = 0;

void insert(node* &root, int x){
	if(root == NULL){
		root = new node;
		root->data = x;
		root->left = root->right = NULL;
		return;
	}
	if(x <= root->data)
		insert(root->left, x);
	else
		insert(root->right, x);
}

void BFS(node* root){
	queue<node*> q;
	root->layer = 1;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		maxLayer = temp->layer;
		num[temp->layer]++;
		if(temp->left != NULL){
			temp->left->layer = temp->layer + 1;
			q.push(temp->left);
		}
		if(temp->right != NULL){
			temp->right->layer = temp->layer + 1;
			q.push(temp->right);
		}
	}
}

int main(){
	freopen("data.txt", "r", stdin);
	node* root = NULL;
	cin  >> n;
	for(int i = 0; i < n; ++i){
		int temp;
		cin >> temp;
		insert(root, temp);
	}
	BFS(root);
	cout << num[maxLayer] << " + " << num[maxLayer - 1] << " = " << num[maxLayer] + num[maxLayer - 1];
	return 0;
}