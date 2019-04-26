#include<iostream>

using namespace std;

struct Node {
	int value;
	Node *next;
};

Node *generateList(int N) {
	Node *first = new Node();
	first->next = NULL;
	Node *last = first;
	first->value = 1;

	for (int i = 1; i < N; i++) {
		last->next = new Node();
		last = last->next;
		last->value = i + 1;
		last->next = NULL;
	}
	last->next = first;

	return first;
}

void freeList(Node *first) {
	Node *current = first->next, *temp;

	while (current->next != first) {
		temp = current;
		current = current->next;
		delete temp;
	}
	delete first;
	delete current;
}

Node *findLast(Node *first) {
	Node *current = first;
	while (current->next != first) {
		current = current->next;
	}
	return current;
}

bool findFinal(Node *first, int N, int dis) {
	int num = N;
	Node *current = findLast(first), *temp = first;

	current->next = first->next;
	first = first->next;
	delete temp;
	num--;

	while (num != 1) {
		for (int i = 0; i < dis - 1; i++) {
			current = current->next;
		}
		if (current->next->value == 13) {
			freeList(first);
			return false;
		}
		else {
			if (current->next == first) {
				temp = first;
				current->next = first->next;
				first = first->next;
				delete temp;
				num--;
			}
			else {
				temp = current->next;
				current->next = temp->next;
				delete temp;
				num--;
			}
		}
	}
	return true;
}

int main() {
	int N;

	while (cin >> N) {
		int dis = 0;
		if (N == 0) return 0;
		
		Node *first = generateList(N);
		
		while (++dis) {
			if (findFinal(first, N, dis)) break;
			first = generateList(N);
		}
		cout << dis << endl;
	}
}