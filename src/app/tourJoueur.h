#ifndef TOUR_JOUEUR_H
#define TOUR_JOUEUR_H

/**
 * Fonction permettant de faire jouer un à un les deux joueurs de la partie
 * @name tourJoueur
 * @return Integer, soit 1, soit 2 en fonction du joueur venant de jouer
*/
int tourJoueur ( int joueur ) {
    if ( joueur % 2 == 0 )
        return 1;
    else
        return 2;
}
#endif