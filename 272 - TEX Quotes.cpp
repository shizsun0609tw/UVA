#include<string>
#include<iostream>

using namespace std;

int main() {
	int count = 0;
	string a;
	while (getline(cin, a)) {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '"') {
				count++;
				if (count % 2 == 1)	printf("``");
				else printf("''");
			}
			else {
				printf("%c", a[i]);
			}
		}
		printf("\n");
	}
	return 0;
}