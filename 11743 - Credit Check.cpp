#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		string a, b, c, d;
		int odd = 0, even = 0;
		cin >> a >> b >> c >> d;
		for (int i = 0; i < 4; i++)a[i] -= '0';
		for (int i = 0; i < 4; i++)b[i] -= '0';
		for (int i = 0; i < 4; i++)c[i] -= '0';
		for (int i = 0; i < 4; i++)d[i] -= '0';
		odd += a[0] * 2 / 10 + a[0] * 2 % 10 + b[0] * 2 / 10 + b[0] * 2 % 10
			+ a[2] * 2 / 10 + a[2] * 2 % 10 + b[2] * 2 / 10 + b[2] * 2 % 10
			+ c[0] * 2 / 10 + c[0] * 2 % 10 + d[0] * 2 / 10 + d[0] * 2 % 10
			+ c[2] * 2 / 10 + c[2] * 2 % 10 + d[2] * 2 / 10 + d[2] * 2 % 10;
		even += a[1] + a[3] + b[1] + b[3] + c[1] + c[3] + d[1] + d[3];
		if ((odd + even) % 10 == 0)printf("Valid\n");
		else printf("Invalid\n");
	}
	return 0;
}