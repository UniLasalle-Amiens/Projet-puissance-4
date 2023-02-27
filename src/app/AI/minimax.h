#ifndef MINIMAX_H
#define MINIMAX_H

/**
 * @brief isValidMove
 * Fonction permettant de déterminer si le move choisi est valide
 * @param grid Plateau de jeu
 * @param col colonne du coup voulant être joué
 * @return false | true / selon si le coup est valide ou non
*/
bool isValidMove(Pion grid[COLONNES][LIGNES], int col);

/**
 * @brief minimax
 * Algorithme minimax permettant de minimiser le joueur adverse
 * @param depth Profondeur de l'arbre de recherche
 * @param player Joueur actuel
 * @param plateau Plateau de jeu
 * @param alpha élagage alpha pour le coup maximisant
 * @param beta élagage beta pour le coup minimisant
 * @return bestScore - nombre de points totals minimisé pour le joueur et maximisé pour l'IA
*/
int minimax(int depth, int player, Pion plateau [COLONNES] [ LIGNES ], int alpha, int beta)
{
    int bestScore;

    int score = evaluate ( plateau, ( player == 1 ) ? ROUGE : JAUNE );

    // Renvoi de la valeur d'évaluation
    if ( depth == 0 || score == 100 || score == -100 )
        return score;

    // Si c'est le tour du joueur maximisant, trouver le meilleur score possible
    if (player == AI_PLAYER) {
        bestScore = INT_MIN;

        for (int column = 0; column < COLONNES; column++) {
            if (isValidMove( plateau, column )) { // Si le move choisi par l'IA est valide
                int row = get_row ( plateau, column ); // On obtient la ligne vide la plus basse pour jouer

                // On réalise un premier coup
                plateau [ column ] [ row ].character = '0';
                strcpy ( plateau [ column ] [ row ].color, JAUNE );

                score = minimax ( depth - 1, HUMAN_PLAYER, plateau, alpha, beta );

                // On retire le coup
                plateau [ column ] [ row ].character = ' ';
                strcpy ( plateau [ column ] [ row ].color, RESET );

                bestScore = max(bestScore, score);
                alpha = max(alpha, bestScore);

                // Coupure alpha
                if (beta <= alpha) {
                    break;
                }
            }
        }

        return bestScore;
    }

    // Si c'est le tour du joueur minimisant, trouver le pire score possible pour le joueur maximisant
    else {
        bestScore = INT_MAX;

        for (int column = 0; column < COLONNES; column++) {
            if ( isValidMove( plateau, column ) ) {
                int row = get_row ( plateau, column );

                // On réalise un premier coup
                plateau [ column ] [ row ].character = '0';
                strcpy ( plateau [ column ] [ row ].color, ROUGE );

                score = minimax(depth - 1, AI_PLAYER, plateau, alpha, beta);

                plateau [ column ] [ row ].character = ' ';
                strcpy ( plateau [ column ] [ row ].color, RESET );

                bestScore = min(bestScore, score);
                beta = min(beta, bestScore);

                // Coupure beta
                if (beta <= alpha) {
                    break;
                }
            }
        }

        return bestScore;
    }
}

bool isValidMove(Pion grid[COLONNES][LIGNES], int col) {
    int row = 0;

    // Vérifier si la colonne est pleine
    if (grid[col][0].character == '0') {
        return false;
    }

    // Trouver la première case vide dans la colonne
    while (row < LIGNES && grid[col][row].character != '0') {
        row++;
    }

    // Retourne true si le move est valide
    return true;
}


#endif