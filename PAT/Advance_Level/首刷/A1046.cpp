/*===================================================================================
A1046 Shortest Distance (20)（20 分）
=====================================================================================
The task is really simple: given N exits on a highway which forms a simple cycle,
you are supposed to tell the shortest distance between any pair of exits.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains an
integer N (in [3, 10^5^]), followed by N integer distances D~1~ D~2~ ... D~N~, where
D~i~ is the distance between the i-th and the (i+1)-st exits, and D~N~ is between
the N-th and the 1st exits. All the numbers in a line are separated by a space.
The second line gives a positive integer M (<=10^4^), with M lines follow, each
contains a pair of exit numbers, provided that the exits are numbered from 1 to
N. It is guaranteed that the total round trip distance is no more than 10^7^.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print your results in M lines, each contains the shortest distance
between the corresponding given pair of exits.
-------------------------------------------------------------------------------------
Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1

Sample Output:
3
10
7
===================================================================================*/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int maxn = 100010;
int e[maxn];
int n, k, total = 0;

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int temp;
        scanf("%d", &temp);
        total += temp;
        e[i + 1] = total;
    }
    cin >> k;
    for(int i = 0; i < k; ++i){
        int st, ed;
        scanf("%d %d", &st, &ed);
        int high = max(st, ed);
        int low = min(st, ed);
        int next = e[high] - e[low];
        cout << min(next, total - next) << endl;
    }
    return 0;
}
