/*===================================================================================
A1082 Read Number in Chinese (25)（25 分）
=====================================================================================
Given an integer with no more than 9 digits, you are supposed to read it in the
traditional Chinese way. Output "Fu" first if it is negative. For example, -123456789
is read as "Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu".
Note: zero ("ling") must be handled correctly according to the Chinese tradition.
For example, 100800 is "yi Shi Wan ling ba Bai".
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case, which gives an integer with no more than
9 digits.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in a line the Chinese way of reading the number. The characters
are separated by a space and there must be no extra space at the end of the line.
-------------------------------------------------------------------------------------
Sample Input 1:
-123456789

Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
------------------
Sample Input 2:
100800

Sample Output 2:
yi Shi Wan ling ba Bai
===================================================================================*/

#include<iostream>
#include<string> 
#include<vector>
using namespace std;

string s1[10] = {"ling", "yi", "er","san", "si", "wu", "liu", "qi", "ba", "jiu"};
string s2[10] = {"", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};
int s3[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int n;
vector<int> ans;
vector<string> out;

int main(){
	cin >> n;
	if(n == 0){
		cout << "ling";
		return 0;
	}
	if(n < 0){
		out.push_back("Fu");
		n *= -1;
	}
	
	//是否要输出Wan/Yi 
	s3[8] = n / 100000000;
	s3[4] = n /10000 - n / 100000000 * 10000; 
	
	while(n > 0){ 
		ans.push_back(n % 10);
		n /= 10;
	}
	
	//把低位的0去除
	for(int i = 0; i < ans.size(); ++i){
		if(ans[i] != 0)	break;
		ans[i] = -1;
	}
	
	bool zf = false;//表示是否欠着0没有输出 
	for(int i = ans.size() - 1; i >= 0; --i){
		if(ans[i] > 0){
			if(zf)	out.push_back("ling");//遇到非零数，输出欠着的0 
			zf = false;
			out.push_back(s1[ans[i]]);
			if(i != 0)	out.push_back(s2[i]);
		}
		else{
			if(s3[i] != 0){
				out.push_back(s2[i]); // 碰到要输出Yi或Wan，则欠着的0清零，防止出现ling Wan的现象 
				zf = false;
			}
			else if(ans[i] == 0) 
				zf = true;
		}
	}
	bool flag = false;
	for(int i = 0; i < out.size(); ++i){
			if(flag)	cout << " ";
			flag = true;
			cout << out[i];
	}
	return 0;
}