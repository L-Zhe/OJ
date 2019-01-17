/*===================================================================================
A1108 Finding Average (20)£®20 ∑÷£©Ã·Œ 
=====================================================================================
The basic task is simple: given N real numbers, you are supposed to calculate their
average. But what makes it complicated is that some of the input numbers might not
be legal. A "legal" input is a real number in [-1000, 1000] and is accurate up to
no more than 2 decimal places. When you calculate the average, those illegal numbers
must not be counted in.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive
integer N (<=100). Then N numbers are given in the next line, separated by one space.
-------------------------------------------------------------------------------------
Output Specification:
For each illegal input number, print in a line "ERROR: X is not a legal number"
where X is the input. Then finally print in a line the result: "The average of K
numbers is Y" where K is the number of legal inputs and Y is their average, accurate
to 2 decimal places. In case the average cannot be calculated, output "Undefined"
instead of Y. In case K is only 1, output "The average of 1 number is Y" instead.
-------------------------------------------------------------------------------------
Sample Input 1:
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35

Sample Output 1:
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
------------------
Sample Input 2:
2
aaa -9999

Sample Output 2:
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
===================================================================================*/

#include<iostream>
#include<cstring>
using namespace std;

int n, cnt = 0;
double total = 0;

bool countdig(char s[]){
    int cnt = 0;
    for (int i = 0; i < strlen(s); ++i){
        if(s[i] == '.'){
            cnt++;
        }
        if (cnt > 1)
            return false;
    }
    return true;
}

bool alpha(char s[]){
    if((s[0] < '0' || s[0] > '9') && (s[0] != '-' && s[0] != '+'))
        return false;
    for (int i = 1; i < strlen(s); ++i)
    {
        if((s[i] < '0' || s[i] > '9') && s[i] != '.')
            return false;
    }
    return true;
}

bool numdig(char s[]){
    int cnt = 0, i;
    bool flag = false;
    for (i = strlen(s) - 1; i >= 0; --i)
    {
        if(s[i] == '.'){
            flag = true;
            break;
        }
        cnt++;
    }
    if(flag && cnt > 2)
        return false;
    return true;
}

double change(char* st){
	double num1 = 0, num2 = 0;
	int i = 0, index = 1;
	if(st[0] == '-'){
		index = -1;
		i = 1;
	}
	for(; i < strlen(st); ++i){
		if(st[i] == '.')	break;
		num1 = num1 * 10 + st[i] - '0';
	}
	for(int j = strlen(st) - 1; j > i; --j){
		num2 = num2 * 0.1 + st[j] - '0';
	}
	return index * (num1 + 0.1 * num2);
}

bool judge(char s[]){
    // cout << countdig(s) << " " << alpha(s) << " " << numdig(s) << " " << s << endl;
    if (countdig(s) && alpha(s) && numdig(s)){
        double num = change(s);
        if(num >= -1000 && num <= 1000)
            return true;
    }
    return false;
}

int main(){
//    freopen("data.txt", "r", stdin);
    scanf("%d", &n);
    char s[100];
    for (int i = 0; i < n; ++i){
        scanf("%s", s);
        if(judge(s)){
            total += change(s);
            cnt++;
        }
        else{
            printf("ERROR: %s is not a legal number\n", s);
        } 
    }
    if(cnt != 0){
        if(cnt != 1)
            printf("The average of %d numbers is %.2f", cnt, total / cnt);
        
        else
            printf("The average of %d number is %.2f", cnt, total / cnt);
    }
       
    else
        printf("The average of 0 numbers is Undefined");
//    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}
