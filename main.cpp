# include <iostream>
# include <string.h>
# include <dirent.h>
# include "utility.h"
# include "lexOps.h"

using namespace std ;

int main ( ) {
    DIR * dir ;
    struct dirent * entity ;
    char nameBuffer [ 16 ] = "\\" , directory [ 64 ] , dirBuffer [ 64 ] , fileBuffer [ 1048576 ] ;
    int totalGsum = 0 ;
    int totalKey = 0 , totalOp = 0 , totalSp = 0 , totalCh = 0 , totalNum = 0 , totalStr = 0 , totalArr = 0 , totalId = 0 ;

    cout << "Enter directory\t>>" ;
    gets ( directory ) ;
    strcpy ( dirBuffer , directory ) ;
    dir = opendir ( directory ) ;

    if ( dir == NULL ) {
        cout << "Nonexistent Directory!!!" << endl ;
        exit ( 0 ) ;
    }

    entity = readdir ( dir ) ;
    while ( entity != NULL ) {
        strcat ( nameBuffer , entity -> d_name ) ;
        strcat ( dirBuffer , nameBuffer ) ;

        if ( checkPath ( dirBuffer ) ) {
            char file [ 262144 ] ;
            char tokenBuffer [ 32 ] , * bufferP ;
            bufferP = & tokenBuffer [ 0 ] ;
            lexNode parseHead , * parseP = & parseHead ;
            lexNode headNode , * headP = & headNode ;
            int kc , oc , spc , ccc , ncc , sc , ac , ic , grandSum = 0 , lexSum ;

            getFile ( dirBuffer , file ) ;

            bufferP = strtok ( file , " \n\t" ) ;
            while ( bufferP != NULL ) {
                grandSum ++ ;
                appendLex ( & parseP , bufferP , " " ) ;
                bufferP = strtok ( NULL , " \n\t" ) ;
            }

            while ( parseP -> next != NULL ) {
                parseP -> next -> setType ( ) ;
                parseP = parseP -> next ;
            }

            parseP = & parseHead ;
            while ( parseP -> next != NULL ) {
                if ( searchFreq ( & headP , parseP -> next -> lex ) ) ;
                else {
                    appendLex ( & headP , parseP -> next -> lex , parseP -> next -> type ) ;
                }
                parseP = parseP -> next ;
            }

            headP = & headNode ;
            cout << endl << dirBuffer << endl << endl ;
            kc = printType ( & headP , "Keyword" ) ;
            totalKey += countTotalFreq( & headP , "Keyword" ) ;
            oc = printType ( & headP , "Operator" ) ;
            totalOp += countTotalFreq ( & headP , "Operator" ) ;
            spc = printType ( & headP , "Special Char" ) ;
            totalSp += countTotalFreq ( & headP , "Special Char" ) ;
            ccc = printType ( & headP , "Char Const" ) ;
            totalCh += countTotalFreq ( & headP , "Char Const" ) ;
            ncc = printType ( & headP , "Num Const" ) ;
            totalNum += countTotalFreq ( & headP , "Num Const" ) ;
            sc = printType ( & headP , "String" ) ;
            totalStr += countTotalFreq ( & headP , "String" ) ;
            ac = printType ( & headP , "Array" ) ;
            totalArr += countTotalFreq ( & headP , "Array" ) ;
            ic = printType ( & headP , "Identifier" ) ;
            totalId += countTotalFreq ( & headP , "Identifier" ) ;
            lexSum = kc + oc + spc + ccc + ncc + sc + ac + ic ;
            cout << "LexSum Is:" << lexSum << endl << endl ;
            cout << "GrandSum Is:" << grandSum << endl << endl ;
            totalGsum += grandSum ;

            parseHead . next = NULL ;
            headNode . next = NULL ;
        }

        strcpy ( dirBuffer , directory ) ;
        strcpy ( nameBuffer , "\\" ) ;
        entity = readdir ( dir ) ;
    }

    cout << "****************************************" << endl << "Grand Summation" << endl << "****************************************" << endl << endl ;
    cout << "Keyword\t\t>>" << totalKey << endl ;
    cout << "Operator\t>>" << totalOp << endl ;
    cout << "Special Char\t>>" << totalSp << endl ;
    cout << "Char Const\t>>" << totalCh << endl ;
    cout << "Num Const\t>>" << totalNum << endl ;
    cout << "String\t\t>>" << totalStr << endl ;
    cout << "Array\t\t>>" << totalArr << endl ;
    cout << "Identifier\t>>" << totalId << endl ;
    cout << "Grand Sum\t>>" << totalGsum << endl << endl ;

    system ( "PAUSE" ) ;
    system ( "EXIT" ) ;
}