#include<iostream>
using namespace std;
int main() {
	long long s, d;
	while (cin >> s >> d) {
		long long count = 0;
		while (count < d) {
			count += s;
			s++;
		}
		cout << s - 1 << "\n";
	}
	return 0;
}