# include <string.h>

using namespace std ;

class lexNode ;

bool isKeyword ( char * str ) ;
bool isOperator ( char * str ) ;
bool isSpChar ( char * str ) ;
bool isChConst ( char * str ) ;
bool isNumConst ( char * str ) ;
bool isStr ( char * str ) ;
bool isArr ( lexNode * next ) ;

class lexNode {
public :
	char type [ 16 ] , lex [ 64 ] ;
	int frequency = 0 ;
	lexNode * next ;

	void increaseFreq ( ) {
		frequency ++ ;
	}

	void setType ( ) {
		if ( isKeyword ( lex ) ) {
			strcpy ( type , "Keyword" ) ;
		}
		else if ( isOperator ( lex ) ) {
			strcpy ( type , "Operator" ) ;
		}
		else if ( isSpChar ( lex ) ) {
			strcpy ( type , "Special Char" ) ;
		}
		else if ( isChConst ( lex ) ) {
			strcpy ( type , "Char Const" ) ;
		}
		else if ( isNumConst ( lex ) ) {
			strcpy ( type , "Num Const" ) ;
		}
		else if ( isStr ( lex ) ) {
			strcpy ( type , "String" ) ;
		}
		else if ( isArr ( next ) ) {
			strcpy ( type , "Array" ) ;
		}
		else {
			strcpy ( type , "Identifier" ) ;
		}
	}

	void getType ( const char * t ) {
		strcpy ( type , t ) ;
	}

	void getLex ( char * l ) {
		strcpy ( lex , l ) ;
		increaseFreq ( ) ;
	}
} ;

void appendLex ( lexNode * * head , char * lex , const char * type ) {
	lexNode * newNode = new lexNode ( ) ;
	lexNode * last = * head ;
	newNode -> getLex ( lex ) ;
	newNode -> getType ( type ) ;
	newNode -> next = NULL ;

	while ( last -> next != NULL ) {
		last = last -> next ;
	}

	last -> next = newNode ;
}

bool searchFreq ( lexNode * * head , char * str ) {
	lexNode * searchP = * head ;

	while ( searchP -> next != NULL ) {
		if ( ! strcmp ( searchP -> next -> lex , str ) ) {
			searchP -> next -> increaseFreq ( ) ;
			return true ;
		}
		searchP = searchP -> next ;
	}
	return false ;
}

int printType ( lexNode * * head , const char * type ) {
	lexNode * href = * head ;
	int total = 0 ;
	char tabs [ 8 ] ;
	if ( ! strcmp ( type , "Special Char" ) || ! strcmp ( type , "Identifier" ) || ! strcmp ( type , "Num Const" ) || ! strcmp ( type , "Char Const" ) || ! strcmp ( type , "Operator" ) ) {
	    strcpy ( tabs , "\t>>\t" ) ;
	}
	else {
		strcpy ( tabs , "\t\t>>\t" ) ;
	}


	while ( href -> next != NULL ) {
		if ( ! strcmp ( href -> next -> type , type ) ) {
			cout << href -> next -> type << tabs << href -> next -> frequency << "\t>>" << href -> next -> lex << endl ;
			total ++ ;
		}
		href = href -> next ;
	}

	if ( total > 0 ) {
		cout << endl << "Total \t\t>>\t" << total << "\t>>" << type << endl << endl ;
        cout << "****************************************" << endl << endl ;
	}

	return total ;
}

int countTotalFreq ( lexNode * * head , const char * type ) {
    lexNode * href = * head ;
    int freq = 0 ;

    while ( href -> next != NULL ) {
        if ( ! strcmp ( href -> next -> type , type ) ) {
            freq += href -> next -> frequency;
        }
        href = href -> next ;
    }

    return freq ;
}

