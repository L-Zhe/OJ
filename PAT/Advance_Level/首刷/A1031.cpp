/*===================================================================================
A1031 Hello World for U (20)（20 分）
=====================================================================================
Given any string of N (>=5) characters, you are asked to form the characters into
the shape of U. For example, "helloworld" can be printed as:
h  d
e  l
l  r
lowo
That is, the characters must be printed in the original order, starting top-down
from the left vertical line with n~1~ characters, then left to right along the bottom
line with n~2~ characters, and finally bottom-up along the vertical line with n~3~
characters. And more, we would like U to be as squared as possible -- that is, it
must be satisfied that n~1~ = n~3~ = max { k| k <= n~2~ for all 3 <= n~2~ <= N }
with n~1~
n~2~ + n~3~ - 2 = N.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case contains one string with no less
than 5 and no more than 80 characters in a line. The string contains no white space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print the input string in the shape of U as specified in the
description.
-------------------------------------------------------------------------------------
Sample Input:
helloworld!

Sample Output:
h   !
e   d
l   l
lowor
===================================================================================*/

#include<iostream>
#include<string>
using namespace std;

string st;
int N, n1, n2;

void print(int a, int b){
    int i = 0, j = N-1;
    while(a != 1){
        cout << st[i++];
        for(int v = 0; v < b - 2; ++v)
            cout << " ";
        cout << st[j--] << endl;
        a--;
    }
    for(;i <= j; ++i)
        cout << st[i];
}

int main(){
    cin >> st;
    N = st.size();
    int min = N, _n1, _n2;
    for(_n2 = 3; _n2 <= N; ++_n2){
        _n1 = (N + 2 - _n2)/2;
        int even = (N + 2 - _n2) % 2;
        if(_n2 >= _n1 && _n2 - _n1 < min && even == 0){
            min = _n2 - _n1;
            n2 = _n2;
            n1 = _n1;
        }
    }
    print(n1, n2);
    return 0;
}
