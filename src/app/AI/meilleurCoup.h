/**
 * @brief meilleurCoup
 * Fonction permettant de calculer le meilleur coup pour le joueur
 * @param plateau Plateau de jeu
 * @param depth Profondeur de l'arbre de recherche
 * @param player Joueur actuel
 * @return 1 <= colonne <= 7 - Meilleur coup à jouer pour le tour représenté par la colonne à jouer
*/
int meilleurCoup(Pion plateau [ COLONNES ] [ LIGNES ], int depth, int player)
{
    int bestMove = -1;
    int bestScore = INT_MIN;
    int score;
    int column;
    int row;

    for (column = 0; column < COLONNES; column++) {
        if (isValidMove(plateau, column)) {
            row = get_row ( plateau, column );

            // On joue un premier coup
            plateau [ column ] [ row ].character = '0';
            strcpy ( plateau [ column ] [ row ].color, JAUNE );

            score = minimax(depth, player, plateau, INT_MIN, INT_MAX);

            // On retire le coup
            plateau [ column ] [ row ].character = ' ';
            strcpy ( plateau [ column ] [ row ].color, RESET );

            if (score > bestScore) {
                bestScore = score;
                bestMove = column;
            }
        }
    }

    return bestMove;
}