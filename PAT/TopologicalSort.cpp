#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxv = 1000;
const int INF = 0X3FFFFFFF;
class Node{
public:
	int v;
	Node(int _v): v(_v){}
};
vector<Node> Adj[maxv];
queue<int> sort;
int inDegree[maxv];
bool inq[maxv];
int N, M;

bool TopologicalSort(){
	queue<int> Q;
	int ans = 0;
	for(int i = 0; i < N; ++i)
		if(inDegree[i] == 0)
			Q.push(i);	
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		ans++;
		sort.push(u);
		for(int j = 0; j < Adj[u].size(); ++j){
			int v = Adj[u][j].v;
			inDegree[v]--;
			if(inDegree[v] == 0)
				Q.push(v);
		}
	}
	if(ans == N)
		return true;
	else
		return false;
}

int main(){
	cin >> N >> M;
	fill(inDegree, inDegree + maxv, 0);
	for(int i = 0; i < M; ++i){
		int u, v;
		cin >> u >> v;
		Adj[u].push_back(Node(v));
		inDegree[v]++;
	}
	if(TopologicalSort()){
		while(!sort.empty()){
			cout << sort.front() << " ";
			sort.pop();
		}
	}
	else
		cout << "false";
	return 0;
}