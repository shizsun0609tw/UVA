#include<stdio.h>
#include<string.h>
char a[500000];
int main() {
	int n;
	int count[30] = {};
	scanf("%d ", &n);
	while (n--) {
		fgets(a, sizeof(a), stdin);
		for (int i = 0; i < strlen(a); i++) {
			if (a[i] >= 'a' && a[i] <= 'z') {
				count[a[i] - 97]++;
			}
			else if (a[i] >= 'A' && a[i] <= 'Z') {
				count[a[i] - 65]++;
			}
			else {
				continue;
			}
		}
	}
	for (int gg = 1;gg == 1;) {
		int big = 0;
		int hold = 0;
		gg = 0;
		for (int i = 0; i < 26; i++) {
			if (count[i] > big) {
				big = count[i];
				hold = i;
				gg = 1;
			}
		}
		if (gg == 1) {
			printf("%c %d\n", hold + 65, count[hold]);
			count[hold] = 0;
		}
	}
	return 0;
}