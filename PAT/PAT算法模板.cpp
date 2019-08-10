//AVL
struct node{
	int data, height;
	node *left, *right;
	node(int x){
		height = 1;
		left = NULL;
		right = NULL;
		data = x;
	}
};

int getHeight(node* root){
	if(root == NULL)	return 0;
	return root->height;
}

int getBalancrFac(node* root){
	return getHeight(root->left) - getHeight(root->right);
}

void updateHeight(node* root){
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

void R(node*& root){
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void L(node*& root){
	node* temp = root->right;
	root->right = tmep->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node*& root, int x){
	if(root == NULL){
		root = new node(x);
		return;
	}
	if(x < root->data){
		insert(root->left, x);
		updateHeight(root);
		if(getBalanceFac(root) == 2){
			if(getBalanceFac(root->left) == 1){
				R(root);
			}else if(getBalanceFac(root->left) == -1){
				L(root->left);
				R(root);
			}
		}
	}else if(x > root->data){
		insert(root->right, x);
		updateHeight(root);
		if(getBalanceFac(root) == -2){
			if(getBalanceFac(root->right) == -1){
				L(root);
			}else if(getBalanceFac(root->right) == 1){
				R(root->right);
				L(root);
			}
		}
	}
}

node* creat(int a[], int n
	node* root = NULL;
	for(int i = 0; i < n; ++i){
		insert(root, a[i]);
	}
	return root;
}

//HEAP
void downAdjust(int low, int high){
	int i = low, j = 2 * i;
	while(j <= high){
		if(j + 1 <= high && heap[j + 1] > heap[j])
			++j;
		if(heap[j] > heap[i]){
			swap(heap[j], heap[i]);
			i = j;
			j = 2 * i;
		}else{
			break;
		}
	}
}

void upAdjust(int low, int high){
	int i = high, j = i / 2;
	while(j >= low){
		if(heap[j] < heap[i]){
			swap(heap[i], heap[j]);
			i = j;
			j = i / 2;
		}else{
			break;
		}
	}
}

void creatHeap(){
	for(int i = n / 2; i >= 1; --i){
		downAdjust(i, n);
	}
}

void deleteTop(){
	heap[1] = heap[n--];
	downAdjust(1, n);
}

void insert(int x){
	heap[++n] = x;
	upAdjust(1, n);
}

void heapSort(){
	creatHeap();
	for(int i = n, i >= 1; --i){
		swap(heap[1], heap[i]);
		downAdjust(1, i - 1);
	}
}

//Union
void init(){
	for(int i = 0; i < n; ++i)
		father[i] = i;
}

int fiindFather(int a){
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

void Union(int a, int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa != fb)
		father[fa] = fb;
}

//Dijkstra
void Dijkstra(int st){
	fill(d, d + maxn, inf);
	memset(vis, false, sizeof(vis));
	d[st] = 0;
	for(int i = 0; i < n; ++i){
		int u = -1, MIN = inf;
		for(int j = 0; j < n; ++j){
			if(!vis[j] && d[j] < MIN)
				MIN = d[u = j];
		}
		if(u == -1)	break;
		vis[u] = true;
		for(int v = 0; v < n; ++v){
			if(!vis[v])
				d[v] = MIN(d[v], d[u] + g[u][v]);
		}
	}
}

//SPFA
bool SPFA(int st){
	fill(d, d + maxn, inf
	memset(num, 0, sizeof(num));
	memset(inq, false, sizeof(inq));
	d[st] = 0;
	queue<int> q;
	q.push(st);
	inq[st] = true;
	++num[st];
	while(!q.empty()){
		int u = q.front();
		q.pop();
		inq[u] = false;
		for(int i = 0; i < adj[u].size; ++i){
			int v = adj[u][i].v, dis = adj[u][i].dis;
			if(d[v] > d[u] + dis){
				d[v] = d[u] + dis;
				if(!inq[v]){
					q.push(v);
					inq[v] = true;
					++num[v];
					if(num[v] >= n)	return false;
				}
			}
		}
	}
	return true;
}

//Bellman-ford
bool bellman(int st){
	fill(d, d + maxn, inf);
	d[st] = 0;
	for(int i = 0; i < n; ++i){
		for(int u = 0; u < n; ++u){
			for(int j = 0; j < adj[u].size(); ++j){
				int v = adj[u][j].v, dis = adj[u][j].dis;
				d[v] = min(d[v], d[u] + dis;)
			}
		}
	
	for(int u = 0; u < n; ++u){
		for(int j = 0; j < adj[u].size(); ++j){
			int v = adj[u][j].v, dis = adj[u][j].dis;
			if(d[v] > d[u] + dis)	return false;
		}
	}
	return true;
}

//Floyd
void Floyd(){
	int num = 0;
	for(int k = 0; k < n; ++k)
		for(int u = 0; u < n; ++u)
			for(int v = 0; v < n; ++v)
				if(dis[u][v] > dis[u][k] + dis[k][v])
					dis[u][v] = dis[u][k] + dis[k][v];
}

//Prim
bool Prim(int root){
	fill(d, d + maxn, inf);
	memset(vis, false, sizeof(vis));
	int ans;
	for(int i = 0; i < n; ++i){
		int u = -1, MIN = inf;
		for(int j = 0; j < n; ++j){
			if(!vis[j] && d[v] < MIN)
				MIN = d[u = j];
		}
		if(u == -1)	break;
		vis[u] = true;
		ans += d[u];
		for(int v = 0; v < n; ++v){
			if(!vis[v])
				d[v] = min(d[v], g[u][v]);
		}
	}
	return ans;
}

//Kruskal
struct edge{
	int u, v;
	int weight;
}e[maxn];
int father[maxn];
void init(){
	for(int i = 0; i < maxn; ++i)
		father[i] = i;
}

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

bool cmp(edge a, edge b){
	return a.weight < b.weight;
}

int Kruskal(){
	int ans = 0, num = 0;
	init();
	sort(e, e + m, cmp);
	for(int i = 0; i < m; ++i){
		int fu = findFather(e[i].u);
		int fv = findFather(e[i].v);
		if(fu != fv){
			ans += e[i].weight
			++num;
			father[fu] = fv;
			if(num == n - 1)	break;
		}
	}
	if(num != n - 1)	return -1;
	return ans;
}

//Topological
bool Topological(){
	int num = 0;
	queue<int> q;
	for(int i = 0; i < n; ++i){
		if(inDegree[i] == 0){
			q.push(i);
			++num;
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int j = 0; j < adj[u].size(); ++j){
			int v = adj[u][j];
			--inDegree[v];
			if(inDegree[v] == 0){
				q.push(v);
				++num;
			}
		}
	}
	if(num != n)	return false;
	else	return true;
}


// 先序中序建树
struct node{
	int data;
	 node *left, *right;
	 node(int x){
		 x = data;
	 }
};

node* creat(int preL, int preR, int inL, int inR){
	if(preL > preR)	return NULL;
	node* root = new node(pre[preL]);
	int mid;
	for(mid = inL, mid <= inR; ++mid){
		if(in[mid] == pre[preL])
			break;
	}
	int numLeft = mid - inL;
	root->left = creat(preL + 1, preL + numLeft, inL, mid - 1);
	root->right = creat(preL + numLeft + 1, mid + 1, inR);
	return root;
}

//埃拉斯托特尼素数塞法
void findPrime(){
	p[0] = p[1] = true;
	int len = 0;
	for(int i = 2; i < maxn; ++i){
		if(!p[i]){
			prime[len++] = i;
			for(int j = i + i; j < maxn; j += i){
				p[j] = true;
			}
		}
	}
}

//素数判定
bool isPrime(int n){
	if(n <= 1)	return false;
	int MAX = sqrt(n);
	for(int i = 0; i <= MAX; ++i){
		if(n % i != 0)	return false;
	}
	return true;
}

//最大公约数
int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}

//最小公倍数
int lcm(int a, int b){
	int d = gcd(a, b);
	return a / d * b;
}

//质因子分解
struct node{
	int p, cnt;
	node(){
		cnt = 0;
	}
}fac[maxn];
int len = 0;

void fac(int n){
	findPrime();
	int MAX = sqrt(n);
	int i = 0;
	while(Prime[i] <= MAX){
		if(n % Prime[i] == 0){
			fac[len].p = Prime[i];
			while(n % Prime[i] == 0){
				++fac[len].cnt;
				n /= Prime[i];
			}
			++len;
		}
	}
	if(n != 1){
		fac[len].p = n;
		fac[len++].cnt = 1;
	}
}
//分数四则运算
struct Fraction{
	int up, down;
};

Fraction reduction(Fraction result){
	if(result.down < 0){
		result.down *= -1;
		result.up *= -1;
	}
	if(result.up == 0){
		result.down = 1
	}else {
		int d = gcd(abs(result.up), result.down);
		result.up /= d;
		result.down /= d;
	}
	return result;
}

Fraction add(Fraction f1, Fraction f2){
	Fraction ans;
	ans.up = f1.up * f2.down + f2.up * f1.down;
	ans.down = f1.down * f2.down;
	return reduction(ans);
}

Fraction sub(Fraction f1, Fraction f2){
	
	Fraction ans;
	ans.up = f1.up * f2.down - f2.up * f1.down;
	ans.down = f1.down * f2.down;
	return reduction(ans);
}

Fraction multi(Fraction f1, Fraction f2){
	Fraction ans;
	ans.up = f1.up * f2.up;
	ans.down = f1.down * f2.down;
	return reduction(ans);
}

Fraction divide(Fraction f1, Fraction f2){
	Fraction ans;
	ans.up = f1.up * f2.down;
	ans.down = f1.down * f2.up;
	return reduction(ans);
}

void print(Faction r){
	if(r.down == 1)	printf("%d", r.up);
	else if(abs(r.up) > r.down)
		printf("%d %d/%d", r.up / r.down, abs(r.up) % r.down, r.down);
	else 
		printf("%d/%d", r.up, r.down);
}

//大整数运算
struct bign{
	int d[1000];
	int len;
	bign(){
		int len = 0;
		memset(d, 0, sizeof(d));
	}
};

bign change(char s[]){
	bign a;
	a.len = strlen(s);
	for(int i = 0; i < a.len; ++i)
		a.d[i] = s[a.len - i - 1] - '0';
	return a;
}

int compare(bign a, bign b){
	if(a.len < b.len)	return -1;
	else if(a.len > b.len)	return 1;
	else{
		for(int i . a.len - 1; i >= 0; --i){
			if(a.d[i] > b.d[i])	return 1;
			else if(a.d[i] < b.d[i])	return -1;
		}
	}
	return 0;
}

bign add(bign a, bign b){
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; ++i){
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0){
		c.d[c.len++] = carry;
	}
	return c;
}

bign sub(bign a, bign b){
	bign c;
	for(int i = 0; i < a.len || i < b.len; ++i){
		if(a.d[i] < b.d[i]){
			a.d[i] += 10;
			--a.d[i + 1];
		}
		c.d[c.len++] = a.d[i] = b.d[i];
	}
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0)
		--c.len;
	return c;
}

bign multi(bign a, int b){
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len; ++i){
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0){
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

bign divide(bign a, ing b, int& r){
	bign c;
	c.len = a.len;
	for(int i = a.len - 1; i >= 0; --i){
		r = r * 10 + a.d[i];
		if(r < b)	c.d[i] = 0;
		else{
			c.d[i] = r / b;
			r %= b;
		}
	}
	while(c.len - 1 >= 1 && c.d[c,len - 1] == 0)
		--c.len;
	return c;
}

//Selection Sort
for(int i = 1; i < n; ++i){
	int temp = a[i], j = i;
	while(j > 0 && a[k - 1] > temp){
		a[j]  = a[j - 1];
		--j;
	}
	a[j] = temp;
}

//Merge Sort
void merge(int L1, int R1, int L2, int R2){
	int i = L1, j = L2;
	int temp[maxn], len = 0;
	while(i <= R1 && j <= R2){
		if(a[i] <= a[j])	temp[len++] = a[i++];
		else	temp[len++] = b[j++];
	}
	while(i <= R1)	temp[len++] = a[i++];
	while(j <= R2)	temp[len++] = b[j++]
	}
	for(int i = 0; i < len; ++i){
		a[L1 + i] = temp[i];
	}
}

void mergeSort(int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, mid + 1, right);
	}
}

