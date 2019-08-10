/*===================================================================================
A1093 Count PAT's (25)?25 ????
=====================================================================================
The string APPAPT contains two PAT's as substrings. The first one is formed by the
2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the
4th, and the 6th characters.
Now given any string, you are supposed to tell the number of PAT's contained in
the string.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, there is only one line giving
a string of no more than 10^5^ characters containing only P, A, or T.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line the number of PAT's contained in the string.
Since the result may be a huge number, you only have to output the result moded
by 1000000007.
-------------------------------------------------------------------------------------
Sample Input:
APPAPT

Sample Output:
2
===================================================================================*/

#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 1e5 + 10;
const int mod = 1000000007;
char s[maxn];
int p[maxn], t;
int cnt = 0;

int main(){
    scanf("%s", s);
    int len = strlen(s);
    if(s[0] == 'P')
        p[0] = 1;
    else
        p[0] = 0;
    for (int i = 1; i < len; ++i)
    {
        if(s[i] == 'P')
            p[i] = p[i - 1] + 1;
        else
            p[i] = p[i - 1];
    }
    for (int i = len - 1; i >= 0; --i){
        if(s[i] == 'T')
            ++t;
        else if(s[i] == 'A')
            cnt =(cnt + t * p[i])  % mod;
    }
    printf("%d", cnt);
    system("pause");
    return 0;
}