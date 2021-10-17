#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "linked_list.h"

using namespace std;

int main() {
	Node *head, headNode;
	head = &headNode;//Head initialization

	for (int i = 1; i < 6; i++) {
		append(&head, i*i);
	}

	while (head->next != NULL) {
		cout << head->next->data << endl;
		head = head->next;
	}


	system("PAUSE");
	system("EXIT");
}