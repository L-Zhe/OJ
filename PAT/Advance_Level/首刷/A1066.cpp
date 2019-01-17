/*===================================================================================
A1066 Root of AVL Tree (25)（25 分）
=====================================================================================
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights
of the two child subtrees of any node differ by at most one; if at any time they
differ by more than one, rebalancing is done to restore this property. Figures 1-4
illustrate the rotation rules.
 
 
Now given a sequence of insertions, you are supposed to tell the root of the resulting
AVL tree.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains a
positive integer N (<=20) which is the total number of keys to be inserted. Then
N distinct integer keys are given in the next line. All the numbers in a line are
separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print the root of the resulting AVL tree in one line.
-------------------------------------------------------------------------------------
Sample Input 1:
5
88 70 61 96 120

Sample Output 1:
70
------------------
Sample Input 2:
7
88 70 61 96 120 90 65

Sample Output 2:
88
===================================================================================*/

#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int data, height;
	node *left, *right;
};
int n;

node* newNode(int data){
    node* root = new node;
    root->left = root->right = NULL;
    root->data = data;
    root->height = 1;
    return root;
}

int getHeight(node* root){
    if(root == NULL)
        return 0;
    return root->height;
}

void updateHeight(node* root){
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int balanceFac(node* root){
    return getHeight(root->left) - getHeight(root->right);
}

void  L(node* &root){
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node* &root){
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node* &root, int data){
    if(root == NULL){
        root = newNode(data);
        return;
    }
    if(data < root->data){
        insert(root->left, data);
        updateHeight(root);
        if(balanceFac(root) == 2){
            if(balanceFac(root->left) == 1)
                R(root);
            else if(balanceFac(root->left) == -1){//注意！！！elsei很重要，没有else会报错。
                L(root->left);
                R(root);
            }
        }
    }
    else{
        insert(root->right, data);
        updateHeight(root);
        if(balanceFac(root) == -2){
            if(balanceFac(root->right) == -1)
                L(root);
            else if(balanceFac(root->right) == 1){
                R(root->right);
                L(root);
            }
        }
    }
}

int main(){
    cin >> n;
    node* root = NULL;
    for(int i = 0; i < n; ++i){
        int temp;
        cin >> temp;
        insert(root, temp);
    }
    cout << root->data;
    return 0;
}
