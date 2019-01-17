/*===================================================================================
A1016 Phone Bills (25)（25 分）提问
=====================================================================================
A long-distance telephone company charges its customers by the following rules:
Making a long-distance call costs a certain amount per minute, depending on the
time of day when the call is made. When a customer starts connecting a long-distance
call, the time will be recorded, and so will be the time when the customer hangs
up the phone. Every calendar month, a bill is sent to the customer for each minute
called (at a rate determined by the time of day). Your job is to prepare the bills
for each month, given a set of phone call records.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure,
and the phone call records.
The rate structure consists of a line with 24 non-negative integers denoting the
toll (cents/minute) from 00:00 - 01:00, the toll from 01:00
02:00, and so on for each hour in the day.
The next line contains a positive number N (<= 1000), followed by N lines of records.
Each phone call record consists of the name of the customer (string of up to 20
characters without space), the time and date (mm:dd:hh:mm), and the word "on-line"
or "off-line".
For each test case, all dates will be within a single month. Each "on-line" record
is paired with the chronologically next record for the same customer provided it
is an "off-line" record. Any "on-line" records that are not paired with an "off-line"
record are ignored, as are "off-line" records not paired with an "on-line" record.
It is guaranteed that at least one call is well paired in the input. You may assume
that no two records for the same customer have the same time. Times are recorded
using a 24-hour clock.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, you must print a phone bill for each customer.
Bills must be printed in alphabetical order of customers' names. For each customer,
first print in a line the name of the customer and the month of the bill in the
format shown by the sample. Then for each time period of a call, print in one line
the beginning and ending time and date (dd:hh:mm), the lasting time (in minute)
and the charge of the call. The calls must be listed in chronological order. Finally,
print the total charge for the month in the format shown by the sample.
-------------------------------------------------------------------------------------
Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line

Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
===================================================================================*/


#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	char name[22];
	int mo, d, m, h;
	bool flag;
};
vector<node> his;
int p[24];
int n;

bool cmp(node a, node b){
	if(strcmp(a.name, b.name) != 0)
		return strcmp(a.name, b.name) < 0;
	else if(a.mo != b.mo)
		return a.mo < b.mo;
	else if(a.d != b.d)
		return a.d < b.d;
	else if(a.h != b.h)
		return a.h < b.h;
	else 
		return a.m < b.m;
}

int computer(int d1, int h1, int m1, int d2, int h2, int m2){
	int n = (d2 - d1) * 24 * 60 + (h2 - h1) * 60 + m2 - m1;
	int ans = 0, price = 0;
	for(int i = 0; i < n; ++i){
		price += p[h1];
		ans++;
		m1++;
		if(m1 == 60){
			m1 = 0;
			h1 ++;
		}
		if(h1 == 24){
			h1 = 0;
			d1 ++;
		}
	}
	printf("%d", ans);
	return price;
}

int main(){
	//freopen("data.txt", "r", stdin);
	for(int i = 0; i < 24; ++i){
		scanf("%d", p + i);
	}
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		node temp;
		char f[10];
		scanf("%s %d:%d:%d:%d %s", temp.name, &temp.mo, &temp.d, &temp.h, &temp.m, f);
		if(strcmp(f, "on-line") == 0)
			temp.flag = true;
		else
			temp.flag = false;
		his.push_back(temp);
	}
	
//有效性检查
	sort(his.begin(), his.end(), cmp);
	int i = 0;
	while(i < his.size()){
		if(strcmp(his[i].name, his[i+1].name) == 0 && his[i].flag == true && his[i+1].flag == false){
			i += 2;
		}
		else{
			his.erase(his.begin() + i);
		}
	}
/* 	for(int i = 0; i < his.size(); ++i)
		cout << his[i].name << " " << his[i].mo << ":" << his[i].d << ":" << his[i].h << ":" << his[i].m << " " << his[i].flag << endl; */
	
//output
	char d[22];
	int total = 0;
	for(int i = 0; i < his.size();){
		if(strcmp(d, his[i].name) == 0){
			int d1 = his[i].d, h1 = his[i].h, m1 =his[i].m;
			int d2 = his[i+1].d, h2 = his[i+1].h, m2 = his[i+1].m;
			printf("%02d:%02d:%02d ", d1, h1, m1);
			printf("%02d:%02d:%02d ", d2, h2, m2);
			int temp = computer(d1, h1, m1, d2, h2, m2);
			total += temp;
			printf(" $%.2f\n", (double)temp/100);
			i += 2;
		}
		else{
			if(i != 0)
				printf("Total amount: $%.2f\n", (double)total/100);
			printf("%s %02d\n", his[i].name, his[i].mo);
			total = 0;
			strcpy(d, his[i].name);
		}
	}
	printf("Total amount: $%.2f\n", (double)total/100);
	return 0;
	
}