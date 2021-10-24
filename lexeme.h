#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "identifyLex.h"

class Lexeme {
public:
	char type[16], lex[32];
	int frequency = 0;

	void increaseFreq() {
		frequency++;
	}

	void setType() {
		if (isKeyword(lex)) {
			strcpy(type, "Keyword");
		}
		else if (isOperator(lex)) {
			strcpy(type, "Operator");
		}
		else if (isSpChar(lex)) {
			strcpy(type, "Special Char");
		}
		else if (isChConst(lex)) {
			strcpy(type, "Char Const");
		}
		else if (isNumConst(lex)) {
			strcpy(type, "Num Const");
		}
		else if (isStr(lex)) {
			strcpy(type, "String");
		}
		else if (isArr(lex)) {
			strcpy(type, "Array");
		}
		else {
			strcpy(type, "Identifier");
		}
	}

	void getLex(char *l) {
		strcpy(lex, l);
		setType();
		increaseFreq();
	}
};
