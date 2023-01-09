#ifndef TOUR_JOUEUR_H
#define TOUR_JOUEUR_H

/**
 * Fonction permettant de faire jouer un à un les deux joueurs de la partie
 * @name tourJoueur
 * @return void
*/
void tourJoueur ( int *joueur ) {
    if ( *joueur % 2 == 0 )
        *joueur = 1;
    else
        *joueur = 2;
}
#endif