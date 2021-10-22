#include <string.h>
#include "lexIdentify.h"
#include "linkedList.h"

using namespace std;

void analyzeSource(char *file) {
	char tokenBuffer[32], *bufferP = &tokenBuffer[0];
	bool found = false;
	int i;
	strNode parseHead, *pheadP = &parseHead, strHead, *strheadP = &strHead;
	lexNode cHead, numHead, *cheadP = &cHead, *nheadP = &numHead;
	struct lexeme k_lex[62], o_lex[27], sp_lex[6];

	strcpy(k_lex[0].lex, "auto");
	strcpy(k_lex[1].lex, "break");
	strcpy(k_lex[2].lex, "case");
	strcpy(k_lex[3].lex, "char");
	strcpy(k_lex[4].lex, "const");
	strcpy(k_lex[5].lex, "continue");
	strcpy(k_lex[6].lex, "default");
	strcpy(k_lex[7].lex, "do");
	strcpy(k_lex[8].lex, "double");
	strcpy(k_lex[9].lex, "else");
	strcpy(k_lex[10].lex, "enum");
	strcpy(k_lex[11].lex, "extern");
	strcpy(k_lex[12].lex, "float");
	strcpy(k_lex[13].lex, "for");
	strcpy(k_lex[14].lex, "goto");
	strcpy(k_lex[15].lex, "if");
	strcpy(k_lex[16].lex, "int");
	strcpy(k_lex[17].lex, "long");
	strcpy(k_lex[18].lex, "register");
	strcpy(k_lex[19].lex, "return");
	strcpy(k_lex[20].lex, "short");
	strcpy(k_lex[21].lex, "signed");
	strcpy(k_lex[22].lex, "sizeof");
	strcpy(k_lex[23].lex, "static");
	strcpy(k_lex[24].lex, "struct");
	strcpy(k_lex[25].lex, "switch");
	strcpy(k_lex[26].lex, "typedef");
	strcpy(k_lex[27].lex, "union");
	strcpy(k_lex[28].lex, "unsigned");
	strcpy(k_lex[29].lex, "void");
	strcpy(k_lex[30].lex, "volatile");
	strcpy(k_lex[31].lex, "while");
	strcpy(k_lex[32].lex, "asm");
	strcpy(k_lex[33].lex, "dynamic_cast");
	strcpy(k_lex[34].lex, "namespace");
	strcpy(k_lex[35].lex, "reinterpret_cast");
	strcpy(k_lex[36].lex, "bool");
	strcpy(k_lex[37].lex, "explicit");
	strcpy(k_lex[38].lex, "new");
	strcpy(k_lex[39].lex, "static_cast");
	strcpy(k_lex[40].lex, "false");
	strcpy(k_lex[41].lex, "catch");
	strcpy(k_lex[42].lex, "operator");
	strcpy(k_lex[43].lex, "template");
	strcpy(k_lex[44].lex, "friend");
	strcpy(k_lex[45].lex, "private");
	strcpy(k_lex[46].lex, "class");
	strcpy(k_lex[47].lex, "this");
	strcpy(k_lex[48].lex, "inline");
	strcpy(k_lex[49].lex, "public");
	strcpy(k_lex[50].lex, "throw");
	strcpy(k_lex[51].lex, "const_cast");
	strcpy(k_lex[52].lex, "delete");
	strcpy(k_lex[53].lex, "mutable");
	strcpy(k_lex[54].lex, "protected");
	strcpy(k_lex[55].lex, "true");
	strcpy(k_lex[56].lex, "try");
	strcpy(k_lex[57].lex, "typeid");
	strcpy(k_lex[58].lex, "typename");
	strcpy(k_lex[59].lex, "using");
	strcpy(k_lex[60].lex, "virtual");
	strcpy(k_lex[61].lex, "wchar_t");

	//o_lex definitions
	strcpy(o_lex[0].lex, "+");
	strcpy(o_lex[1].lex, "-");
	strcpy(o_lex[2].lex, "*");
	strcpy(o_lex[3].lex, "/");
	strcpy(o_lex[4].lex, "%");
	strcpy(o_lex[5].lex, "++");
	strcpy(o_lex[6].lex, "--");
	strcpy(o_lex[7].lex, "=");
	strcpy(o_lex[8].lex, "+=");
	strcpy(o_lex[9].lex, "*=");
	strcpy(o_lex[10].lex, "-=");
	strcpy(o_lex[11].lex, "/=");
	strcpy(o_lex[12].lex, "%=");
	strcpy(o_lex[13].lex, "&=");
	strcpy(o_lex[14].lex, "|=");
	strcpy(o_lex[15].lex, "^=");
	strcpy(o_lex[16].lex, ">>=");
	strcpy(o_lex[17].lex, "<<=");
	strcpy(o_lex[18].lex, "==");
	strcpy(o_lex[19].lex, "!=");
	strcpy(o_lex[20].lex, ">");
	strcpy(o_lex[21].lex, "<");
	strcpy(o_lex[22].lex, ">=");
	strcpy(o_lex[23].lex, "<=");
	strcpy(o_lex[24].lex, "&&");
	strcpy(o_lex[25].lex, "||");
	strcpy(o_lex[26].lex, "!");

	//sp_lex definitions 
	strcpy(sp_lex[0].lex, "[");
	strcpy(sp_lex[1].lex, "(");
	strcpy(sp_lex[2].lex, "{");
	strcpy(sp_lex[3].lex, ";");
	strcpy(sp_lex[4].lex, ",");
	strcpy(sp_lex[5].lex, "#");

	bufferP = strtok(file, " ");
	while (bufferP != NULL) {

		if (isKeyword(bufferP)) {
			i = 0;
			while (i < 62) {
				if (!strcmp(bufferP, k_lex[i].lex)) {
					k_lex[i].frequency++;
				}
				i++;
			}
		}
		else if (isOperator(bufferP)) {
			i = 0;
			while (i < 27) {
				if (!strcmp(bufferP, o_lex[i].lex)) {
					o_lex[i].frequency++;
				}
				i++;
			}
		}
		else if (isSpChar(bufferP)) {
			i = 0;
			while (i < 6) {
				if (!strcmp(bufferP, sp_lex[i].lex)) {
					sp_lex[i].frequency++;
				}
				i++;
			}
		}


		appendStr(&pheadP, bufferP);
		bufferP = strtok(NULL, " ");
	}

	pheadP = &parseHead;
	while (pheadP->next != NULL) {
		found = false;
		if (isChConst(pheadP->next->str)) {
			cheadP = &cHead;
			while (cheadP->next != NULL) {
				if (!strcmp(cheadP->next->str, pheadP->next->str)) {
					found = true;
					cheadP->next->frequency++;
				}
				cheadP = cheadP->next;
			}
			if (found == false) {
				appendLex(&cheadP, pheadP->next->str);
			}
		}
		pheadP = pheadP->next;
	}

	pheadP = &parseHead;
	while (pheadP->next != NULL) {
		found = false;
		if (isNumConst(pheadP->next->str)) {
			nheadP = &numHead;
			while (nheadP->next != NULL) {
				if (!strcmp(nheadP->next->str, pheadP->next->str)) {
					found = true;
					nheadP->next->frequency++;
				}
				nheadP = nheadP->next;
			}
			if (found == false) {
				appendLex(&nheadP, pheadP->next->str);
			}
		}

		pheadP = pheadP->next;
	}

	pheadP = &parseHead;
	while (pheadP->next != NULL) {
		if (isString(pheadP->next->str)) {
			appendStr(&strheadP, pheadP->next->str);
		}
		pheadP = pheadP->next;
	}

	pheadP = &parseHead;
	while (pheadP->next != NULL) {
		cout << pheadP->next->str << endl;
		pheadP = pheadP->next;
	}

	cout << endl;

	cout << "****************************************" << endl << endl;

	i = 0;
	while (i < 62) {
		if (k_lex[i].frequency > 0) {
			cout << "Keyword\t\t>>" << k_lex[i].lex << endl << "Frequency\t>>" << k_lex[i].frequency << endl << endl;
		}
		i++;
	}
	cout << "****************************************" << endl << endl;
	i = 0;
	while (i < 27) {
		if (o_lex[i].frequency > 0) {
			cout << "Operator\t>>" << o_lex[i].lex << endl << "Frequency\t>>" << o_lex[i].frequency << endl << endl;
		}
		i++;
	}
	cout << "****************************************" << endl << endl;
	i = 0;
	while (i < 6) {
		if (sp_lex[i].frequency > 0) {
			cout << "Special Char\t>>" << sp_lex[i].lex << endl << "Frequency\t>>" << sp_lex[i].frequency << endl << endl;
		}
		i++;
	}
	cout << "****************************************" << endl << endl;
	cheadP = &cHead;
	while (cheadP->next != NULL) {
		cout << "Char Const\t>>" << cheadP->next->str << endl << "Frequency\t>>" << cheadP->next->frequency << endl << endl;;
		cheadP = cheadP->next;
	}
	cout << "****************************************" << endl << endl;
	nheadP = &numHead;
	while (nheadP->next != NULL) {
		cout << "Num Const\t>>" << nheadP->next->str << endl << "Frequency\t>>" << nheadP->next->frequency << endl << endl;;
		nheadP = nheadP->next;
	}
	cout << "****************************************" << endl << endl;
	strheadP = &strHead;
	while (strheadP->next != NULL) {
		cout << "String\t\t>>" << strheadP->next->str << endl;
		strheadP = strheadP->next;
	}
	cout << endl << "****************************************" << endl << endl;
}