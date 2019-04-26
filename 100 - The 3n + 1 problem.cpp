#include<stdio.h>
int main() {
	int inputA, inputB;
	while (scanf("%d%d", &inputA, &inputB) != EOF) {
		int i, ans = 0;
		printf("%d %d ", inputA, inputB);
		if (inputA > inputB) {
			int temp = inputB;
			inputB = inputA;
			inputA = temp;
		}
		for (i = inputA; i <= inputB; i++) {
			int num = i, count = 1;
			while (num != 1) {
				if (num % 2 == 1) {
					num = 3 * num + 1;
					count++;
				}
				else if(num % 2 == 0) {
					num /= 2;
					count++;
				}
			}
			if (count > ans) {
				ans = count;
			}
			count = 1;
		}	
		printf("%d\n", ans);
	}

	return 0;
}