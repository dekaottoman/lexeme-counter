# lexeme-counter
A lexeme counter I have developed alongside my partners for " CSE0405 - Programming Languages ".

The project was meant to analyze lexemes in a given sample of C++ code. 
The project assumes that in the given sample;
  -There are no errors
  -There is a ' ' between each lexeme
The project will ask for a directory and analyze each file in that directory as asked in the project requirements

NOTE : The project uses the "dirent.h" header which is not supported by VC++ compiler. Please try to use GCC or another that supports it.

The output will be similar to following;

Enter directory >>C:\Users\Teoman\Desktop\code

C:\Users\Teoman\Desktop\code\main.cpp

Keyword         >>      5       >>include
Keyword         >>      1       >>using
Keyword         >>      1       >>namespace
Keyword         >>      4       >>int
Keyword         >>      1       >>struct
Keyword         >>      3       >>char
Keyword         >>      3       >>if
Keyword         >>      8       >>NULL
Keyword         >>      4       >>while
Keyword         >>      1       >>else

Total           >>      10      >>Keyword

****************************************

Operator        >>      5       >>*
Operator        >>      34      >>=
Operator        >>      50      >><<
Operator        >>      1       >>==
Operator        >>      4       >>!=
Operator        >>      13      >>->
Operator        >>      24      >>&
Operator        >>      1       >>++
Operator        >>      9       >>+=
Operator        >>      7       >>+
Operator        >>      2       >>.

Total           >>      11      >>Operator

****************************************

Special Char    >>      5       >>#
Special Char    >>      71      >>;
Special Char    >>      43      >>(
Special Char    >>      44      >>)
Special Char    >>      8       >>{
Special Char    >>      7       >>[
Special Char    >>      7       >>]
Special Char    >>      51      >>,
Special Char    >>      8       >>}

Total           >>      9       >>Special Char

****************************************

Num Const       >>      1       >>16
Num Const       >>      2       >>64
Num Const       >>      1       >>1048576
Num Const       >>      12      >>0
Num Const       >>      1       >>262144
Num Const       >>      1       >>32

Total           >>      6       >>Num Const

****************************************

String          >>      1       >>"utility.h"
String          >>      1       >>"lexOps.h"
String          >>      2       >>"\\"
String          >>      1       >>"Enter
String          >>      1       >>directory\t>>"
String          >>      1       >>"Nonexistent
String          >>      1       >>Directory!!!"
String          >>      4       >>"
String          >>      2       >>\n\t"
String          >>      2       >>"Keyword"
String          >>      2       >>"Operator"
String          >>      3       >>"Special
String          >>      2       >>Char"
String          >>      3       >>"Char
String          >>      4       >>Const"
String          >>      3       >>"Num
String          >>      2       >>"String"
String          >>      2       >>"Array"
String          >>      2       >>"Identifier"
String          >>      1       >>"LexSum
String          >>      2       >>Is:"
String          >>      1       >>"GrandSum
String          >>      2       >>"****************************************"
String          >>      2       >>"Grand
String          >>      1       >>Summation"
String          >>      1       >>"Keyword\t\t>>"
String          >>      1       >>"Operator\t>>"
String          >>      1       >>Char\t>>"
String          >>      2       >>Const\t>>"
String          >>      1       >>"String\t\t>>"
String          >>      1       >>"Array\t\t>>"
String          >>      1       >>"Identifier\t>>"
String          >>      1       >>Sum\t>>"
String          >>      1       >>"PAUSE"
String          >>      1       >>"EXIT"

Total           >>      35      >>String

****************************************

Array           >>      4       >>nameBuffer
Array           >>      5       >>directory
Array           >>      7       >>dirBuffer
Array           >>      1       >>fileBuffer
Array           >>      3       >>file
Array           >>      2       >>tokenBuffer

Total           >>      6       >>Array

****************************************

