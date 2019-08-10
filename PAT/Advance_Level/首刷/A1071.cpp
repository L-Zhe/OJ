/*===================================================================================
A1071 Speech Patterns (25)?25 ??
=====================================================================================
People often have a preference among synonyms of the same word. For example, some
may prefer "the police", while others may prefer "the cops". Analyzing such patterns
can help to narrow down a speaker's identity, which is useful when validating, for
example, whether it's still the same person behind an online avatar.
Now given a paragraph of text sampled from someone's speech, can you find the person's
most commonly used word?
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, there is one line of text
no more than 1048576 characters in length, terminated by a carriage return '\n'.
The input contains at least one alphanumerical character, i.e., one character from
the set [0-9 A-Z a-z].
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line the most commonly occurring word in the input
text, followed by a space and the number of times it has occurred in the input.
If there are more than one such words, print the lexicographically smallest one.
The word should be printed in all lower case. Here a "word" is defined as a continuous
sequence of alphanumerical characters separated by non-alphanumerical characters
or the line beginning/end.
Note that words are case insensitive.
-------------------------------------------------------------------------------------
Sample Input:
Can1: "Can a can can a can?  It can!"

Sample Output:
can 5
===================================================================================*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string, int> cnt;
string s;

int main(){
    freopen("data.txt", "r", stdin);
    getline(cin, s); 
    
    //把所有大写字母转换为小写字母
    for (int i = 0; i < s.length(); ++i){
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
    }
    int i = 0;

    while(i < s.length()){
        while(i < s.length() && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))){
            ++i;
        }
        if(i >= s.length())
            break;
        int j = i;
        string temp;
        while (j < s.length() && ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))){
            ++j;
        }
        if ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))
            ++j;
        temp.insert(temp.begin(), s.begin() + i, s.begin() + j);
        if (cnt.find(temp) == cnt.end())
            cnt[temp] = 1;
        else
            cnt[temp]++;
        i = j;
    }
    int MAX = 0;
    string temp;
    map<string, int>::iterator it = cnt.end();
    for (it--; it != cnt.begin(); --it)
    {
        if(it->second > MAX){
            MAX = it->second;
            temp = it->first;
        }
    }
    if(cnt.begin()->second > MAX){
        MAX = cnt.begin()->second;
        temp = cnt.begin()->first;
    }
    cout << temp << " " << MAX << endl;
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}