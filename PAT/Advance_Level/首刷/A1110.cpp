/*===================================================================================
A1110 Complete Binary Tree?25 ??
=====================================================================================
Given a tree, you are supposed to tell if it is a complete binary tree.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive
integer N (?20) which is the total number of nodes in the tree -- and hence the
nodes are numbered from 0 to N?1. Then N lines follow, each corresponds to a node,
and gives the indices of the left and right children of the node. If the child does
not exist, a - will be put at the position. Any pair of children are separated by
a space.
-------------------------------------------------------------------------------------
Output Specification:
For each case, print in one line YES and the index of the last node if the tree
is a complete binary tree, or NO and the index of the root if not. There must be
exactly one space separating the word and the number.
-------------------------------------------------------------------------------------
Sample Input 1:
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -

Sample Output 1:
YES 8
------------------
Sample Input 2:
8
- -
4 5
0 6
- -
2 3
- 7
- -
- -

Sample Output 2:
NO 1
===================================================================================*/

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 23;
struct node{
    int left, right;
}Btree[maxn];
bool isRoot[maxn];
int n;
int a[maxn];

int change(char s[]){
    int num = 0;
    for (int i = 0; i < strlen(s); ++i){
        num = num * 10 + s[i] - '0';
    }
    return num;
}

void BFS(int root){
    queue<int> q;
    q.push(root);
    int index = 1;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        a[index++] = top;
        if(Btree[top].left != -1){
            q.push(Btree[top].left);
        }
        if(Btree[top].right != -1){
            q.push(Btree[top].right);
        }
    }
}

bool judge(){
    int i = 1;
    for (int i = 1;  i <= n / 2; ++i){
        if(a[2*i] != Btree[a[i]].left)
            return false;
        if(2*i + 1 <= n && a[2*i + 1] != Btree[a[i]].right)
            return false;
    }
    return true;
}

int main(){
    freopen("data.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        char s1[3], s2[3];
        scanf("%s %s", s1, s2);
        if(strcmp(s1, "-") != 0){
            int index = change(s1);
            Btree[i].left = index;
            isRoot[index] = true;
        }
        else{
            Btree[i].left = -1;
        }
        
        if(strcmp(s2, "-") != 0){
            int index = change(s2);
            Btree[i].right = index;
            isRoot[index] = true;
        }
        else{
            Btree[i].right = -1;
        }
    }
    int root;
    for (int i = 0; i < n; ++i){
        if(isRoot[i] == false){
            root = i;
            break;
        }
    }
    BFS(root);
    if(judge()){
        printf("YES %d\n", a[n]);
    }
    else{
        printf("NO %d\n", root);
    }
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}