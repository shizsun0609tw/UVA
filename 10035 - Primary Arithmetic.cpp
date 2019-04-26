#include<stdio.h>
int main() {
	long long a, b;
	while (scanf("%lld%lld", &a, &b)) {
		if (a == 0 && b == 0) {
			return 0;
		}
		else {
			int count = 0;
			int mod = 0;
			while (a > 0 || b > 0) {
				if (a % 10 + b % 10 + mod >= 10) {
					count++;
					mod = 1;
				}
				else {
					mod = 0;
				}
				a /= 10;
				b /= 10;
			}
			if (count == 0) {
				printf("No carry operation.\n");
			}
			else if (count == 1) {
				printf("1 carry operation.\n");
			}
			else {
				printf("%d carry operations.\n", count);
			}
		}
	}
}