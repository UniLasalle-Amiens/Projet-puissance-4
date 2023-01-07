#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Utilitaires
#include "src/utils.h"
#include "src/structs.h"

// Affichage
#include "src/afficherMenu.h"
#include "src/afficherRegles.h"

// App
#include "src/app/affichagePlateau.h"
#include "src/app/initCase.h"
#include "src/app/game.h"


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