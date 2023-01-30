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
#include "src/app/win.h"

#include "src/app/game.h"


int main ( int argc, char const **argv [] ) {
    bool loop = true, ask;
    int choix;
    int level;

    while ( loop ) {
        afficherMenu ( &choix );

        switch ( choix ) {
            case 1:
                do {
                    clear ();
                    printf ( "Veuillez choisir la difficulté" );
                    printf ( "\n\t1: NUL\n\t2: FORT" );
                    printf ( "\n\nVotre choix: " );

                    #ifdef WIN32
                    fflush ( stdin );
                    #endif

                    scanf ( "%d", &level );

                    if ( level != 2 && level != 1 ) {
                        printf ( "\n\nNiveau d'IA inconnu" );

                        #ifdef __linux__
                        flush_linux ();
                        #elif __APPLE__
                        fflush ( stdin );
                        #endif
                        PAUSE ();

                        ask = true;

                    } else
                        ask = false;

                } while ( ask );
                
                if ( !ask ) {
                    game ( choix, level );
                    break;

                } else
                    continue;

            case 2:
                game ( choix, level );
                break;

            case 3:
                afficherRegles ();
                break;

            case 4:
                loop = false;
                clear ();
                
                color ( MAGENTA );
                printFile ( fopen ( "tools/thanks.txt", "r" ) );
                color ( RESET );
                break;

            default:
                printf ( "\n\nVeuillez choisir une des options disponibles au dessus" );

                #ifdef __linux__
                flush_linux ();
                #elif __APPLE__
                fflush ( stdin );
                #endif

                PAUSE ();
                continue;
        }
    }

    return EXIT_SUCCESS;
}