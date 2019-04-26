#include<stdio.h>
#include<stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char a[3010][20];
		int b[3010], c[3010];
		int k, num;
		scanf("%d %d", &num, &k);
		for (int i = 0; i < num; i++) {
			scanf("%s %d", &a[i],&b[i]);
		}
		for (int i = 0; i < num; i++) {
			c[i] = b[i];
		}

		int now = 0;
		for (int g = 0; g < k; g++) {
			int hold = 0;
			for (int i = 0; i < num; i++) {
				if (b[i] < b[hold]) {
					hold = i;
				}
			}
			now = b[hold];
			b[hold] += c[hold];
			printf("%d %s\n", now, a[hold]);
		}
	}
	return 0;
}