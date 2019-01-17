/*===================================================================================
A1091 Acute Stroke (30)（30 分）
=====================================================================================
One important factor to identify acute stroke (急性脑卒中) is the volume of the
stroke core. Given the results of image analysis in which the core regions are identified
in each MRI slice, your job is to calculate the volume of the stroke core.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains 4
positive integers: M, N, L and T, where M and N are the sizes of each slice (i.e.
pixels of a slice are in an M by N matrix, and the maximum resolution is 1286 by
128); L (<=60) is the number of slices of a brain; and T is the integer threshold
(i.e. if the volume of a connected core is less than T, then that core must not
be counted).
Then L slices are given. Each slice is represented by an M by N matrix of 0's and
1's, where 1 represents a pixel of stroke, and 0 means normal. Since the thickness
of a slice is a constant, we only have to count the number of 1's to obtain the
volume. However, there might be several separated core regions in a brain, and only
those with their volumes no less than T are counted. Two pixels are "connected"
and hence belong to the same region if they share a common side, as shown by Figure
1 where all the 6 red pixels are connected to the blue one.
\ Figure 1
-------------------------------------------------------------------------------------
Output Specification:
For each case, output in a line the total volume of the stroke core.
-------------------------------------------------------------------------------------
Sample Input:
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0

Sample Output:
26
===================================================================================*/

#include<iostream>
#include<queue>
using namespace std;

struct node{
	int x, y, z;
}; 
int pixel[1290][130][61];
bool inq[1290][130][61] = {false};
int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};
int m, n, l, t;

bool judge(int x, int y, int z){
	if(x >= m || x < 0 || y >= n || y < 0 || z >= l || z < 0)
		return false;
	if(inq[x][y][z] == true || pixel[x][y][z]  == 0)
		return false;
	return true;
} 

int BFS(int x, int y, int z){
	int total = 0;
	queue<node> q;
	node n;
	n.x = x, n.y = y, n.z = z;
	q.push(n);
	inq[x][y][z] = true;
	while(!q.empty()){
		node p = q.front();
		q.pop();
		total++;
		for(int i = 0; i < 6; ++i){
			int newX = p.x + X[i];
			int newY = p.y + Y[i];
			int newZ = p.z + Z[i];
			if(judge(newX, newY, newZ)){
				node temp;
				temp.x = newX;
				temp.y = newY;
				temp.z = newZ;
				q.push(temp);
				inq[newX][newY][newZ] = true;
			}
		}
	}
	if(total >= t)	return total;
	else return 0;
}

int main(){
	cin >> m >> n >> l >> t;
	for(int z = 0; z < l; ++z)
		for(int x = 0; x < m; ++x)
			for(int y = 0; y < n; ++y)
				scanf("%d", &pixel[x][y][z]);
	int ans = 0;
	for(int x = 0; x < m; ++x)
		for(int y = 0; y < n; ++y)
			for(int z = 0; z < l; ++z)
				if(pixel[x][y][z] == 1 && inq[x][y][z] == false)
					ans += BFS(x, y, z);
	cout << ans;
	return 0;
}