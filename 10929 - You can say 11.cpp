#include<stdio.h>
#include<stdlib.h>
int main() {
	while (1) {
		char n[1050];
		int i = 0, j = 0;
		while (scanf("%c", &n[i])) {
			i++;
			if (n[i - 1] == '\n') {
				break;
			}
		}
		while (n[j] == '0') {
			j++;
			if (n[j] == '\n') {
				return 0;
			}
		}
		int  odd = 0, even = 0;
			while (j < i - 1) {
				if ((n[j] - '0') >= 0 && (n[j] - '0') <= 9) {
					if (j % 2 != 0) {
						odd += (n[j] - '0');
					}
					else {
						even += (n[j] - '0');
					}
				}
				j++;
			}

			for (j = 0; j < i - 1; j++) {
				if (n[j] != ' ') {
					printf("%c", n[j]);
				}
			}
			if ((abs(odd - even)) % 11 == 0) {
				printf(" is a multiple of 11.\n");
			}
			else {
				printf(" is not a multiple of 11.\n");
			}
	}
}