#include<stdio.h>
int main() {
	int n;
	int a, b;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &a, &b);
		if (a == 1)b -= 9;
		if (a == 2)b -= 20;
		if (a == 3)b += 1;
		if (a == 4)b -= 3;
		if (a == 5)b -= 8;
		if (a == 6)b -= 5;
		if (a == 7)b -= 10;
		if (a == 8)b -= 7;
		if (a == 9)b -= 4;
		if (a == 10)b -= 9;
		if (a == 11)b -= 6;
		if (a == 12)b -= 11;
		while (b < 0)b += 7;
		b %= 7;
		if (b == 0)printf("Sunday\n");
		if (b == 1)printf("Monday\n");
		if (b == 2)printf("Tuesday\n");
		if (b == 3)printf("Wednesday\n");
		if (b == 4)printf("Thursday\n");
		if (b == 5)printf("Friday\n");
		if (b == 6)printf("Saturday\n");
	}
	return 0;
}//1/10 2/21 4/4 5/9 6/6 7/11 8/8 9/5 10/10 11/7 12/12 