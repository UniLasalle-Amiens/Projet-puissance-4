#ifndef WIN_H
#define WIN_H

/**
 * Fonction permettant de déterminer si un des deux joueurs à gagné
 * @brief win
 * @param plateau Plateau du jeu de type Pion
 * @param ligne Ligne correspondante au dernier pion posé
 * @param colonne Colonne correspondante au dernier pion posé
 * @param joueur Joueur venant de jouer
 * @return 1 | 2
*/
int win (Pion plateau[COLONNES][LIGNES], int ligne, int colonne, int joueur ) {
    int score;
    char couleur [ 256 ];

    // Vérification verticale
    

    if ( score == 1 && strcmp ( couleur, ROUGE ) == 0 )
        return 1;
    else
        return 2;
}


#endif