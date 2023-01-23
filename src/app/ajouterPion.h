#ifndef AJOUTER_PION_H
#define AJOUTER_PION_H

/**
 * Fonction permettant d'ajouter des pions au plateau
 * @name ajouterPion
 * @param plateau Tableau double dimension contenant toutes les caractéristiques de chaque case du plateau de jeu
 * @param c Colonne choisit par l'utilisateur
 * @param l Pointeur vers la variable stockant la dernière ligne du plateau où le pion est tombé
 * @param joueur Type integer contenant soit le joueur 1 ou 2 qui doit jouer
 * @return void
*/
void ajouterPion ( Pion plateau [ COLONNES ] [ LIGNES ], int c, int *l, int joueur ) {
    int line = 0;
    bool down = true;
    char color [ 40 ];

    if ( joueur == 1 )
        strcpy ( color, ROUGE );
    else
        strcpy ( color, JAUNE );

    do {
        if ( plateau [ c - 1 ] [ line ].character != '0' && line < LIGNES )
            line++;

        else {
            plateau [ c - 1 ] [ line - 1 ].character = '0';
            strcpy ( plateau [ c - 1 ] [ line - 1 ].color, color );
            
            down = false;
        }

    } while ( down );

    *l = line;
}

#endif