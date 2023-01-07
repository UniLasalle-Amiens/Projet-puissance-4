#ifndef INIT_CASE_H
#define INIT_CASE_H

/**
 * Fonction permettant d'initialiser chaque case du plateau et/ou de les manipuler par la suite
 * @name initCase
 * @param plateau Tableau à double dimension contenant les cases de notre plateau de jeu
 * @return void
*/
void initCase ( Pion plateau [ COLONNES ] [ LIGNES ] ) {
    for ( int x = 0 ; x < COLONNES ; x++ )
        for ( int y = 0 ; y < LIGNES ; y++ ) {
            plateau [ x ] [ y ].character = ' ';
        }
}

#endif