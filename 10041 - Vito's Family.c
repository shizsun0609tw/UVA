#include<stdio.h>
int main() {
	int n, num, a[30000], i, j;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &num);
		for (i = 0; i < num; i++) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < num; i++) {
			for (j = 0; j < num - 1 - i; j++) {
				if (a[j] > a[j + 1]) {
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
		int mid = num / 2, sum = 0;
		for (i = 0; i < mid; i++) {
			sum += a[mid] - a[i];
		}
		for (i = mid + 1; i < num; i++) {
			sum += a[i] - a[mid];
		}
		printf("%d\n", sum);
	}
	return 0;
}

