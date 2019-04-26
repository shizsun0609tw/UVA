#include<stdio.h>
#include<string.h>
void BanglaNumbers(long long n) {
	if (n >= 10000000) {
		BanglaNumbers(n / 10000000);
		n %= 10000000;
		printf(" kuti");
	}if (n >= 100000) {
		BanglaNumbers(n / 100000);
		n %= 100000;
		printf(" lakh");
	}if (n >= 1000) {
		BanglaNumbers(n / 1000);
		n %= 1000;
		printf(" hajar");
	}if (n >= 100) {
		BanglaNumbers(n / 100);
		n %= 100;
		printf(" shata");
	}if (n) {
		printf("% lld",n);
	}
}

int main() {
	long long a;
	int count = 0;
	while (scanf("%lld", &a) != EOF) {
		count++;
		printf("%4d.", count);
		if (a == 0)printf(" 0");
		else BanglaNumbers(a);
		printf("\n");
	}
	return 0;
}
