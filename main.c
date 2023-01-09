#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Utilitaires
#include "src/utils.h"
#include "src/structs.h"

// Affichage
#include "src/afficherMenu.h"
#include "src/afficherRegles.h"

// App
#include "src/app/affichagePlateau.h"
#include "src/app/initCase.h"
#include "src/app/ajouterPion.h"
#include "src/app/tourJoueur.h"

#include "src/app/game.h"


int main ( int argc, char const **argv [] ) {
    bool loop = true;
    int choix, level_IA;

    while ( loop ) {
        afficherMenu ( &choix );

        switch ( choix ) {
            case 1:
                printf ( "\n\nVeuillez choisir la difficulté" );
                printf ( "\n\t1: NUL\n\t2: MOYEN" );
                printf ( "\n\nVotre choix: " );

                #ifdef WIN32
                fflush ( stdin );
                #endif
                
                scanf ( "%d", &level_IA );
                
                game ( 1, level_IA, &loop );
                loop = false;
                break;
            
            case 2:
                game ( 2, level_IA, &loop );
                loop = false;
                break;

            case 3:
                afficherRegles ();
                break;
        }
    }

    return EXIT_SUCCESS;
}