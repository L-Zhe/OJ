#include<iostream>
#include<queue>
using namespace std;

int g[1290][130][61];
bool vis[1290][130][61];
int m, n, l, t;
struct node{
	int x, y, z;
	node(int _x, int _y, int _z): x(_x), y(_y), z(_z){}
};
int x[6] = {1, -1, 0, 0, 0, 0};
int y[6] = {0, 0, 1, -1, 0, 0};
int z[6] = {0, 0, 0, 0, 1, -1};

bool judge(int x, int y, int z){
	if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l)
		return false;
	if(vis[x][y][z])	return false;
	if(!g[x][y][z])	return false;
	return true;
}

int bfs(node a){
	int cnt = 0;
	queue<node> q;
	q.push(a);
	vis[a.x][a.y][a.z] = true;
	while(!q.empty()){
		node top = q.front();
		q.pop();
		++cnt;
		for(int i = 0; i < 6; ++i){
			int newX = top.x + x[i];
			int newY = top.y + y[i];
			int newZ = top.z + z[i];
			if(judge(newX, newY, newZ)){
				q.push(node{newX, newY, newZ});
				vis[newX][newY][newZ] = true;
			}
		}
	}
	if(cnt >= t)	return cnt;
	else 	return 0;
}

int BFS(){
	int total = 0;
	for(int i = 0; i < l; ++i)
		for(int j = 0; j < m; ++j)
			for(int k = 0; k < n; ++k)
				if(!vis[j][k][i] && g[j][k][i])
					total += bfs(node{j, k, i});
	return total;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for(int i = 0; i < l; ++i)
		for(int j = 0; j < m; ++j)
			for(int k = 0; k < n; ++k)
				scanf("%d", &g[j][k][i]);
	printf("%d", BFS());
	return 0;
}
