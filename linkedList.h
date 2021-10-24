#include <string.h>
#include "lexeme.h"

class lexNode {
public:
	Lexeme l;
	lexNode* next = NULL;
};

void appendLex(lexNode** head, char *str) {
	lexNode* newNode = new lexNode();
	lexNode* last = *head;
	newNode->l.getLex(str);
	newNode->next = NULL;

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = newNode;
}

bool searchFreq(lexNode** head, char *str) {
	lexNode* searchP = *head;

	while (searchP->next != NULL) {
		if (!strcmp(searchP->next->l.lex, str)) {
			searchP->next->l.increaseFreq();
			return true;
		}
		searchP = searchP->next;
	}
	return false;
}