#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int day, p, P[105], i = 0, count = 0;
		scanf("%d", &day);
		scanf("%d", &p);
		while (p--) {
			scanf("%d", &P[i]);
			i++;
		}

		int j, k;
		for (j = 1; j <= day; j++) {
			if (j % 7 != 6 && j % 7 != 0) {
				for (k = 0; k < i; k++) {
					if (j % P[k] == 0) {
						count++;
						break;
					}
				}
			}
		}
		printf("%d\n", count);
	}

	return 0;
}