#include<iostream>
#include<cstring>
using namespace std;

const int Big = 110;
struct node{
	char name[11], id[11];
	int grade;
	node(char _n[], char _id[], int _grade){
		strcpy(name, _n);
		strcpy(id, _id);
		grade = _grade;
	}
	node(int _grade): grade(_grade){} 
};


int main(){
	int n;
	scanf("%d", &n);
	node bmin(Big);
	node gmax(-1);
	for(int i = 0; i < n; ++i){
		char name[11], id[11], gender;
		int grade;
		scanf("%s %c %s %d", name, &gender, id, &grade);
		node temp(name, id, grade);
		if(gender == 'M'){
			if(temp.grade < bmin.grade){
				bmin = temp;
			}
		}else{
			if(temp.grade > gmax.grade){
				gmax = temp;
			}
		}
	}
	bool flag = true;
	if(gmax.grade != -1){
		printf("%s %s\n", gmax.name, gmax.id);
	}else{
		printf("Absent\n");
		flag = false;
	}
	if(bmin.grade != Big){
		printf("%s %s\n", bmin.name, bmin.id);
	}else{
		printf("Absent\n");
		flag = false;
	}
	if(flag){
		printf("%d", gmax.grade - bmin.grade);
	}else{
		printf("NA");
	}
	return 0;
}
