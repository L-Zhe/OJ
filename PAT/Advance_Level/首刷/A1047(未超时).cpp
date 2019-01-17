#include<vector>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct name
{
	char na[5];
};
vector<name> ans[2510];

bool cmp(name n1, name n2)
{
	return strcmp(n1.na, n2.na) < 0;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		name stu;
		scanf("%s", stu.na);
		int c;
		scanf("%d", &c);
		for (int j = 1; j <= c; j++)
		{
			int val;
			scanf("%d", &val);
			ans[val].push_back(stu);
		}
	}
	for (int i = 1; i <= k; i++)
	{
		sort(ans[i].begin(), ans[i].end(), cmp);
		printf("%d %d\n", i, ans[i].size());
		for (int j = 0; j != ans[i].size(); j++)
		{
			printf("%s\n", ans[i][j].na);
		}
	}
	

}