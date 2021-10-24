#include <iostream>
#include "linkedList.h"

using namespace std;

void getFile(char *directory, char *file) {
	FILE *fp = fopen(directory, "r+");
	char c;
	int i = 0;

	if (fp) {
		while ((c = getc(fp)) != EOF) {
			file[i] = c;
			i++;
		}
		file[i] = '\0';
	}

	fclose(fp);
}

void analyze(char *directory) {
	lexNode headNode, *headP = &headNode;
	char file[262144], tokenBuffer[32], *bufferP = &tokenBuffer[0];
	getFile(directory, file);

	bufferP = strtok(file, " \n\t");
	while (bufferP != NULL) {
		if (searchFreq(&headP, bufferP)) {

		}
		else {
			appendLex(&headP, bufferP);
		}
		bufferP = strtok(NULL, " \n\t");
	}

	cout << "Type\t\t>>Frequency\t>>Token" << endl;
	cout << "****************************************" << endl;
	while (headP->next != NULL) {
		if (!strcmp(headP->next->l.type, "Keyword")) {
			cout << headP->next->l.type << "\t\t>>\t" << headP->next->l.frequency << "\t>>" << headP->next->l.lex << endl;
		}
		headP = headP->next;
	}
	cout << "****************************************" << endl;
	headP = &headNode;
	while (headP->next != NULL) {
		if (!strcmp(headP->next->l.type, "Operator")) {
			cout << headP->next->l.type << "\t>>\t" << headP->next->l.frequency << "\t>>" << headP->next->l.lex << endl;
		}
		headP = headP->next;
	}
	cout << "****************************************" << endl;
	headP = &headNode;
	while (headP->next != NULL) {
		if (!strcmp(headP->next->l.type, "Special Char")) {
			cout << headP->next->l.type << "\t>>\t" << headP->next->l.frequency << "\t>>" << headP->next->l.lex << endl;
		}
		headP = headP->next;
	}
	cout << "****************************************" << endl;
	headP = &headNode;
	while (headP->next != NULL) {
		if (!strcmp(headP->next->l.type, "Char Const")) {
			cout << headP->next->l.type << "\t>>\t" << headP->next->l.frequency << "\t>>" << headP->next->l.lex << endl;
		}
		headP = headP->next;
	}
	cout << "****************************************" << endl;
	headP = &headNode;
	while (headP->next != NULL) {
		if (!strcmp(headP->next->l.type, "Num Const")) {
			cout << headP->next->l.type << "\t>>\t" << headP->next->l.frequency << "\t>>" << headP->next->l.lex << endl;
		}
		headP = headP->next;
	}
	cout << "****************************************" << endl;
	headP = &headNode;
	while (headP->next != NULL) {
		if (!strcmp(headP->next->l.type, "String")) {
			cout << headP->next->l.type << "\t\t>>\t" << headP->next->l.frequency << "\t>>" << headP->next->l.lex << endl;
		}
		headP = headP->next;
	}
	cout << "****************************************" << endl;
	headP = &headNode;
	while (headP->next != NULL) {
		if (!strcmp(headP->next->l.type, "Array")) {
			cout << headP->next->l.type << "\t\t>>\t" << headP->next->l.frequency << "\t>>" << headP->next->l.lex << endl;
		}
		headP = headP->next;
	}
	cout << "****************************************" << endl;
	headP = &headNode;
	while (headP->next != NULL) {
		if (!strcmp(headP->next->l.type, "Identifier")) {
			cout << headP->next->l.type << "\t>>\t" << headP->next->l.frequency << "\t>>" << headP->next->l.lex << endl;
		}
		headP = headP->next;
	}
}