/*===================================================================================
A1112 Stucked Keyboard?20 ??
=====================================================================================
On a broken keyboard, some of the keys are always stucked. So when you type some
sentences, the characters corresponding to those keys will appear repeatedly on
screen for k times.
Now given a resulting string on screen, you are supposed to list all the possible
stucked keys, and the original string.
Notice that there might be some characters that are typed repeatedly. The stucked
key will always repeat output for a fixed k times whenever it is pressed. For example,
when k=3, from the string thiiis iiisss a teeeeeest we know that the keys i and
e might be stucked, but s is not even though it appears repeatedly sometimes. The
original string could be this isss a teest.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the 1st line gives a positive
integer k (1<k?100) which is the output repeating times of a stucked key. The 2nd
line contains the resulting string on screen, which consists of no more than 1000
characters from {a-z}, {0-9} and _. It is guaranteed that the string is non-empty.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line the possible stucked keys, in the order of
being detected. Make sure that each key is printed once only. Then in the next line
print the original string. It is guaranteed that there is at least one stucked key.
-------------------------------------------------------------------------------------
Sample Input:
3
caseee1__thiiis_iiisss_a_teeeeeest

Sample Output:
ei
case1__this_isss_a_teest
===================================================================================*/

//重点：按照被检测到的顺序输出

#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 1e3 +10;
const int inf = 0x3fffffff;
char s[maxn];
int k;
bool mp[128], out[maxn];



int main(){
    fill(mp, mp + 128, true);	//先把所有按键都标记为坏键
    scanf("%d", &k);
    getchar();
    fgets(s, maxn, stdin);
    int i = 0;
    while(i < strlen(s)){
        int j = i + 1;
        while(j < strlen(s) && s[j] == s[i]){
            ++j;
        }
        if((j - i) % k != 0){
            mp[s[i]] = false;	//找出非坏键
        }
        i = j;
    }
    for(int i = 0; i < strlen(s); ++i){
        if(mp[s[i]] && !out[s[i]]){
            out[s[i]] = true;
            printf("%c", s[i]);
        }
    }
    printf("\n");
    for(int i = 0; i < strlen(s); ++i){
        printf("%c", s[i]);
        if(mp[s[i]]){
            i += (k - 1);
        }
    }
    system("pause");
    return 0;
}