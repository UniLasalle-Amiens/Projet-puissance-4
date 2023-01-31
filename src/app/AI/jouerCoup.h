#ifndef JOUER_COUP_H
#define JOUER_COUP_H

/**
 * @brief jouerCoup
 * Fonction permettant de calculer la colonne la plus favorable à jouer
 * @param plateau plateau de jeu
 * @param couleur couleur du joueur ayant joué un pion
 * @return integer / colonne la plus favorable
*/
int jouerCoup(Pion plateau[COLONNES][LIGNES], char couleur []) {
  int colonneFavorable = -1;
  int scoreMax = INT_MIN;

  for (int colonne = 0; colonne < COLONNES; colonne++) {
    int ligne = getLigneLibre(plateau, colonne);
    if (ligne != -1) {

      // Ajouter un pion de couleur "couleur" à la colonne
      plateau[colonne][ligne].character = '0';
      strcpy ( plateau [ colonne ] [ ligne ].color, couleur );

      // Évaluer l'état du plateau
      int score = evaluerScore(plateau, colonne, ligne);

      // Supprimer le pion
      plateau[colonne][ligne].character = ' ';
      strcpy ( plateau [ colonne ] [ ligne ].color, "" );

      if (score > scoreMax) {
        scoreMax = score;
        colonneFavorable = colonne;
      }
    }
  }

  return colonneFavorable + 1;
}

#endif