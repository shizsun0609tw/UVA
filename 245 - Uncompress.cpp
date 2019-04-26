#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>

using namespace std;

struct Node {
	string word;
	Node *next;
};

void addHead(Node **first, string add) {
	if (*first == NULL) {
		*first = new Node();
		(*first)->word = add;
		(*first)->next = NULL;
	}
	else {
		Node *temp = new Node();
		temp->word = add;
		temp->next = *first;
		(*first) = temp;
	}
}

void printWord(Node **first, int n) {
	Node *current = *first, *temp;
	if (n != 1) {
		for (int i = 0; i < n - 2; i++) {
			current = current->next;
		}

		temp = current->next;

		current->next = current->next->next;
		temp->next = *first;
		*first = temp;
	}

	cout << (*first)->word;
}

void clearList(Node **first) {
	Node *current;
	while ((*first)->next != NULL) {
		Node *current = *first;
		*first = (*first)->next;
		delete current;
	}
	delete *first;
}

int main() {
	Node *first = NULL;
	string s;
	char c;
	int n = 0;

	while (cin.get(c)) {
		if (c >= '0' && c <= '9') {
			if (c == '0' && s == "") {
				clearList(&first);
				return 0;
			}
			while (c >= '0' && c <= '9') {
				s += c;
				cin.get(c);
			}
			for (int i = 0; i < s.length(); i++) {
				n += (s[i] - '0') * pow(10, (s.length() - i - 1));
			}

			printWord(&first, n);
			cout << c;
			s.clear();
			n = 0;
		}
		else if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z')) {
			if (s != "") {
				addHead(&first, s);
			}
			cout << s << c;
			s.clear();
			continue;
		}
		else {
			s += c;
		}
	}
}