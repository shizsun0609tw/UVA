#include<stdio.h>
void input(int r, int c, int a[][100]) {
	char input;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			do {						
				scanf("%c", &input);
			} while (input == '\n');		//處裡換行
			if (input == '@') {
				a[i][j] = 1;
			}
			else {
				a[i][j] = 0;				//如果是@陣列內為1 不是為0
			}
		}
	}
}
void cheak(int r, int c, int i, int j, int a[][100]) {
	if (j != c) {
		if (a[i][j + 1] == 1){
			a[i][j + 1] = 0;
			cheak(r, c, i, j + 1, a);
		}
	}
	if (j > 0) {
		if (a[i][j - 1] == 1) {
			a[i][j - 1] = 0;
			cheak(r, c, i, j - 1, a);
		}
	}
	if (i > 0 && j != c) {
		if (a[i - 1][j + 1] == 1) {
			a[i - 1][j + 1] = 0;
			cheak(r, c, i - 1, j + 1, a);
		}
	}
	if (i > 0 && j > 0) {
		if (a[i - 1][j - 1] == 1) {
			a[i - 1][j - 1] = 0;
			cheak(r, c, i - 1, j - 1, a);
		}
	}
	if (i > 0) {
		if (a[i - 1][j] == 1) {
			a[i - 1][j] = 0;
			cheak(r, c, i - 1, j, a);
		}
	}
	if (a[i + 1][j - 1] == 1) {
		a[i + 1][j - 1] = 0;
		cheak(r, c, i + 1, j - 1, a);
	}
	if (a[i + 1][j] == 1) {
		a[i + 1][j] = 0;
		cheak(r, c, i + 1, j, a);
	}
	if (a[i + 1][j + 1] == 1) {
		a[i + 1][j + 1] = 0;
		cheak(r, c, i + 1, j + 1, a);
	}
	return;
}
int judge(int r,int c,int a[][100]) {
	int count = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] == 1) {
				a[i][j] = 0;
				cheak(r, c, i, j, a);
				count++;
			}
		}
	}
	return count;
}
int main() {
	int r, c;
	int array[100][100];
	while (scanf("%d %d", &r, &c)) {
		if (r == 0 && c == 0) {
			return 0;
		}
		input(r, c, array);
		int count = 0;
		printf("%d\n",judge(r, c, array));
	}
	return 0;
}