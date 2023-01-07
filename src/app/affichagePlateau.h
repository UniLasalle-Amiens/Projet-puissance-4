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
    printf ( "  " );
    for ( int i = 0 ; i < COLONNES ; i++ )
        printf ( " %d", i + 1 );
    

    // Affichage du plateau de jeu
    for ( int i = 0 ; i < LIGNES ; i++ ) {
        printf ( "\n" );
        
        printf ( "\t\t%d |", i + 1 );

        for ( int y = 0 ; y < COLONNES ; y++ ) {
            printf ( "%s", p [ y ] [ i ].color );
            printf ( "%c", p [ y ] [ i ].character );
            color ( RESET );
            
            printf ( "|" );
        }
    }
}
#endif