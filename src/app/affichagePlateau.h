#ifndef AFFICHAGE_PLATEAU_H
#define AFFICHAGE_PLATEAU_H

/**
 * Fonction permettant l'affichage du plateau de jeu dans la console
 * @name afficherPlateau
 * @param p Tableau à double dimension contenant toutes les cases du plateau de jeu
 * @return void
*/
void afficherPlateau ( Pion p [ COLONNES ] [ LIGNES ] ) {
    clear ();

    // Affichage haut du plateau de jeu
    printf ( "\t\t" );

    for ( int i = 0 ; i < COLONNES ; i++ )
        printf ( " _" );
    

    // Affichage du plateau de jeu
    for ( int i = 0 ; i < LIGNES ; i++ ) {
        printf ( "\n" );
        
        printf ( "\t\t|" );

        for ( int y = 0 ; y < COLONNES ; y++ ) {
            printf ( "%c", p [ y ] [ i ].character );
            printf ( "|" );
        }
    }
}
#endif