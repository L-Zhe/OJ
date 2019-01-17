#include<iostream>
#include<algorithm>
using namespace std;

int a[55], n[55], temp[55];
int k;

void print(){
	for(int i = 1; i <= 54; ++i){
		int index = (a[i] - 1) / 13;
		int num = a[i] % 13;
		if(num == 0)	num = 13;	
		if(i != 1)	printf(" ");
		if(index == 0)	printf("S");
		else if(index == 1)	printf("H");
		else if(index == 2)	printf("C");
		else if(index == 3)	printf("D");
		else printf("J");
		printf("%d", num);
	}
}

void init(){
	for(int i = 0; i < 55; ++i){
		a[i] = i;
	}
}

int main(){
	init();
	scanf("%d", &k);
	for(int i = 1; i <= 54; ++i){
		scanf("%d", n + i);
	}
	for(int i = 0; i < k; ++i){
		for(int v = 1; v <= 54; ++v){
			int u = n[v];
			temp[u]	= a[v];
		}
		for(int j = 1; j <= 54; ++j)
			a[j] = temp[j];
	}
	print();
	return 0;
}
