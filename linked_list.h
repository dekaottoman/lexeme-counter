class Node {
	public:
		int data;
		Node* next = NULL;
};

class strNode {
public:
	char str[32];
	strNode* next = NULL;
};

void append(Node** head, int data){
	Node* newNode = new Node();
	Node* last = *head;
	newNode->data = data;
	newNode->next = NULL;

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = newNode;
}

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
