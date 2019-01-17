/*===================================================================================
A1092 To Buy or Not to Buy (20)£®20 ∑÷£©Ã·Œ 
=====================================================================================
Eva would like to make a string of beads with her favorite colors so she went to
a small shop to buy some beads. There were many colorful strings of beads. However
the owner of the shop would only sell the strings in whole pieces. Hence Eva must
check whether a string in the shop contains all the beads she needs. She now comes
to you for help: if the answer is "Yes", please tell her the number of extra beads
she has to buy; or if the answer is "No", please tell her the number of beads missing
from the string.
For the sake of simplicity, let's use the characters in the ranges [0-9], [a-z],
and [A-Z] to represent the colors. For example, the 3rd string in Figure 1 is the
one that Eva would like to make. Then the 1st string is okay since it contains all
the necessary beads with 8 extra ones; yet the 2nd one is not since there is no
black bead and one less red bead.
\ Figure 1
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case gives in two lines the strings
of no more than 1000 beads which belong to the shop owner and Eva, respectively.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print your answer in one line. If the answer is "Yes", then
also output the number of extra beads Eva has to buy; or if the answer is "No",
then also output the number of beads missing from the string. There must be exactly
1 space between the answer and the number.
-------------------------------------------------------------------------------------
Sample Input 1:
ppRYYGrrYBR2258
YrR8RrY

Sample Output 1:
Yes 8
------------------
Sample Input 2:
ppRYYGrrYB225
YrR8RrY

Sample Output 1:
No 2
===================================================================================*/

#include<iostream>
using namespace std;

int a[128]; 
int main(){
	freopen("data.txt", "r", stdin);
	char s1[1001], s2[1001];
	scanf("%s%s", s1, s2);
	int i = 0, len = 0;
	while(s1[i] != '\0'){
		int temp = s1[i] - '\0';
		++len;
		++a[temp];
		++i;
	}
	//cout << len << endl;
	i = 0;
	int cnt = 0, ncnt = 0;
	while(s2[i] != '\0'){
		int temp = s2[i] - '\0';
		if(a[temp]){
			cnt++;
			--a[temp];
		}
		else
			ncnt++;
		++i;
	}
	if(ncnt)
		cout << "No " << ncnt;
	else
		cout << "Yes " << len - cnt;
	return 0;
}