#ifndef AFFICHAGE_PLATEAU_H
#define AFFICHAGE_PLATEAU_H

/**
 * Fonction permettant l'affichage du plateau de jeu dans la console
 * @name afficherPlateau
 * @return void
*/
void afficherPlateau () {
    clear ();
    int line = 1;

    for ( int i = 0 ; i < COLONNES ; i++ )
        printf ( " _" );
    
    for ( int i = 0 ; i < LIGNES ; i++ ) {
        printf ( "\n" );
        printf ( "|" );

        for ( int i = 0 ; i < COLONNES ; i++ ) {
            printf ( " " );
            printf ( "|" );
        }

        line++;
    }
}
#endif