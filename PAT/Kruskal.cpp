const int maxv;
const int maxe;
struct edge{
	int u, v;
	int cost;
}e[maxe];
bool cmp(edge a, edge b){
	return a.cost < b.cost;
}

int father[maxv];
int findFather(int a){
	int x = a;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int temp = father[a];
		father[a] = x;
		a = temp;
	}
	return x;
}

int Kruskal(int n, int m){	//n顶点数， m边数;
	int ans= 0, num_edge = 0;
	for(int i = 0; i < m; ++i)
		father[i] = i;
	sort(e, e + m, cmp);
	for(int i = 0; i < m; ++i){
		int fu = findFather(e[i].u);
		int fv = findFather(e[i].v);
		if(fu != fv){
			father[fv] = fu;
			ans += e[i].cost;
			num_edge++;
			if(num_edge == n - 1)
				break;
		}
	}
}
