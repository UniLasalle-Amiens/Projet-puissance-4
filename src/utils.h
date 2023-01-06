#ifndef UTILS_H
#define UTILS_H

#ifdef WIN32
    #define clear() system ( "cls" )
#else
    #define clear() system ( "clear" )
#endif

void PAUSE () {
    printf ( "\n\nAppuyer sur une entree pour continuer..." );
    getchar ();
    getchar ();
}

#ifndef WIN32
    void flush_linux () {
        char c;
        while ( ( c = getchar () ) != '\n' && c != EOF );
    }
#endif

#endif