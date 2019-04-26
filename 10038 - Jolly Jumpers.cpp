#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b) {
	int c = *(int*)a;
	int d = *(int*)b;
	if (c > d)return 1;
	if (c == d)return 0;
	else return -1;
}
int main() {
	int a[3010] = {};
	int n;
	while (scanf("%d", &n) != EOF) {
		int hold;
		scanf("%d", &hold);
		for (int i = 0; i < n - 1; i++) {
			int input;
			scanf("%d", &input);
			a[i] = abs(hold - input);
			hold = input;
		}
		qsort((void*)a, n - 1, sizeof(int), compare);
		int gg = 0;
		for (int i = 0,count = 1; i < n - 1 && a[i] == count; i++,count++) {
			gg = count;
			continue;
		}
		if (gg == n - 1)printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}