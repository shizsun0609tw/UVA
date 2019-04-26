#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		double num, winner;
		double p;
		scanf("%lf %lf %lf", &num, &p, &winner);
		if (p == 0)printf("0.0000\n");
		else {
			double q = (1 - p);
			double r = pow(q, num);
			double ans = pow(q, winner - 1)*p / (1 - r);
			printf("%.4lf\n", ans);
		}
	}
	return 0;
}