bool isKeyword ( char * str ) {
	if ( ! strcmp ( str , "auto" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "break" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "case" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "char" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "const" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "continue" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "default" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "do" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "double" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "else" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "enum" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "extern" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "float" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "for" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "goto" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "if" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "int" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "long" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "register" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "return" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "short" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "signed" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "sizeof" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "static" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "struct" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "switch" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "typedef" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "union" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "unsigned" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "void" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "volatile" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "while" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "asm" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "dynamic_cast" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "namespace" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "reinterpret_cast" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "bool" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "explicit" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "new" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "static_cast" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "false" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "catch" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "operator" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "template" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "friend" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "private" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "class" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "this" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "inline" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "public" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "throw" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "const_cast" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "delete" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "mutable" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "protected" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "true" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "try" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "typeid" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "typename" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "using" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "virtual" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "wchar_t" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "include" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "define" ) ) {
		return true ;
	}
    else if ( ! strcmp ( str , "NULL" ) ) {
        return true ;
    }
	else {
		return false ;
	}
}

bool isOperator ( char * str ) {
	if ( ! strcmp ( str , "+" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "-" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "*" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "/" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "%" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "++" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "--" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "=" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "+=" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "*=" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "-=" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "/=" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "%=" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "&=" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "|=" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "^=" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , ">>=" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "<<=" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "==" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "!=" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , ">" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "<" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , ">=" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "<=" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "&&" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "||" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "!" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , ">>" ) ) {
		return true ;
	}
	else if ( ! strcmp ( str , "<<" ) ) {
		return true ;
	}
    else if ( ! strcmp ( str , "->" ) ) {
        return true ;
    }
    else if ( ! strcmp ( str , "&" ) ) {
        return true ;
    }
    else if ( ! strcmp ( str , "." ) ) {
        return true ;
    }
	else {
		return false ;
	}
}

bool isSpChar ( char * str ) {
	if ( ! strcmp ( "[" , str ) ) {
		return true ;
	}
	else if ( ! strcmp ( "]" , str ) ) {
		return true ;
	}
	else if ( ! strcmp ( "(" , str ) ) {
		return true ;
	}
	else if ( ! strcmp ( ")" , str ) ) {
		return true ;
	}
	else if ( ! strcmp ( "{" , str ) ) {
		return true ;
	}
	else if ( ! strcmp ( "}" , str ) ) {
		return true ;
	}
	else if ( ! strcmp ( ";" , str ) ) {
		return true ;
	}
    else if ( ! strcmp ( ":" , str ) ) {
        return true ;
    }
	else if ( ! strcmp ( "," , str ) ) {
		return true ;
	}
	else if ( ! strcmp ( "#" , str ) ) {
		return true ;
	}
	else {
		return false ;
	}
}

bool isChConst ( char * str ) {
	if ( str [ 0 ] == '\'' ) {
		return true ;
	}
	else {
		return false ;
	}
}

bool isNumConst ( char * str ) {
	int i = 0 , j , digitCount = 0 , strLen = 0 ;
	char nums [ ] = "0123456789." ;

	while ( str [ strLen ] != '\0' ) {
		strLen ++ ;
	}

	while ( str [ i ] != '\0' ) {
		j = 0 ;
		while ( nums [ j ] != '\0' ) {
			if ( nums [ j ] == str [ i ] ) {
				digitCount ++ ;
			}
			j ++ ;
		}
		i ++ ;
	}

	if ( strLen == digitCount ) {
		return true ;
	}
	else {
		return false ;
	}
}

bool isStr ( char * str ) {
	bool isStr = false ;
	int i = 0 ;
	while ( str [ i ] != '\0' ) {
		if ( str [ i ] == '\"' ) {
			isStr = true ;
		}
		i ++ ;
	}

	return isStr ;
}

bool isArr ( lexNode * next ) {
	if ( next != NULL ) {
		if ( ! strcmp ( next -> lex , "[" ) ) {
			return true ;
		}
		else {
			return false ;
		}
	}
	else {
		return false ;
	}
}