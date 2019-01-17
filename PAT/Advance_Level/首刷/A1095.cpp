/*===================================================================================
A1095 Cars on Campus (30)（30 分）提问
=====================================================================================
Zhejiang University has 6 campuses and a lot of gates. From each gate we can collect
the in/out times and the plate numbers of the cars crossing the gate. Now with all
the information available, you are supposed to tell, at any specific time point,
the number of cars parking on campus, and at the end of the day find the cars that
have parked for the longest time period.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case starts with two positive integers
N (<= 10000), the number of records, and K (<= 80000) the number of queries. Then
N lines follow, each gives a record in the format
plate_number hh:mm:ss status
where plate_number is a string of 7 English capital letters or 1-digit numbers;
hh:mm:ss represents the time point in a day by hour:minute:second, with the earliest
time being 00:00:00 and the latest 23:59:59; and status is either in or out.
Note that all times will be within a single day. Each "in" record is paired with
the chronologically next record for the same car provided it is an "out" record.
Any "in" records that are not paired with an "out" record are ignored, as are "out"
records not paired with an "in" record. It is guaranteed that at least one car is
well paired in the input, and no car is both "in" and "out" at the same moment.
Times are recorded using a 24-hour clock.
Then K lines of queries follow, each gives a time point in the format hh:mm:ss.
Note: the queries are given in ascending order of the times.
-------------------------------------------------------------------------------------
Output Specification:
For each query, output in a line the total number of cars parking on campus. The
last line of output is supposed to give the plate number of the car that has parked
for the longest time period, and the corresponding time length. If such a car is
not unique, then output all of their plate numbers in a line in alphabetical order,
separated by a space.
-------------------------------------------------------------------------------------
Sample Input:
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00

Sample Output:
1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09
===================================================================================*/


#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
	char id[10];
	int time;
	bool flag;
};
vector<node> rec;
vector<int> query;
vector<string> name;
int n, k;

bool cmp(node a, node b){
	if(strcmp(a.id, b.id) != 0)
		return strcmp(a.id, b.id) < 0;
	return a.time < b.time;
}

bool cmp2(node a, node b){
	return a.time < b.time;
}

bool cmp3(string a, string b){
	return a < b;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i){
		char id[10];
		int hh, mm, ss;
		char f[5];
		scanf("%s %d:%d:%d %s", id, &hh, &mm, &ss, f);
		node temp;
		strcpy(temp.id, id);
		temp.time = hh * 60 * 60 + mm * 60 + ss;
		if(strcmp(f, "in") == 0)
			temp.flag = true;
		else
			temp.flag = false;
		rec.push_back(temp);
	}
	for(int i = 0; i < k; ++i){
		int hh, mm, ss, temp;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		temp = hh * 60 * 60 + mm * 60 + ss;
		query.push_back(temp);
	}
	sort(rec.begin(), rec.end(), cmp);
	
/* 	cout << rec.size() << endl;
 	for(int i = 0; i < rec.size(); ++i)
		cout << rec[i].id << " " << rec[i].time << " " << rec[i].flag << endl;
	cout << "----------------" << endl;   */

//处理数据
	int i = 0;
	bool comp = false;
	char _id[10];
	while(i < rec.size()){
		if(rec[i].flag == true && strcmp(rec[i].id, rec[i+1].id) == 0 && rec[i + 1].flag == false)
			i += 2;
		else
			rec.erase(rec.begin() + i);
	}

//找到停车最长的
	char id[10];
	int _to = 0, to = 0;
	for(int i = 0; i < rec.size();){
		if(strcmp(id, rec[i].id) == 0){
			_to = _to + rec[i+1].time - rec[i].time;
			if(_to == to)
				name.push_back(rec[i].id);
			else if(_to > to){
				name.clear();
				name.push_back(rec[i].id);
				to = _to;
			}
			i += 2;
		}
		else{
			_to = 0;
			strcpy(id, rec[i].id);
		}
	}
	
/*   cout << rec.size() << endl;
	for(int i = 0; i < rec.size(); ++i)
		cout << rec[i].id << " " << rec[i].time << " " << rec[i].flag << endl;  */  
	sort(rec.begin(), rec.end(), cmp2);
	int j = 0, cnt = 0;
	for(int i = 0; i < query.size(); ++i){
		while(j < rec.size() && rec[j].time <= query[i]){
			if(rec[j].flag == true)
				cnt++;
			else cnt--;
			++j;
		}
		printf("%d\n", cnt);
	}
	sort(name.begin(), name.end(), cmp3);
	for(int i = 0; i < name.size(); ++i){
			cout << name[i] << " ";
	}
	printf("%02d:%02d:%02d", to / 3600, to / 60 % 60, to % 60);
	return 0;
}