#include<iostream>
#include<stack>
using namespace std;

int main(){
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	for(int i = 0; i < k; ++i){
		stack<int> s;
		s.push(0);
		int temp, index = 1;
		bool flag = true;
		for(int j = 0; j < n; ++j){
			scanf("%d", &temp);
			if(flag){
				if(s.top() != temp){
					if(s.top() > temp)	flag = false;
					else{
						while(s.top() < temp && index <= n){
							s.push(index++);
							if(s.size() > m + 1)	flag = false;
						}
					}
				}
				s.pop();
			}	
		}
		if(flag) printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}
