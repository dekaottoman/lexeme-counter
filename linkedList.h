#include <string.h>

class lexNode {
public:
	char str[32];
	int frequency = 0;
	lexNode* next = NULL;
};

class strNode {
public:
	char str[32];
	strNode* next = NULL;
};

void appendStr(strNode** head, char *str) {
	strNode* newNode = new strNode();
	strNode* last = *head;
	strcpy(newNode->str, str);
	newNode->next = NULL;

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = newNode;
}

void appendLex(lexNode** head, char *str) {
	lexNode* newNode = new lexNode();
	lexNode* last = *head;
	strcpy(newNode->str, str);
	newNode->next = NULL;
	newNode->frequency++;


	while (last->next != NULL) {
		last = last->next;
	}

	last->next = newNode;
}