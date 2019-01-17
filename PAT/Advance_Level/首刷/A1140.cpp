#include<iostream>
#include<string>
using namespace std;

const int maxn = 10;
int h[maxn];
int d, n;
string s, temp;

int main(){
	scanf("%d%d", &d, &n);
	int cnt = 0;
	temp += d + '0';
	while(cnt < n){
		s.clear();
		s = temp;
		cout << s << endl;
		int i = 0;
		temp.clear();
		while(i < s.size()){
			int num = s[i++] - '0';
			int count = 1;
			while(i < s.size() && s[i] - '0' == num){
				++count;
				++i;
			}
			temp += num + '0';
			temp += count + '0';
		}
		++cnt;
	}
	cout << s;
	return 0;
}
 
