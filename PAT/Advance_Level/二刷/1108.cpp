//88.是合法数
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

int n, cnt = 0;
double ans = 0;

double change(char* st){
	double num1 = 0, num2 = 0;
	int i = 0, index = 1;
	if(st[0] == '-'){
		index = -1;
		i = 1;
	}
	for(; i < strlen(st); ++i){
		if(st[i] == '.')	break;
		num1 = num1 * 10 + st[i] - '0';
	}
	for(int j = strlen(st) - 1; j > i; --j){
		num2 = num2 * 0.1 + st[j] - '0';
	}
	return index * (num1 + 0.1 * num2);
}

bool judge(char* st){
	if((st[0] < '0' || st[0] > '9') && (st[0] != '-' && st[0] != '+'))
        return false;
	int cntD = 0, degree = -1;
	for(int i = 1; i < strlen(st); ++i){
		if(st[i] == '.'){
			degree = i;
			//if(degree == strlen(st) - 1)	return false;
			++cntD;
			if(cntD > 1)	return false; 
		}	
		if(!(st[i] >= '0' && st[i] <= '9') && st[i] != '.')
			return false;
	}
	if(degree != -1){
		if(strlen(st) - 1 - degree > 2)	return false;
	}
	double num = change(st);
	if(num > 1000 || num < -1000)	return false;
	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		char st[100];
		scanf("%s", st);
		if(judge(st)){
			++cnt; 
			ans += change(st);
		}else{
			printf("ERROR: %s is not a legal number\n", st);
		}
	}
	if(cnt != 1)
		printf("The average of %d numbers is ", cnt);
	else
		printf("The average of %d number is ", cnt);
	if(cnt != 0)	printf("%.2f\n", ans / cnt);
	else	printf("Undefined\n");
	return 0;
}
