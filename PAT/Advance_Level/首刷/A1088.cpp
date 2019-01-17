/*===================================================================================
A1088 Rational Arithmetic (20)£¨20 ·Ö£©
=====================================================================================
For two rational numbers, your task is to implement the basic arithmetics, that
is, to calculate their sum, difference, product and quotient.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case, which gives in one line the two rational
numbers in the format "a1/b1 a2/b2". The numerators and the denominators are all
in the range of long int. If there is a negative sign, it must appear only in front
of the numerator. The denominators are guaranteed to be non-zero numbers.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in 4 lines the sum, difference, product and quotient of
the two rational numbers, respectively. The format of each line is "number1 operator
number2 = result". Notice that all the rational numbers must be in their simplest
form "k a/b", where k is the integer part, and a/b is the simplest fraction part.
If the number is negative, it must be included in a pair of parentheses. If the
denominator in the division is zero, output "Inf" as the result. It is guaranteed
that all the output integers are in the range of long int.
-------------------------------------------------------------------------------------
Sample Input 1:
2/3 -4/2

Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
------------------
Sample Input 2:
5/3 0/6

Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
===================================================================================*/

#include<iostream>
#include<cmath>
using namespace std;

struct fra{
	long up, down;
};

long gcd(long a, long b){
	return !b ? a : gcd(b, a%b);
}

fra reduce(fra f){
	fra ans = f;
	if(ans.down < 0){
		ans.down *= -1;
		ans.up *= -1;
	}
	if(ans.up == 0){
		ans.down = 1;
	}else{
		long d = gcd(abs(ans.up), abs(ans.down));
		ans.up /= d;
		ans.down /= d;
	}
	return ans;
}

fra add(fra f1, fra f2){
	fra ans;
	ans.up = f1.up * f2.down + f2.up * f1.down;
	ans.down = f1.down * f2.down;
	return reduce(ans);
}

fra sub(fra f1, fra f2){
	fra ans;
	ans.up = f1.up * f2.down - f1.down * f2.up;
	ans.down = f1.down * f2.down;
	return reduce(ans);
}

fra multi(fra f1, fra f2){
	fra ans;
	ans.up = f1.up * f2.up;
	ans.down = f1.down * f2.down;
	return reduce(ans);
}

fra divide(fra f1, fra f2){
	fra ans;
	ans.up = f1.up * f2.down;
	ans.down = f1.down * f2.up;
	return reduce(ans);
}

void print(fra f){
	f = reduce(f);
	if(f.down == 1){
		if(f.up < 0)
			printf("(%ld)", f.up);
		else
			printf("%ld", f.up);
	}
	else{
		if(f.up >= 0){
			if(f.up < f.down)
				printf("%ld/%ld", f.up, f.down);
			else
				printf("%ld %ld/%ld", f.up/f.down, f.up%f.down, f.down);
		}
		else{
			if(abs(f.up) < f.down)
				printf("(%ld/%ld)", f.up, f.down);
			else
				printf("(%ld %ld/%ld)", f.up/f.down, abs(f.up)%f.down, f.down);
		}
	}
}

int main(){
	fra f1, f2;
	scanf("%ld/%ld %ld/%ld", &f1.up, &f1.down, &f2.up, &f2.down);
	reduce(f1);
	reduce(f2);
	print(f1); printf(" + "); print(f2); printf(" = "); print(add(f1, f2)); printf("\n");
	print(f1); printf(" - "); print(f2); printf(" = "); print(sub(f1, f2)); printf("\n");
	print(f1); printf(" * "); print(f2); printf(" = "); print(multi(f1, f2)); printf("\n");
	print(f1); printf(" / "); print(f2); printf(" = "); 
	if(f2.up == 0)
		printf("Inf");
	else
		print(divide(f1, f2));
	return 0;
}