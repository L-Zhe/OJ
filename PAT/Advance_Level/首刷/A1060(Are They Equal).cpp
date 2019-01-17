/*===================================================================================
A1060 Are They Equal (25)（25 分）
=====================================================================================
If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9
are considered equal since they are both saved as 0.123*10^5^ with simple chopping.
Now given the number of significant digits on a machine and two float numbers, you
are supposed to tell if they are treated equal in that machine.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case which gives three numbers N, A and B, where
N (<100) is the number of significant digits, and A and B are the two float numbers
to be compared. Each float number is non-negative, no greater than 10^100^, and
that its total digit number is less than 100.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in a line "YES" if the two numbers are treated equal,
and then the number in the standard form "0.d~1~...d~N~*10\^k" (d~1~>0 unless the
number is 0); or "NO" if they are not treated equal, and then the two numbers in
their standard form. All the terms must be separated by a space, with no extra space
at the end of a line.
Note: Simple chopping is assumed without rounding.
-------------------------------------------------------------------------------------
Sample Input 1:
3 12300 12358.9

Sample Output 1:
YES 0.123*10^5
------------------
Sample Input 2:
3 120 128

Sample Output 2:
NO 0.120*10^3 0.128*10^3
===================================================================================*/

/*
本题附加测试点
4 0000 0000.00
4 00123.5678 0001235
3 0.0520 0.0521
4 00000.000000123 0.0000001230
3 0.000 0
4 123.0678 123
3 123.5678 123
4 123.5678 123.5
5 0010.013 10.012
4 00100.00000012 100.00000013
*/

/*
思路：
1.先计算换算成科学计数法后的幂
2.把开头的0和小数点都删除，从第一个非零位开始向后比较r位，如果有一个字符串位数不足，
	那么另一个字符串剩下的有效位都要是‘0’；
3.只有1、2成立，才相等，否则输出不相等；
*/

#include<iostream>
#include<string>
using namespace std;

int r;
double num1, num2;
string st1, st2;

void init(string &s){
	while(s[0] == '0'){
		s.erase(s.begin());
	}
}

int count(string &s){
	int ans = 0, index = 1;
	int i = 0;
	while(i < s.size() && s[i] == '0'){
		++i;
	}
	if(s[i] != '.'){							//大等于1
		while(i < s.size() && s[i] != '.'){		//计算.前的有效位数
			++ans;
			++i;
		}
		if(i < s.size() && s[i] == '.')
			s.erase(s.begin() + i);				//顺带删除.方便后续操作
	}
	else{										//小于1
		index = -1;
		s.erase(s.begin() + i);					//先删除.
		while(i < s.size() && s[i] == '0'){		//找到小数第一个非0有效位
			ans++;
			++i;
		}
		if(i == s.size())						//若0.000则ans = 0
			ans = 0;
	}
	return index * ans;
}

bool judge(){
	int i = 0, num = r;
	while(i < st1.size() && i < st2.size() && num > 0){
		if(st1[i] != st2[i])
			return false;
		++i;
		--num;
	}
	while(i < st1.size() && num > 0){
		if(st1[i] != '0')
			return false;
		++i;
		--num;
	}
	while(i < st2.size() && num > 0){
		if(st2[i] != '0')
			return false;
		++i;
		--num;
	}
	return true;
}

void print(string s){
	printf("0.");
	int i = 0;
	int num = r;
	while(i < s.size() && num > 0){
		printf("%c", s[i]);
		++i;
		--num;
	}
	while(num > 0){
		printf("0");
		--num;
	}
	printf("*10^");
}

int main(){
	cin >> r >> st1 >> st2;
	if(r == 0){
		printf("0*10^0");
		return 0;
	}
	//num1 = str2int(st1);
	//num2 = str2int(st2);
	//cout << "1" << " " << num1 << " " << num2 << endl;
	int r1 = count(st1);
	int r2 = count(st2);
	//cout << "2" << " " << r1 << " " << r2 << endl;
	init(st1);
	init(st2);
	//cout << "3" << endl;
	if(r1 == r2 && judge()){
		printf("YES ");
		print(st1);
		printf("%d", r1);
	}
	else{
		printf("NO ");
		print(st1);	printf("%d", r1);
		printf(" ");
		print(st2); printf("%d", r2);
	}
	printf("\n");
	return 0;
}