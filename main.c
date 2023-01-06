#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "src/utils.h"

#include "src/afficherMenu.h"
#include "src/afficherRegles.h"
#include "src/game.h"


int main ( int argc, char const **argv [] ) {
    bool loop = true;
    int choix;
    
    clear ();
    color ( CYAN );
    color ( RESET );

    while ( loop ) {
        afficherMenu ( &choix );

        switch ( choix ) {
            case 1:
                game ( 1 );
                loop = false;
                break;
            
            case 2:
                game ( 2 );
                loop = false;
                break;

            case 3:
                afficherRegles ();
                break;
        }
    }

    return EXIT_SUCCESS;
}