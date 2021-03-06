/*===================================================================================
A1021 Deepest Root (25)（25 分）
=====================================================================================
A graph which is connected and acyclic can be considered a tree. The height of the
tree depends on the selected root. Now you are supposed to find the root that results
in a highest tree. Such a root is called the deepest root.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains a
positive integer N (<=10000) which is the number of nodes, and hence the nodes are
numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the
two adjacent nodes' numbers.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print each of the deepest roots in a line. If such a root is
not unique, print them in increasing order of their numbers. In case that the given
graph is not a tree, print "Error: K components" where K is the number of connected
components in the graph.
-------------------------------------------------------------------------------------
Sample Input 1:
5
1 2
1 3
1 4
2 5

Sample Output 1:
3
4
5
------------------
Sample Input 2:
5
1 3
1 4
2 5
3 4

Sample Output 2:
Error: 2 components
===================================================================================*/

#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

const int maxn = 10010;
vector<int> Adj[maxn];
int father[maxn], height[maxn];
bool root[maxn], vis[maxn];
int n, maxHeight = 0;
vector<int> ans;

//Union
int findFather(int a){
    int f = a;
    while(f != father[f]){
        f = father[f];
    }
    while(a != father[a]){
        int temp = father[a];
        father[a] = f;
        a = temp;
    }
    return f;
}

void Union(int a, int b){
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb)
        father[fa] = fb;
}

void init(){
    for(int i = 1; i <= n; ++i){
        father[i] = i;
        root[i] = false;
    }
}

int judge(){
    int block = 0;
    for(int i = 1; i <= n; ++i){
        int f = findFather(i);
        if(root[f] == false){
            block++;
            root[f] = true;
        }
    }
    return block;
}

//DFS
void init_BFS(){
    for(int i = 1; i <= n; ++i)
        vis[i] = false;
}

int BFS(int index){
    init_BFS();
    queue<int> q;
    int maxH;
    q.push(index);
    vis[index] = true;
    height[index] = 1;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        maxH = height[top];
        for(int i = 0; i < Adj[top].size(); ++i){
            int next = Adj[top][i];
            if(vis[next] == false){
                q.push(next);
                vis[next] = true;
                height[next] = height[top] + 1;
            }
        }
    }
    return maxH;
}

void func(){
    for(int i = 1; i <= n; ++i){
        int temp = BFS(i);
        if(temp > maxHeight){
            maxHeight = temp;
            ans.clear();
            ans.push_back(i);
        }
        else if(temp == maxHeight)
            ans.push_back(i);
    }
}

int main(){
    cin >> n;
    init();
    for(int i = 0; i < n-1; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        Adj[a].push_back(b);
        Adj[b].push_back(a);
        Union(a, b);
    }
    int block = judge();
    if(block != 1)
        cout << "Error: " << block << " components";
    else{
        func();
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << endl;
    }
    return 0;
}
