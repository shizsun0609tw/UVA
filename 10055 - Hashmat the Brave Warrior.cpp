#include<stdio.h>
int main() {
	long long a, b;
	while (scanf("%lld%lld", &a, &b) != EOF) {
		if (b - a < 0) {
			printf("%lld\n", a - b);
		}
		else {
			printf("%lld\n", b - a);
		}
	}
	return 0;
}
