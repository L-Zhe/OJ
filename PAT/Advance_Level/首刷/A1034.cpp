/*===================================================================================
A1034 Head of a Gang (30)（30 分）
=====================================================================================
One way that the police finds the head of a gang is to check people's phone calls.
If there is a phone call between A and B, we say that A and B is related. The weight
of a relation is defined to be the total time length of all the phone calls made
between the two persons. A "Gang" is a cluster of more than 2 persons who are related
to each other with total relation weight being greater than a given threshold K.
In each gang, the one with maximum total weight is the head. Now given a list of
phone calls, you are supposed to find the gangs and the heads.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains two
positive numbers N and K (both less than or equal to 1000), the number of phone
calls and the weight threshold, respectively. Then N lines follow, each in the following
format:
Name1 Name2 Time
where Name1 and Name2 are the names of people at the two ends of the call, and Time
is the length of the call. A name is a string of three capital letters chosen from
A-Z. A time length is a positive integer which is no more than 1000 minutes.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, first print in a line the total number of gangs. Then for each
gang, print in a line the name of the head and the total number of the members.
It is guaranteed that the head is unique for each gang. The output must be sorted
according to the alphabetical order of the names of the heads.
-------------------------------------------------------------------------------------
Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10

Sample Output 1:
2
AAA 3
GGG 3
------------------
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10

Sample Output 2:
0
===================================================================================*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

const int maxn = 2010;
map<string, int> string2Int;
map<int, string> int2String;
map<string, int> Gang;
int n, k, numPerson = 0;
int weight[maxn] = {0};
int G[maxn][maxn] = {0};
bool vis[maxn] = {false};

int change(string str){
    if(string2Int.find(str) != string2Int.end())
        return string2Int[str];
    string2Int[str] = numPerson;
    int2String[numPerson] = str;
    return numPerson++;
}

void DFS(int &index, int &head, int &num, int &total){
    num++;
    vis[index] = true;
    if(weight[index] > weight[head])
        head = index;
    for(int i = 0; i < numPerson; ++i)
        if(G[index][i] > 0){
            total += G[index][i];
            G[index][i] = G[i][index] = 0;
            if(vis[i] == false)
                DFS(i, head, num, total);
    }
}


void DFSTrave(){
    for(int i = 0; i < numPerson; ++i){
        if(vis[i] == false){
            int head = i, num = 0, total = 0;
            DFS(i, head, num, total);
            if(num > 2 && total > k)
                Gang[int2String[head]] = num;
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i =0; i < n; ++i){
        string str1, str2;
        int w;
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFSTrave();
    cout << Gang.size() << endl;
    for(map<string, int>::iterator it = Gang.begin(); it != Gang.end(); ++it)
        cout << it->first << " " << it->second << endl;
    return 0;
}
