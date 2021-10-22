#include <string.h>
#include <stdbool.h>

struct lexeme {
	char lex[32];
	int frequency = 0;
};

bool isKeyword(char *str) {
	if (!strcmp(str, "auto")) {
		return true;
	}
	else if (!strcmp(str, "break")) {
		return true;
	}
	else if (!strcmp(str, "case")) {
		return true;
	}
	else if (!strcmp(str, "char")) {
		return true;
	}
	else if (!strcmp(str, "const")) {
		return true;
	}
	else if (!strcmp(str, "continue")) {
		return true;
	}
	else if (!strcmp(str, "default")) {
		return true;
	}
	else if (!strcmp(str, "do")) {
		return true;
	}
	else if (!strcmp(str, "double")) {
		return true;
	}
	else if (!strcmp(str, "else")) {
		return true;
	}
	else if (!strcmp(str, "enum")) {
		return true;
	}
	else if (!strcmp(str, "extern")) {
		return true;
	}
	else if (!strcmp(str, "float")) {
		return true;
	}
	else if (!strcmp(str, "for")) {
		return true;
	}
	else if (!strcmp(str, "goto")) {
		return true;
	}
	else if (!strcmp(str, "if")) {
		return true;
	}
	else if (!strcmp(str, "int")) {
		return true;
	}
	else if (!strcmp(str, "long")) {
		return true;
	}
	else if (!strcmp(str, "register")) {
		return true;
	}
	else if (!strcmp(str, "return")) {
		return true;
	}
	else if (!strcmp(str, "short")) {
		return true;
	}
	else if (!strcmp(str, "signed")) {
		return true;
	}
	else if (!strcmp(str, "sizeof")) {
		return true;
	}
	else if (!strcmp(str, "static")) {
		return true;
	}
	else if (!strcmp(str, "struct")) {
		return true;
	}
	else if (!strcmp(str, "switch")) {
		return true;
	}
	else if (!strcmp(str, "typedef")) {
		return true;
	}
	else if (!strcmp(str, "union")) {
		return true;
	}
	else if (!strcmp(str, "unsigned")) {
		return true;
	}
	else if (!strcmp(str, "void")) {
		return true;
	}
	else if (!strcmp(str, "volatile")) {
		return true;
	}
	else if (!strcmp(str, "while")) {
		return true;
	}
	else if (!strcmp(str, "asm")) {
		return true;
	}
	else if (!strcmp(str, "dynamic_cast")) {
		return true;
	}
	else if (!strcmp(str, "namespace")) {
		return true;
	}
	else if (!strcmp(str, "reinterpret_cast")) {
		return true;
	}
	else if (!strcmp(str, "bool")) {
		return true;
	}
	else if (!strcmp(str, "explicit")) {
		return true;
	}
	else if (!strcmp(str, "new")) {
		return true;
	}
	else if (!strcmp(str, "static_cast")) {
		return true;
	}
	else if (!strcmp(str, "false")) {
		return true;
	}
	else if (!strcmp(str, "catch")) {
		return true;
	}
	else if (!strcmp(str, "operator")) {
		return true;
	}
	else if (!strcmp(str, "template")) {
		return true;
	}
	else if (!strcmp(str, "friend")) {
		return true;
	}
	else if (!strcmp(str, "private")) {
		return true;
	}
	else if (!strcmp(str, "class")) {
		return true;
	}
	else if (!strcmp(str, "this")) {
		return true;
	}
	else if (!strcmp(str, "inline")) {
		return true;
	}
	else if (!strcmp(str, "public")) {
		return true;
	}
	else if (!strcmp(str, "throw")) {
		return true;
	}
	else if (!strcmp(str, "const_cast")) {
		return true;
	}
	else if (!strcmp(str, "delete")) {
		return true;
	}
	else if (!strcmp(str, "mutable")) {
		return true;
	}
	else if (!strcmp(str, "protected")) {
		return true;
	}
	else if (!strcmp(str, "true")) {
		return true;
	}
	else if (!strcmp(str, "try")) {
		return true;
	}
	else if (!strcmp(str, "typeid")) {
		return true;
	}
	else if (!strcmp(str, "typename")) {
		return true;
	}
	else if (!strcmp(str, "using")) {
		return true;
	}
	else if (!strcmp(str, "virtual")) {
		return true;
	}
	else if (!strcmp(str, "wchar_t")) {
		return true;
	}
	else {
		return false;
	}
}

bool isOperator(char *str) {
	if (!strcmp(str, "+")) {
		return true;
	}
	else if (!strcmp(str, "-")) {
		return true;
	}
	else if (!strcmp(str, "*")) {
		return true;
	}
	else if (!strcmp(str, "/")) {
		return true;
	}
	else if (!strcmp(str, "%")) {
		return true;
	}
	else if (!strcmp(str, "++")) {
		return true;
	}
	else if (!strcmp(str, "--")) {
		return true;
	}
	else if (!strcmp(str, "=")) {
		return true;
	}
	else if (!strcmp(str, "+=")) {
		return true;
	}
	else if (!strcmp(str, "*=")) {
		return true;
	}
	else if (!strcmp(str, "-=")) {
		return true;
	}
	else if (!strcmp(str, "/=")) {
		return true;
	}
	else if (!strcmp(str, "%=")) {
		return true;
	}
	else if (!strcmp(str, "&=")) {
		return true;
	}
	else if (!strcmp(str, "|=")) {
		return true;
	}
	else if (!strcmp(str, "^=")) {
		return true;
	}
	else if (!strcmp(str, ">>=")) {
		return true;
	}
	else if (!strcmp(str, "<<=")) {
		return true;
	}
	else if (!strcmp(str, "==")) {
		return true;
	}
	else if (!strcmp(str, "!=")) {
		return true;
	}
	else if (!strcmp(str, ">")) {
		return true;
	}
	else if (!strcmp(str, "<")) {
		return true;
	}
	else if (!strcmp(str, ">=")) {
		return true;
	}
	else if (!strcmp(str, "<=")) {
		return true;
	}
	else if (!strcmp(str, "&&")) {
		return true;
	}
	else if (!strcmp(str, "||")) {
		return true;
	}
	else if (!strcmp(str, "!")) {
		return true;
	}
	else {
		return false;
	}
}

bool isSpChar(char *str) {
	if (!strcmp("[", str)) {
		return true;
	}
	else if (!strcmp("(", str)) {
		return true;
	}
	else if (!strcmp("{", str)) {
		return true;
	}
	else if (!strcmp(";", str)) {
		return true;
	}
	else if (!strcmp(",", str)) {
		return true;
	}
	else if (!strcmp("#", str)) {
		return true;
	}
	else {
		return false;
	}
}

bool isChConst(char *str) {
	if (str[0] == '\'') {
		return true;
	}
	else {
		return false;
	}
}

bool isNumConst(char *str) {
	int i = 0, j, digitCount = 0, strLen = 0;
	char nums[] = "0123456789.";

	while (str[strLen] != '\0') {
		strLen++;
	}

	while (str[i] != '\0') {
		j = 0;
		while (nums[j] != '\0') {
			if (nums[j] == str[i]) {
				digitCount++;
			}
			j++;
		}

		i++;
	}

	if (strLen == digitCount) {
		return true;
	}
	else {
		return false;
	}
}

bool isString(char *str) {
	if (str[0] == '\"') {
		return true;
	}
	else {
		return false;
	}
}

int identify(char *str) {
	if (isKeyword(str)) {
		return 0;
	}
	else if (isOperator(str)) {
		return 1;
	}
	else if (isSpChar(str)) {
		return 2;
	}
	else {
		return 3;
	}
}