/*===================================================================================
A1061 Dating (20)（20 分）
=====================================================================================
Sherlock Holmes received a note with some strange strings: "Let's date! 3485djDkxh4hhGE
2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". It took him only a minute to figure out
that those strange strings are actually referring to the coded time "Thursday 14:04"
-- since the first common capital English letter (case sensitive) shared by the
first two strings is the 4th capital letter 'D', representing the 4th day in a week;
the second common character is the 5th capital letter 'E', representing the 14th
hour (hence the hours from 0 to 23 in a day are represented by the numbers from
0 to 9 and the capital letters from A to N, respectively); and the English letter
shared by the last two strings is 's' at the 4th position, representing the 4th
minute. Now given two pairs of strings, you are supposed to help Sherlock decode
the dating time.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case gives 4 non-empty strings of no
more than 60 characters without white space in 4 lines.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print the decoded time in one line, in the format "DAY HH:MM",
where "DAY" is a 3-character abbreviation for the days in a week -- that is, "MON"
for Monday, "TUE" for Tuesday, "WED" for Wednesday, "THU" for Thursday, "FRI" for
Friday, "SAT" for Saturday, and "SUN" for Sunday. It is guaranteed that the result
is unique for each case.
-------------------------------------------------------------------------------------
Sample Input:
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm

Sample Output:
THU 14:04
===================================================================================*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

vector<char> ans;
int m;
string str1, str2, str3, str4;

void print(){
    char h = ans[1];
    int d = ans[0] - 'A' + 1;
    if(d == 1)  cout << "MON ";
    if(d == 2)  cout << "TUE ";
    if(d == 3)  cout << "WED ";
    if(d == 4)  cout << "THU ";
    if(d == 5)  cout << "FRI ";
    if(d == 6)  cout << "SAT ";
    if(d == 7)  cout << "SUN ";
    if(h >= '0' && h <= '9')
        printf("%02d", h - '0');
    else
        printf("%02d", h - 'A'+ 10);
    printf(":%02d", m);

}

int main(){
    cin >> str1 >> str2 >> str3 >> str4;
    int len = min(str1.size(), str2.size());
    int index;
    for(int i = 0; i <len; ++i){
        if(str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G'){
            ans.push_back(str1[i]);
            index = i + 1;
            break;
        }
    }
    for(int i = index; i < len; ++i){
        if(str1[i] == str2[i] && (str1[i] >= 'A' && str1[i] <= 'N' || str1[i] >= '0' && str1[i] <= '9')){
            ans.push_back(str1[i]);
            break;
        }
    }
    len = min(str3.size(), str4.size());
    int t = 0;
    for(int i = 0; i < len; ++i){
        if((str3[i] >= 'a' && str3[i] <= 'z') || (str3[i] >= 'A' && str3[i] <= 'Z')){
            t++;
            if(str3[i] == str4[i]){
                ans.push_back(str3[i]);
                m = i;
                break;
            }
        }
    }
    print();
    return 0;
}