Identifier      >>      1       >><iostream>
Identifier      >>      1       >><string.h>
Identifier      >>      1       >><dirent.h>
Identifier      >>      1       >>std
Identifier      >>      1       >>main
Identifier      >>      1       >>DIR
Identifier      >>      5       >>dir
Identifier      >>      1       >>dirent
Identifier      >>      5       >>entity
Identifier      >>      3       >>totalGsum
Identifier      >>      3       >>totalKey
Identifier      >>      3       >>totalOp
Identifier      >>      3       >>totalSp
Identifier      >>      3       >>totalCh
Identifier      >>      3       >>totalNum
Identifier      >>      3       >>totalStr
Identifier      >>      3       >>totalArr
Identifier      >>      3       >>totalId
Identifier      >>      15      >>cout
Identifier      >>      1       >>gets
Identifier      >>      3       >>strcpy
Identifier      >>      1       >>opendir
Identifier      >>      22      >>endl
Identifier      >>      1       >>exit
Identifier      >>      2       >>readdir
Identifier      >>      2       >>strcat
Identifier      >>      1       >>d_name
Identifier      >>      1       >>checkPath
Identifier      >>      6       >>bufferP
Identifier      >>      2       >>lexNode
Identifier      >>      4       >>parseHead
Identifier      >>      13      >>parseP
Identifier      >>      4       >>headNode
Identifier      >>      20      >>headP
Identifier      >>      3       >>kc
Identifier      >>      3       >>oc
Identifier      >>      3       >>spc
Identifier      >>      3       >>ccc
Identifier      >>      3       >>ncc
Identifier      >>      3       >>sc
Identifier      >>      3       >>ac
Identifier      >>      3       >>ic
Identifier      >>      4       >>grandSum
Identifier      >>      3       >>lexSum
Identifier      >>      1       >>getFile
Identifier      >>      2       >>strtok
Identifier      >>      2       >>appendLex
Identifier      >>      10      >>next
Identifier      >>      1       >>setType
Identifier      >>      1       >>searchFreq
Identifier      >>      2       >>lex
Identifier      >>      1       >>type
Identifier      >>      8       >>printType
Identifier      >>      1       >>countTotalFreq(
Identifier      >>      7       >>countTotalFreq
Identifier      >>      2       >>system

Total           >>      56      >>Identifier

****************************************

LexSum Is:133

GrandSum Is:735


C:\Users\Teoman\Desktop\code\utility.h

Keyword         >>      1       >>include
Keyword         >>      1       >>bool
Keyword         >>      4       >>char
Keyword         >>      2       >>if
Keyword         >>      2       >>return
Keyword         >>      1       >>true
Keyword         >>      1       >>else
Keyword         >>      1       >>false
Keyword         >>      1       >>void
Keyword         >>      1       >>int
Keyword         >>      1       >>while

Total           >>      11      >>Keyword

****************************************

Operator        >>      5       >>*
Operator        >>      6       >>=
Operator        >>      1       >>!=
Operator        >>      1       >>++

Total           >>      4       >>Operator

****************************************

Special Char    >>      1       >>#
Special Char    >>      11      >>(
Special Char    >>      11      >>)
Special Char    >>      6       >>{
Special Char    >>      3       >>,
Special Char    >>      11      >>;
Special Char    >>      6       >>}
Special Char    >>      2       >>[
Special Char    >>      2       >>]

Total           >>      9       >>Special Char

****************************************

Char Const      >>      1       >>'\0'

Total           >>      1       >>Char Const

****************************************

Num Const       >>      1       >>0

Total           >>      1       >>Num Const

****************************************

String          >>      2       >>"r+"

Total           >>      1       >>String

****************************************

Identifier      >>      1       >><iostream>
Identifier      >>      1       >>checkPath
Identifier      >>      2       >>path
Identifier      >>      2       >>FILE
Identifier      >>      7       >>fp
Identifier      >>      2       >>fopen
Identifier      >>      2       >>fclose
Identifier      >>      1       >>getFile
Identifier      >>      2       >>directory
Identifier      >>      3       >>file
Identifier      >>      3       >>c
Identifier      >>      4       >>i
Identifier      >>      1       >>getc
Identifier      >>      1       >>EOF

Total           >>      14      >>Identifier

****************************************

LexSum Is:41

GrandSum Is:118

****************************************
Grand Summation
****************************************

Keyword         >>47
Operator        >>163
Special Char    >>297
Char Const      >>1
Num Const       >>19
String          >>61
Array           >>22
Identifier      >>243
Grand Sum       >>853

Press any key to continue . . .