//mergeSort非递归
void mergeSort(){
	for(int step = 2; step / 2 <= n; step *= 2){
		for(int i = 1; i <= n; i += step){
			//sort(a + i, a + min(i + step, n + 1));
			int mid = i + step / 2 - 1;
			if(mid + 1 <= n){
				merge(i, mid, mid + 1, mid(i + step - 1, n));
			}
		}
	}
}

//quickSort
srand((unsigned)time(NULL));
int randPartition(int left, int right){
	int p = (round(1.0 * rand()/RAND_MAX * (right - left) + left));
	swap(a[left], a[p]);
	int i = left;
	for(int j = left + 1; j <= right; ++j){
		if(a[j] < a[left])
			swap(a[j], a[++i]);
	}
	swap(a[left], a[i]);
	return i;
}

int randPartition(int left, int right){
	int p = (round(1.0 * rand()/RAND_MAX * (right - left) + left));
	swap(a[left], a[p]);
	int temp = a[left];
	while(left < right){
		while(left < right && a[right] > temp)	--right;
		a[left] = a[right];
		while(left < right && a[left] < temp)	++left;
		a[right] = a[left];
	}
	a[left] = temp;
	return left;
}

void quickSort(int left, int right){
	if(left < right){
		int pos = randPartition();
		quickSort(left, pos - 1);
		quick(pos + 1, right);
	}
}

//随机选择算法
int	randSelection(int left, int right, int k){
	if(left == right)	return a[left];
	int p = randPartition(left, right);
	int M = p - left + 1;
	if(k == M)	return A[p];
	if(k < M)	return randSelection(left, p - 1, k);
	else	return randSelection(lp + 1, right, k - M);
}