# include <iostream>

bool checkPath ( char * path ) {
    FILE * fp = fopen ( path , "r+" ) ;
    if ( fp ) {
        fclose ( fp ) ;
        return true ;
    }
    else {
        return false ;
    }
}

void getFile ( char * directory , char * file ) {
	FILE * fp = fopen ( directory , "r+" ) ;
	char c ;
	int i = 0 ;

	if ( fp ) {
		while ( ( c = getc ( fp ) ) != EOF ) {
			file [ i ] = c ;
			i ++ ;
		}
		file [ i ] = '\0' ;
	}

	fclose ( fp ) ;
}
