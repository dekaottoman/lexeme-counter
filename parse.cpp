#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
	char str[] = "int i = 10 ;char c ;printf('%c : %d', c, i) ;";
	char tokenBuffer[16] = "", *bufferP;
	bufferP = &tokenBuffer[0];

	bufferP = strtok(str, " ;");
	while (bufferP != NULL) {
		printf("%s\n", bufferP);
		bufferP = strtok(NULL, " ;");
	}

	system("PAUSE");
	exit(0);
}