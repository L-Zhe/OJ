/*===================================================================================
A1100 Mars Numbers (20)（20 分）
=====================================================================================
People on Mars count their numbers with base 13:
Zero on Earth is called "tret" on Mars.
The numbers 1 to 12 on Earch is called "jan, feb, mar, apr, may, jun, jly, aug,
sep, oct, nov, dec" on Mars, respectively.
For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh,
tou, kes, hei, elo, syy, lok, mer, jou", respectively.
For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov"
on Mars corresponds to 115 on Earth. In order to help communication between people
from these two planets, you are supposed to write a program for mutual translation
between Earth and Mars number systems.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains a
positive integer N (< 100). Then N lines follow, each contains a number in [0, 169),
given either in the form of an Earth number, or that of Mars.
-------------------------------------------------------------------------------------
Output Specification:
For each number, print in a line the corresponding number in the other language.
-------------------------------------------------------------------------------------
Sample Input:
4
29
5
elo nov
tam

Sample Output:
hel mar
may
115
13
===================================================================================*/

#include<iostream>
#include<string>
#include<map>
#include<cstdio>
using namespace std;

string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> str2int;
string int2str[170];

void init(){
    for (int i = 0; i < 13; ++i){
        int2str[i] = unitDigit[i];
        str2int[unitDigit[i]] = i;
        int2str[i * 13] = tenDigit[i];
        str2int[tenDigit[i]] = 13 * i;
    }
    for (int i = 1; i < 13; ++i){
        for (int j = 1; j < 13; ++j){
            string str = tenDigit[i] + " " + unitDigit[j];
            int2str[13 * i + j] = str;
            str2int[str] = 13 * i + j;
        }
    }
}

int main(){
    freopen("data.txt", "r", stdin);
    init();
    string s;
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i){
        getline(cin, s);
        if(s[0] >= '0' && s[0] <= '9'){
            int num = 0;
            for (int i = 0; i < s.length(); ++i)
                num = num * 10 + s[i] - '0';
            cout << int2str[num] << endl;
        }
        else{
            cout << str2int[s] << endl;
        }
    }
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}