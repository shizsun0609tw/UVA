#include<iostream>

using namespace std;
int main() {
	int n, a;
	while (cin >> n) {
		int sum = 0, empty = 0;
		sum += n;
		empty += n;
		while (empty >= 3) {
			a = empty % 3;
			sum += empty / 3;
			empty /= 3;
			empty += a;
		}
		if (empty == 2) {
			sum += 1;
		}
		cout << sum << endl;
	}
	return 0;
}