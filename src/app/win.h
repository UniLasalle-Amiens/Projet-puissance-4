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
    for ( int i = 1 ; i < 4 ; i++ ) {
        if ( strcmp ( couleur, plateau [ colonne - 1 ] [ ( ligne - 1 ) + i ].color ) != 0 )
            break;

        if ( i == 3 )
            if ( joueur == 1 )
                score = 1;
            else
                score = 2;
    }

    // Si l'un des deux joueurs n'a toujours pas gagné, alors on vérifie horizontalement
    if ( score != 1 && score != 2 ) {

        // Vérification horizontale à gauche
        for ( int i = 1 ; i < 4 ; i++ ) {
            if ( strcmp ( plateau [ ( colonne - 1 ) - i ] [ ligne - 1 ].color, couleur ) == 0 )
                streak++;

            else
                break;
        }

        // Vérification horizontale à droite
        for ( int i = 1 ; i < 4 ; i++ ) {
            if ( strcmp ( plateau [ ( colonne - 1 ) + i ] [ ligne - 1 ].color, couleur ) == 0 )
                streak++;

            else
                break;
        }

        // Si quatres pions alignés horizontalement alors le joueur à gagné
        if ( streak == 3 )
            if ( joueur == 1 )
                score = 1;
            else
                score = 2;
    }

    // ---- vérification diagonale gauche
    if ( score != 1 && score != 2 ) {
        int count = 1;
        streak = 0;

        // Diagonale montante
        for ( int i = 1 ; i < 4 ; i++ ) {
            if ( strcmp ( plateau [ ( colonne - 1 ) - i ] [ ( ligne - 1 ) - count ].color, couleur ) == 0 ) {
                count++; // Incrémentation du compteur de ligne
                streak++; // Incrémentation du compteur de pions alignés

            } else {
                count = 1;
                break;
            }
        }

        // Diagonale descendente
        for ( int i = 1 ; i < 4 ; i++ ) {
            if ( strcmp ( plateau [ ( colonne - 1 ) + i ] [ ( ligne - 1 ) + count ].color, couleur ) == 0 ) {
                count++;
                streak++;

            } else {
                count = 1;
                break;
            }
        }

        // Si quatres pions alignés diagonalement alors le joueur à gagné
        if ( streak == 3 )
            if ( joueur == 1 )
                score = 1;
            else
                score = 2;
    }


    // Vérification diagonale droite
    if ( score != 1 && score != 2 ) {
        int count = 1;
        streak = 0;

        // Diagonale montante
        for ( int i = 1 ; i < 4 ; i++ ) {
            if ( strcmp ( plateau [ ( colonne - 1 ) + i ] [ ( ligne - 1 ) - count ].color, couleur ) == 0 ) {
                count++; // Incrémentation du compteur de ligne
                streak++; // Incrémentation du compteur de pions alignés

            } else {
                count = 1;
                break;
            }
        }

        // Diagonale descendente
        for ( int i = 1 ; i < 4 ; i++ ) {
            if ( strcmp ( plateau [ ( colonne - 1 ) - i ] [ ( ligne - 1 ) + count ].color, couleur ) == 0 ) {
                count++;
                streak++;

            } else {
                count = 1;
                break;
            }
        }

        // Si quatres pions alignés diagonalement alors le joueur à gagné
        if ( streak == 3 )
            if ( joueur == 1 )
                score = 1;
            else
                score = 2;
    }

    return score;
}

#endif