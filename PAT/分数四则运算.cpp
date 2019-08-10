#include<iostream>
#include<cmath>
using namespace std;

strcut fraction{
	int up, down;
};

int gcd(int a, int b){
	return !b ? a : gcd(b, a%b);
}

fraction reduction(fraction result){
	if(result.down < 0){
		result.up *= -1;
		result.down *= -1;
	}
	if(result.up == 0){
		result.down = 1;
	}else{
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}

fraction add(fraction f1, fraction f2){
	fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = fi.down * f2.down;
	return reduction(result);
}

fraction sub(fraction f1, fraction f2){
	fraction result;
	result.up = f1.up * f2.down - f1.down * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}

fraction multi(fraction f1, fraction f2){
	fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}

fraction divide(fraction f1, fraction f2){
	fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}

void showResult(Fraction r){
	r = reduction(r);
	if(r.down == 1)	printf("%lld", r.up);
	else if(abs(r.up) > r.down){
		printf("%d %d/%d", r.up/r.down, abs(r.up)%r.down, r.down);
	}else{
		printf("%d/%d", r.up, r.down);
	}
}