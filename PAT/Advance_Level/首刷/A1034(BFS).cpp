#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 2020;
struct node{
    int num;
    string head;
    int totalMin;
};
int G[maxn][maxn], totalMin[maxn];
bool vis[maxn];
int n, k, numPerson = 0;
map<string, int> string2int;
map<int, string> int2string;
vector<node> Gang;

int change(string str){
    if(string2int.find(str) != string2int.end())
        return string2int[str];
    string2int[str] = numPerson;
    int2string[numPerson] = str;
    return numPerson++;
}

void init(){
    for(int i = 0; i < numPerson; ++i){
        int total = 0;
        for(int j = 0; j < numPerson; ++j){
            total += G[i][j];
        }
        totalMin[i] = total;
    }
}

node BFS(int root){
    int minute = 0, head = root, num = 0;
    queue<int> q;
    q.push(root);
    vis[root] = true;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        ++num;
        if(totalMin[top] > totalMin[head])
            head = top;
        for(int i = 0; i < numPerson; ++i){
            if(G[top][i] != 0){
                if(vis[i] == false){
                    q.push(i);
                    vis[i] = true;
                }
                minute += G[top][i];
                G[top][i] = G[i][top] = 0;
            }
        }
    }
    node Gan;
    Gan.num = num;
    Gan.head = int2string[head];
    Gan.totalMin = minute;
    return Gan;
}

void func(){
    init();
    for(int i = 0; i < numPerson; ++i){
        if(vis[i] == false){
            node temp = BFS(i);
            if(temp.num > 2 && temp.totalMin > k)
                Gang.push_back(temp);
        }
    }
}

bool cmp(node a, node b){
    return a.head < b.head;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        string str1, str2;
        int w;
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    func();
    cout << Gang.size() << endl;
    sort(Gang.begin(), Gang.end(), cmp);
    for(int i = 0; i < Gang.size(); ++i)
        cout << Gang[i].head << " " << Gang[i].num << endl;
    return 0;

}
