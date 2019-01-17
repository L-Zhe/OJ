#include<iostream>
#include<cstring>
using namespace std;

struct bign{
	int d[1010];
	int len;
	bign(){
		len = 0;
		memset(d, 0, sizeof(d));
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

bign add(bign a, bign b){
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; ++i){
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0)
		c.d[c.len++] = carry;
	return c;
}

bool judge(bign a){
	for(int i = 0; i <= a.len / 2; ++i){
		if(a.d[i] != a.d[a.len - 1 - i])
			return false;
	}
	return true;
}

void print(bign a){
	for(int i = a.len - 1; i >= 0; --i){
		printf("%d", a.d[i]);
	}
}

bign reve(bign s){
	bign a;
	a.len = s.len;
	for(int i = 0; i < a.len; ++i)
		a.d[i] = s.d[a.len - 1 - i];
	return a;
}

int main(){
	char n[1010];
	scanf("%s", n);
	bign a = change(n);
	int cnt = 0;
	while(!judge(a) && cnt < 10){
		bign b = reve(a);
		bign c = add(a, b);
		print(a); printf(" + "); print(b); printf(" = "); print(c); printf("\n");
		a = c;
		++cnt;
	}
	if(cnt == 10)	printf("Not found in 10 iterations.");
	else{
		print(a);
		printf(" is a palindromic number.");
	}
	return 0;
}
