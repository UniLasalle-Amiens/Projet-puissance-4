/**
 * @brief evaluate
 * Fonction d'évaluation du plateau
 * @param plateau Plateau de jeu
 * @param joueur Joueur jouant actuellement
 * @return -10 | 10 | 0 - score du plateau pour le joueur ou l'IA
*/
int evaluate(Pion plateau[COLONNES][LIGNES], char couleur [] )
{   
    int playerScore = 0, opponentScore = 0, emptySpaces = 0;

    // Vérifie chaque ligne, alignement horizontal
    for (int row = 0; row < LIGNES ; row++)
    {
        for (int col = 0; col < COLONNES - 3 ; col++)
        {
            int countPlayer = 0, countOpponent = 0;

            for ( int k = 0 ; k < 4 ; k++ ) {
                if ( strcmp ( plateau [ col + k ] [ row ].color, couleur ) == 0 )
                    countPlayer++;
                else if ( plateau [ col  + k ] [ row ].character != ' ' )
                    countOpponent++;
            }

            if ( countPlayer == 4 )
                playerScore += 100;

            else if ( countPlayer > 0 && countOpponent == 0 )
                playerScore += countPlayer;

            if ( countOpponent == 4 )
                opponentScore += 100;

            else if ( countOpponent > 0 && countPlayer == 0 )
                opponentScore += countOpponent;
        }
    }

    // Vérifie chaque colonne, alignement vertical
    for (int col = 0; col < COLONNES; col++)
    {
        for (int row = 0; row < LIGNES - 3; row++)
        {
            int countPlayer = 0, countOpponent = 0;

            for ( int k = 0 ; k < 4 ; k++ ) {
                if ( strcmp ( plateau [ col ] [ row + k ].color, couleur ) == 0 )
                    countPlayer++;

                else if ( plateau [ col ] [ row + k ].character != ' ' )
                    countOpponent++;
            }

            if (countPlayer == 4) {
                playerScore += 100;

            } else if (countPlayer > 0 && countOpponent == 0) {
                playerScore += countPlayer;
            }
            if (countOpponent == 4) {
                opponentScore += 100;

            } else if (countOpponent > 0 && countPlayer == 0) {
                opponentScore += countOpponent;
            }
        }
    }

    // Vérifie les diagonales descendantes
    for (int i = 0; i < LIGNES - 3; i++) {
        for (int j = 0; j < COLONNES - 3; j++) {
            int countPlayer = 0;
            int countOpponent = 0;
            for (int k = 0; k < 4; k++) {
                if ( strcmp (plateau[i + k][j + k].color, couleur) == 0 ) {
                    countPlayer++;
                } else if (plateau[i + k][j + k].character != ' ') {
                    countOpponent++;
                }
            }
            if (countPlayer == 4) {
                playerScore += 100;
            } else if (countPlayer > 0 && countOpponent == 0) {
                playerScore += countPlayer;
            }
            if (countOpponent == 4) {
                opponentScore += 100;
            } else if (countOpponent > 0 && countPlayer == 0) {
                opponentScore += countOpponent;
            }
        }
    }

    // Vérifie les diagonales montantes
    for (int i = 0; i < LIGNES - 3; i++) {
        for (int j = 0; j < COLONNES - 3; j++) {
            int countPlayer = 0;
            int countOpponent = 0;
            for (int k = 0; k < 4; k++) {
                if (strcmp (plateau[i + k][j - k].color, couleur) == 0) {
                    countPlayer++;
                } else if (plateau[i + k][j - k].character != ' ') {
                    countOpponent++;
                }
            }
            if (countPlayer == 4) {
                playerScore += 100;
            } else if (countPlayer > 0 && countOpponent == 0) {
                playerScore += countPlayer;
            }
            if (countOpponent == 4) {
                opponentScore += 100;
            } else if (countOpponent > 0 && countPlayer == 0) {
                opponentScore += countOpponent;
            }
        }
    }

    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (plateau[i][j].character == ' ') {
                emptySpaces++;
            }
        }
    }
    
    if (emptySpaces == 0) {
        return 0;
    } else if ( strcmp ( couleur, ROUGE ) == 0 ) {
        return playerScore - opponentScore + emptySpaces;
    } else {
        return opponentScore - playerScore + emptySpaces;
    }
}