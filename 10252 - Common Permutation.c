#include<stdio.h>
#include<string.h>
void bublesort(char A[]) {
	int i, j;
	for (i = 0; i < strlen(A); i++) {
		for (j = 0; j < strlen(A) - 1 - i; j++) {
			if (A[j] > A[j + 1]) {
				char temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}
int main() {
	char strA[1050], strB[1050], ans[1050];
	char trash;
	while (fgets(strA, sizeof(strA), stdin)) {
		fgets(strB, sizeof(strB), stdin);
		strA[strlen(strA) - 1] = '\0';
		strB[strlen(strB) - 1] = '\0';
		bublesort(strA);
		bublesort(strB);
		int i = 0, j = 0, k = 0;
		while (j != strlen(strB) && i != strlen(strA)) {
			if (strA[i] < strB[j]) {
				i++;
			}else if (strA[i] > strB[j]) {
				j++;
			}else {
					ans[k] = strA[i];
					k++;
					i++;
					j++;
			}
		}

		ans[k] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}
