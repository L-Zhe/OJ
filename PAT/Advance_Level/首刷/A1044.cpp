/*===================================================================================
A1044 Shopping in Mars (25)?25 ????
=====================================================================================
Shopping in Mars is quite a different experience. The Mars people pay by chained
diamonds. Each diamond has a value (in Mars dollars M\$). When making the payment,
the chain can be cut at any position for only once and some of the diamonds are
taken off the chain one by one. Once a diamond is off the chain, it cannot be taken
back. For example, if we have a chain of 8 diamonds with values M\$3, 2, 1, 5, 4,
6, 8, 7, and we must pay M\$15. We may have 3 options:
1. Cut the chain between 4 and 6, and take off the diamonds from the position 1
to 5 (with values 3+2+1+5+4=15).\
Cut before 5 or after 6, and take off the diamonds from the position 4 to 6 (with
values 5+4+6=15).\
Cut before 8, and take off the diamonds from the position 7 to 8 (with values 8+7=15).\
Now given the chain of diamond values and the amount that a customer has to pay,
you are supposed to list all the paying options for the customer.
If it is impossible to pay the exact amount, you must suggest solutions with minimum
lost.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains 2
numbers: N (<=10^5^), the total number of diamonds on the chain, and M (<=10^8^),
the amount that the customer has to pay. Then the next line contains N positive
numbers D~1~ ... D~N~ (D~i~<=10^3^ for all i=1, ..., N) which are the values of
the diamonds. All the numbers in a line are separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print "i-j" in a line for each pair of i <= j such that D~i~
+ ... + D~j~ = M. Note that if there are more than one solution, all the solutions
must be printed in increasing order of i.
If there is no solution, output "i-j" for pairs of i <= j such that D~i~ + ... +
D~j~ > M with (D~i~ + ... + D~j~ - M) minimized. Again all the solutions must be
printed in increasing order of i.
It is guaranteed that the total value of diamonds is sufficient to pay the given
amount.
-------------------------------------------------------------------------------------
Sample Input 1:
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13

Sample Output 1:
1-5
4-6
7-8
11-11
------------------
Sample Input 2:
5 13
2 4 5 7 9

Sample Output 2:
2-4
4-5
===================================================================================*/

//此题告诉我们，不要总想着用vector+排序偷懒

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;
const int inf = 1e8 + 10;
int n, m;
int chain[maxn];

int binarySearch(int l, int r, int x){
    int left = l, right = r;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(chain[mid] >= x)       //找出第一个不小于x的坐标j
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}


int main(){
    freopen("data.txt", "r",stdin);
    scanf("%d%d", &n, &m);
    chain[0] = 0;
    for (int i = 1; i <= n; ++i){
        scanf("%d", chain + i);
        chain[i] += chain[i - 1];
    }
    int dism = inf;
    for (int i = 1; i <= n; ++i){
        int x = m + chain[i - 1];
        int j = binarySearch(i, n + 1, x);
        if(j <= n)
            dism = min(dism, chain[j] - chain[i - 1]);
    }
    for (int i = 1; i <= n; ++i){
        int j = binarySearch(i, n, dism + chain[i - 1]);//不考虑j = n + 1的情况
        if(chain[j] - chain[i - 1] == dism)
            printf("%d-%d\n", i, j);
    }
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}

/*算法笔记解
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 10;
int n, m;
int chain[maxn];
struct node
{
    int i, j;
    int total;
};
vector<node> ans;

int binarySearch(int l, int r, int x)
{
    int left = l, right = r;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (chain[mid] > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

bool cmp(node a, node b)
{
    return abs(a.total - m) < abs(b.total - m);
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    chain[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", chain + i);
        chain[i] += chain[i - 1];
    }
    int nears = 1e5 + 10;
    for (int i = 1; i <= n; ++i)
    {
        int x = m + chain[i - 1];
        int j = binarySearch(i, n + 1, x);
        if(chain[j - 1] - chain[i - 1] == m){
            nears = m;
            break;
        }
        else if(chain[j] - chain[i - 1] > m){
            nears = min(nears, chain[j] - chain[i - 1]);
        }
    }
    //cout << nears << endl;
    for (int i = 1; i <= n; ++i)
    {
        int j = binarySearch(i, n, nears + chain[i - 1]);
        if(chain[j - 1] - chain[i - 1] == nears)
            printf("%d-%d\n", i, j - 1);
    }
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}
*/