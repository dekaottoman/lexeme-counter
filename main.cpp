#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "analyze.h"

using namespace std;

int main() {
	char file[] = "int i = 0 ; int j = ( 1 + 1 ) ; int k = 222 , l = 222 ; const char a = 'A' , b = 'B' , c = 'B'  float x = ( 2 + 2.55 ) ; char str1[] = \"String1\" , str2[] = \"String2\" , str3[] = \"String3\" ; ";

	analyzeSource(file);

	system("PAUSE");
	system("EXIT");
}