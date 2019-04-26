#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cstdlib>
using namespace std;

int cross(pair<int, int> P, pair<int, int> A, pair<int, int> B) {
	return (A.first - P.first) * (B.second - P.second) -
		(A.second - P.second) * (B.first - P.first);
}

int len(pair<int, int> P, pair<int, int> A) {
	return abs((A.first - P.first) * (A.first - P.first) -
		(A.second - P.second) * (A.second - P.second));
}

void Jarvis_March(vector<pair<int, int>> &k, vector<pair<int, int>> &c) {
	sort(k.begin(), k.end());
	pair<int, int> start = k[0];
	pair<int, int> hold = k[1];

	c[0] = start;

	for (int m = 1; true; m++) {
		hold = k[1];
		for (int i = 0; i < k.size(); i++) {
			if (cross(c[m-1], hold, k[i]) < 0 ||
				(cross(c[m-1], hold, k[i]) == 0 && len(c[m-1], hold) < len(c[m-1], k[i]))) {
				hold = k[i];
			}
		}
		c.push_back(hold);
		if (start == c[m])break;
	}
}

bool is_inside(pair<int, int> m, vector<pair<int, int>> c) {
	for (int i = 0; i < c.size() - 1; i++) {
		if (cross(c[i], c[i + 1], m) < 0) {
			return false;
		}
	}
	return true;
}

void cal_area(vector<pair<int, int>> c, vector<double> &a) {
	double sum = 0;
	for (int i = 1; i < c.size(); i++) {
		sum += c[i - 1].first * c[i].second - c[i].first * c[i - 1].second;
	}
	a.push_back(sum / 2.0);
}

int main() {
	int n, x, y, count = 0;
	vector<vector<pair<int, int>>> kingdom;
	vector<vector<pair<int, int>>> c_h;
	vector<pair<int, int>> input;
	vector<double> area;
	double sum = 0;

	while (cin >> n) {
		if (n == -1)break;

		for (int count = 0; count < n; count++) {
			cin >> x >> y;
			input.push_back(make_pair(x, y));
		}
		kingdom.push_back(input);
		input.clear();
	}

	for (int i = 0; i < kingdom.size(); i++) {
		c_h.push_back(vector<pair<int, int>>(1));
		Jarvis_March(kingdom[i], c_h[i]);
		cal_area(c_h[i], area);
	}

	while (cin >> x >> y) {
		for (int i = 0; i < kingdom.size(); i++) {
			if (is_inside(make_pair(x, y), c_h[i])) {
				sum += area[i];
				area[i] = 0.0;
			}
		}
	}
	cout << fixed << setprecision(2) << sum << endl;
}