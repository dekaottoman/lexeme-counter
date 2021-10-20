class strNode {
    public:
	    char str[64];
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

