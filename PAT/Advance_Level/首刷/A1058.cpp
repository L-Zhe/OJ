 /*===================================================================================
A1058 A+B in Hogwarts (20)（20 分）
=====================================================================================
If you are a fan of Harry Potter, you would know the world of magic has its own
currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to
a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write
a program to compute A+B where A and B are given in the standard form of "Galleon.Sickle.Knut"
(Galleon is an integer in [0, 10^7^], Sickle is an integer in [0, 17), and Knut
is an integer in [0, 29)).
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case which occupies a line with A and B in the
standard form, separated by one space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case you should output the sum of A and B in one line, with the same
format as the input.
-------------------------------------------------------------------------------------
Sample Input:
3.2.1 10.16.27

Sample Output:
14.1.28
===================================================================================*/

#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
stack<long long int> ans;
long long int a[2][3];

int main(){
    scanf("%lld.%lld.%lld", &a[0][0], &a[0][1], &a[0][2]);
    scanf("%lld.%lld.%lld", &a[1][0], &a[1][1], &a[1][2]);
    long long int t1 = a[0][0] * 17 * 29 + a[0][1] * 29 + a[0][2];
    long long int t2 = a[1][0] * 17 * 29 + a[1][1] * 29 + a[1][2];
    long long int t = t1 + t2;
    ans.push(t % 29);
    t /= 29;
    ans.push(t % 17);
    t /= 17;
    ans.push(t);
    bool flag = false;
    while(!ans.empty()){
        if(flag)    cout << ".";
        flag = true;
        cout << ans.top();
        ans.pop();
    }
}
