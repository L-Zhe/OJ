#include<iostream>
using namespace std;

int main(){
	double ans = 1;
	int a[3];
	for(int i = 0; i < 3; ++i){
		double MAX = 0, temp, u = -1;
		for(int j = 0; j < 3; ++j){
			scanf("%lf", &temp);
			if(temp > MAX)	{
				MAX = temp;
				u = j;	
			}
		}
		ans *= MAX;
		a[i] = u;
	}
	for(int i = 0; i < 3; ++i){
		if(a[i] == 0)	printf("W ");
		else if(a[i] == 1)	printf("T ");
		else	printf("L ");
		
	}
	printf("%.2f", (ans * 0.65 - 1.0) * 2);
	return 0;
}
