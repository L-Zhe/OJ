/*===================================================================================
A1084 Broken Keyboard (20)£®20 ∑÷£©Ã·Œ 
=====================================================================================
On a broken keyboard, some of the keys are worn out. So when you type some sentences,
the characters corresponding to those keys will not appear on screen.
Now given a string that you are supposed to type, and the string that you actually
type out, please list those keys which are for sure worn out.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the 1st line contains the
original string, and the 2nd line contains the typed-out string. Each string contains
no more than 80 characters which are either English letters [A-Z] (case insensitive),
digital numbers [0-9], or "_" (representing the space). It is guaranteed that both
strings are non-empty.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line the keys that are worn out, in the order of
being detected. The English letters must be capitalized. Each worn out key must
be printed once only. It is guaranteed that there is at least one worn out key.
-------------------------------------------------------------------------------------
Sample Input:
7_This_is_a_test
_hs_s_a_es

Sample Output:
7TI
===================================================================================*/

#include<iostream>
using namespace std;

char a[128];

int main(){
	freopen("data.txt", "r", stdin);
	char s1[90], s2[90];
	scanf("%s%s", s1, s2);
	int i = 0, j = 0;
	while(s2[j] != '\0'){
		while(s1[i] != s2[j]){
			if(a[s1[i]] == 0){
				a[s1[i]] = 1;
				if(s1[i] >= 'a' && s1[i] <= 'z'){
					a[s1[i] - 32] = 1;
					printf("%c", s1[i] - 32);
				}
					
				else if(s1[i] >= 'A' && s1[i] <= 'Z'){
					a[s1[i] +  32] = 1;
					printf("%c", s1[i]);
				}
				else
					printf("%c", s1[i]);
			}
			++i;
		}
		++i;
		++j;
	}
	while(s1[i] != '\0'){
		if(a[s1[i]] == 0){
			a[s1[i]] = 1;
			if(s1[i] >= 'a' && s1[i] <= 'z'){
				a[s1[i]- 32] = 1;
				printf("%c", s1[i] - 32);
			}
			else if(s1[i] >= 'A' && s1[i] <= 'Z'){
				a[s1[i] + 32] = 1;
				printf("%c", s1[i]);
			}
			else
				printf("%c", s1[i]);
		}
		++i;
	}
	return 0;
}