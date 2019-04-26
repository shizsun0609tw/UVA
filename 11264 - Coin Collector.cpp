#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int num, a[1010], sum = 0, count = 1;
		scanf("%d", &num);
		for (int i = 0; i < num; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < num - 1; i++) { 
			if (sum + a[i] < a[i + 1]) {
				count++;
				sum += a[i];
			}
		}
		printf("%d\n", count);
	}
	return 0;
}