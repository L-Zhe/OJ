#include<iostream>
using namespace std;

typedef long long ll;
ll ca1, ca2, si1, si2, kn1, kn2;

int main(){
	scanf("%lld.%lld.%lld", &ca1, &si1, &kn1);
	scanf("%lld.%lld.%lld", &ca2, &si2, &kn2);
	ll kn = kn1 + kn2;
	ll si = si1 + si2 + kn / 29;
	kn %= 29;
	ll ca = ca1 + ca2 + si / 17;
	si %= 17;
	printf("%lld.%lld.%lld", ca, si, kn);
	return 0;
}
