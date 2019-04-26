#include<iostream>
#include<string>
#include<set>

#define DEFAULT 0
#define REAL -10

using namespace std;

int main() {
	int n;
	int isFake[15] = { 0 };
	string left, right, status;
	set<char> heavy[3], light[3], real[3];

	cin >> n;
	while (n--) {
		for (int i = 0; i < 3; i++) {
			cin >> left >> right >> status;

			if (status.compare("even") == 0) {
				for (int i = 0; i < left.length(); i++) {
					isFake[left[i] - 'A'] = REAL;
					isFake[right[i] - 'A'] = REAL;
				}
			}
			else if (status.compare("up") == 0) {
				for (int i = 0; i < left.length(); i++) {
					if (isFake[left[i] - 'A'] != REAL) isFake[left[i] - 'A']++;
					if (isFake[right[i] - 'A'] != REAL)isFake[right[i] - 'A']--;
				}
			}
			else if (status.compare("down") == 0) {
				for (int i = 0; i < left.length(); i++) {
					if (isFake[left[i] - 'A'] != REAL) isFake[left[i] - 'A']--;
					if (isFake[right[i] - 'A'] != REAL)isFake[right[i] - 'A']++;
				}
			}
		}
		int max = 0, label = 0;
		for (int i = 0; i < 15; i++) {
			if (abs(isFake[i]) != 10 && abs(isFake[i]) > max) {
				max = abs(isFake[i]);
				label = i;
			}
		}

		if (isFake[label] > 0) cout << char(label + 'A') << " is the counterfeit coin and it is heavy." << endl;
		else cout << char(label + 'A') << " is the counterfeit coin and it is light." << endl;

		for (int i = 0; i < 15; i++) {
			isFake[i] = DEFAULT;
		}
	}
	return 0;
}