/*===================================================================================
A1065 A+B and C (64bit) (20)（20 分）
=====================================================================================
Given three integers A, B and C in [-2^63^, 2^63^], you are supposed to tell whether
A+B > C.
-------------------------------------------------------------------------------------
Input Specification:
The first line of the input gives the positive number of test cases, T (<=10). Then
T test cases follow, each consists of a single line containing three integers A,
B and C, separated by single spaces.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, output in one line "Case #X: true" if A+B&gtC, or "Case #X:
false" otherwise, where X is the case number (starting from 1).
-------------------------------------------------------------------------------------
Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0

Sample Output:
Case #1: false
Case #2: true
Case #3: false
===================================================================================*/

#include<iostream>
#include<vector>
using namespace std;

long long int a, b, c;
int n;
vector<bool> flag;

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a >> b >> c;
        long long int temp = a + b;
        if(a>0 && b>0 && temp <0)
            flag.push_back(true);
        else if(a<0 && b<0 && temp >= 0)
            flag.push_back(false);
        else
            flag.push_back(temp > c);
    }
    for(int i = 0; i < flag.size(); ++i)
        cout << "Case #" << i+1 << ": " << boolalpha << flag[i] << endl;
    return 0;
}
