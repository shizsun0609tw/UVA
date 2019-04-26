#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int num, count = 0;
		int a[60];
		scanf("%d", &num);
		
		for (int i = 0; i < num; i++)scanf("%d", &a[i]);
		
		for (int i = 0; i < num - 1; i++) {
			for (int j = i+1; j < num; j++) {
				if (a[i] > a[j]) {
					int temp = a[j];
					a[j] = a[i];
					a[i] = temp;
					count++;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n", count);
	}
	return 0;
}