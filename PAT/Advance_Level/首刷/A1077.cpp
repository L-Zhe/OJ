/*===================================================================================
A1077 Kuchiguse (20)（20 分）
=====================================================================================
The Japanese language is notorious for its sentence ending particles. Personal preference
of such particles can be considered as a reflection of the speaker's personality.
Such a preference is called "Kuchiguse" and is often exaggerated artistically in
Anime and Manga. For example, the artificial sentence ending particle "nyan~" is
often used as a stereotype for characters with a cat-like personality:
Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)
Now given a few lines spoken by the same character, can you find her Kuchiguse?
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line is an integer
N (2<=N<=100). Following are N file lines of 0~256 (inclusive) characters in length,
each representing a character's spoken line. The spoken lines are case sensitive.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line the kuchiguse of the character, i.e., the
longest common suffix of all N lines. If there is no such suffix, write "nai".
-------------------------------------------------------------------------------------
Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~

Sample Output 1:
nyan~
------------------
Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T

Sample Output 2:
nai
===================================================================================*/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
string s[maxn];
vector<char> temp, ans;
int n;

int main(){
	cin >> n;
	getchar();
	for(int i = 0; i < n; ++i)
		getline(cin, s[i]);
	for(int i = 0; i < s[0].size(); ++i)
		ans.push_back(s[0][i]);
	for(int i = 1; i < n; ++i){
		temp.clear();
		int u = ans.size() - 1, v = s[i].size() - 1;
		while(u >= 0 && v >= 0){
			if(ans[u] != s[i][v])
				break;
			temp.push_back(ans[u]);
			u--; v--;
		}
		ans.clear();
		for(int i = temp.size() - 1; i >= 0; --i)
			ans.push_back(temp[i]);	
	}
	if(ans.size() == 0)	cout << "nai";
	else {
		for(int i = 0; i < ans.size(); ++i)
			cout << ans[i];
	}
	return 0;
}