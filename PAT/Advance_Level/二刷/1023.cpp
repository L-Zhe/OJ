#include<iostream>
#include<cstring>
using namespace std;

struct bign{
	int d[30];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char s[]){
	bign a;
	a.len = strlen(s);
	for(int i = 0; i < a.len; ++i){
		a.d[i] = s[a.len - 1 - i] - '0';
	}
	return a;
}

bign multi(bign a, int b){
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len; ++i){
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0){
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

bool judge(bign a, bign b){
	if(a.len != b.len)	return false;
	int h[10];
	for(int i = 0; i < a.len; ++i){
		int index = a.d[i];
		++h[index];
	}
	for(int i = 0; i < b.len; ++i){
		int index = b.d[i];
		if(h[index] == 0)	return false;
		--h[index];
	}
	return true;
}

void print(bign a){
	for(int i = a.len - 1; i >= 0; --i)
		printf("%d", a.d[i]);
}

int main(){
	char s[21];
	scanf("%s", s);
	bign a = change(s);
	bign b = multi(a, 2);
	if(judge(a, b))	printf("Yes\n");
	else	printf("No\n");
	print(b);
	return 0;
}
