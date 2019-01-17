/*===================================================================================
A1107 Social Clusters (30)（30 分）
=====================================================================================
When register on a social network, you are always asked to specify your hobbies
in order to find some potential friends with the same hobbies. A "social cluster"
is a set of people who have some of their hobbies in common. You are supposed to
find all the clusters.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each test case, the first line contains
a positive integer N (<=1000), the total number of people in a social network. Hence
the people are numbered from 1 to N. Then N lines follow, each gives the hobby list
of a person in the format:
K~i~: h~i~[1] h~i~[2] ... h~i~[K~i~]
where K~i~ (>0) is the number of hobbies, and h~i~[j] is the index of the j-th hobby,
which is an integer in [1, 1000].
-------------------------------------------------------------------------------------
Output Specification:
For each case, print in one line the total number of clusters in the network. Then
in the second line, print the numbers of people in the clusters in non-increasing
order. The numbers must be separated by exactly one space, and there must be no
extra space at the end of the line.
-------------------------------------------------------------------------------------
Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4

Sample Output:
3
4 3 1
===================================================================================*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1010;
int father[maxn];
int isRoot[maxn];
int hobby[maxn];
int n, k;

void init(){
    for(int i = 0; i < maxn; ++i){
        father[i] = i;
        isRoot[i] = 0;
        hobby[i] = 0;
    }
}

int findFather(int a){
    int f = a;
    while(father[f] != f){
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
        father[fb] = fa;
}

bool cmp(int a, int b){
    return a > b;
}

int main(){
    init();
    cin >> n;
    for(int i = 1; i <= n; ++i){
        scanf("%d:", &k);
        for(int j = 0; j < k; ++j){
            int temp;
            cin >> temp;
            if(hobby[temp] == 0)
                hobby[temp] = i;
            Union(i, findFather(hobby[temp]));
        }
    }
    for(int i = 1; i <= n; ++i)
        isRoot[findFather(i)]++;
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        if(isRoot[i] != 0)
            ans++;
    cout << ans << endl;
    sort(isRoot+1, isRoot+n+1, cmp);
    bool flag = false;
    for(int i = 1; i <= ans; ++i){
        if(flag)    cout << " ";
        flag = true;
        cout << isRoot[i];
    }
    return 0;
}
