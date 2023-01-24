#ifndef WIN_H
#define WIN_H

/**
 * Fonction permettant de déterminer si un des deux joueurs à gagné
 * @name win
 * @param plateau Plateau du jeu de type Pion
 * @param ligne Ligne correspondante au dernier pion posé
 * @param colonne Colonne correspondante au dernier pion posé
 * @param joueur Joueur venant de jouer
 * @return 0 | 1 | 2
*/
int win (Pion plateau[COLONNES][LIGNES], int ligne, int colonne, int joueur ) {
    int score = 0;
    int streak = 0;

    char couleur [ 256 ];

    if ( joueur == 1 )
        strcpy ( couleur, ROUGE );
    else
        strcpy ( couleur, JAUNE );

    // Vérification verticale
    for ( int i = 0 ; i <= 3 ; i++ ) {
        if ( strcmp ( couleur, plateau [ colonne - 1 ] [ ligne + i ].color ) == 0 )
            streak++;
        else {
            streak = 0;
            break;
        }

        if ( streak == 3 )
            if ( joueur == 1 )
                score = 1;
            else
                score = 2;
    }

    // Si l'un des deux joueurs n'a toujours pas gagné, alors on vérifie d'autres combinaisons possibles
    if ( score != 1 && score != 2 ) {

        // // Vérification horizontale à droite
        // for ( int i = 0 ; i <= 3 ; i++ ) {
        //     if ( strcmp ( plateau [ colonne - i ] [ ligne - 1 ].color, couleur ) == 0 )
        //         streak++;
        //     else
        //         break;

        //     if ( streak == 2 )
        //         if ( joueur == 1 )
        //             score = 1;
        //         else
        //             score = 2;
        // }

        // Vérification horizontale à droite
        for ( int i = 0 ; i <= 3 ; i++ ) {
            if ( strcmp ( plateau [ colonne + i ] [ ligne - 1 ].color, couleur ) == 0 )
                streak++;
            else {
                streak = 0;
                break;
            }

            if ( streak == 3 )
                if ( joueur == 1 )
                    score = 1;
                else
                    score = 2;
        }
    }

    return score;
}

#endif