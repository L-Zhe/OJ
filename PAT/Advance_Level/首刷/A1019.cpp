/*===================================================================================
A1019 General Palindromic Number (20)（20 分）
=====================================================================================
A number that will be the same when it is written forwards or backwards is known
as a Palindromic Number. For example, 1234321 is a palindromic number. All single
digit numbers are palindromic numbers.
Although palindromic numbers are most often considered in the decimal system, the
concept of palindromicity can be applied to the natural numbers in any numeral system.
Consider a number N > 0 in base b >= 2, where it is written in standard notation
with k+1 digits a~i~ as the sum of (a~i~b^i^) for i from 0 to k. Here, as usual,
0 <= a~i~ < b for all i and a~k~ is non-zero. Then N is palindromic if and only
if a~i~ = a~k-i~ for all i. Zero is written 0 in any base and is also palindromic
by definition.
Given any non-negative decimal integer N and a base b, you are supposed to tell
if N is a palindromic number in base b.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case consists of two non-negative numbers
N and b, where 0 <= N <= 10^9^ is the decimal number and 2 <= b <= 10^9^ is the
base. The numbers are separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, first print in one line "Yes" if N is a palindromic number in
base b, or "No" if not. Then in the next line, print N as the number in base b in
the form "a~k~ a~k-1~ ... a~0~". Notice that there must be no extra space at the
end of output.
-------------------------------------------------------------------------------------
Sample Input 1:
27 2

Sample Output 1:
Yes
1 1 0 1 1
------------------
Sample Input 2:
121 5

Sample Output 2:
No
4 4 1
===================================================================================*/

#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
ll n, b;
vector<int> ans;

void change(){
    while(n > 0){
        ll a = n % b;
        n = n / b;
        ans.push_back(a);
    }
}

bool judge(){
    int i = 0, j = ans.size() - 1;
    while(i <= j){
        if(ans[i++] != ans[j--])
            return false;
    }
    return true;
}

int main(){
    cin >> n >> b;
    bool flag;
    if(n != 0){
        change();
        flag = judge();
    }
    else{
        flag = true;
        ans.push_back(0);
    }
    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for(int i = ans.size() - 1; i >= 0; --i){
        cout << ans[i];
        if(i != 0)  cout << " ";
    }
    return 0;
}
