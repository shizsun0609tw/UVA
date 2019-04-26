#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int str2int(string a) {
	return atoi(a.c_str());
}
string int2str(int &sum) {
	string s;
	stringstream ss(s);
	ss << sum;
	return	ss.str();
}
int main() {
	while (true) {		
		string a;
		int sum = 0;
		cin >> a;
		if (a == "0")return 0;
		sum = str2int(a);
		while (sum > 9) {
			sum = 0;
			for (int i = 0; i < a.length(); i++) {
				sum += a[i] - '0';
			}
			a = int2str(sum);
		}

		cout << sum << endl;
	}
}