#include<iostream>
#include<cstring>
using namespace std;

struct bign{
	int d[20];
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

bign rchange(bign a){
	bign b;
	b.len = a.len;
	for(int i = 0; i < a.len; ++i){
		b.d[i] = a.d[a.len - 1 - i];
 	}
 	return b;
}

bool judge(bign a){
	if(a.len == 1)	return true;
	for(int i = 0; i <= a.len / 2; ++i){
		if(a.d[i] != a.d[a.len - 1  - i])
			return false;
	}
	return true;
}

bign add(bign a, bign b){
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; ++i){
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0){
		c.d[c.len++] = carry;
	}
	return c;
}

int main(){
	int n;
	char s[11];
	scanf("%s%d", s, &n);
	bign a = change(s);
	int cnt = 0;
	while(!judge(a) && cnt < n){
			bign b = rchange(a);
			a = add(a, b);
			cnt++;
	}
	for(int i = a.len - 1; i >= 0; --i)
		printf("%d", a.d[i]);
	printf("\n%d", cnt);
	return 0;
	
}
