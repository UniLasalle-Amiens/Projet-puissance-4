#ifndef EVALUER_SCORE_H
#define EVALUER_SCORE_H

/**
 * @brief evaluerScore
 * Fonction permettant d'évaluer le score total d'un joueur après un coup joué
 * @param plateau tableau à double dimensions contenant le plateau de jeu
 * @param colonne colonne du dernier pion joué
 * @param ligne ligne du dernier pion joué
 * @return integer / score obtenue par le coup joué
*/
int evaluerScore(Pion plateau[COLONNES][LIGNES], int colonne, int ligne) {
  int score = 0;

  // Vérifier les lignes
  for (int c = 0; c < COLONNES; c++) {
    if ( strcmp ( plateau[c][ligne].color, plateau[colonne][ligne].color) == 0 ) {
      score++;
    } else {
      break;
    }
  }

  // Vérifier les colonnes
  for (int l = 0; l < LIGNES; l++) {
    if (plateau[colonne][l].color == plateau[colonne][ligne].color) {
      score++;
    } else {
      break;
    }
  }

  // Vérifier les diagonales descendantes
  int c = colonne;
  int l = ligne;
  while (c > 0 && l < LIGNES - 1) {
    c--;
    l++;
  }
  while (c < COLONNES - 1 && l > 0) {
    if ( strcmp ( plateau[c][l].color, plateau[colonne][ligne].color) == 0 ) {
      score++;
    } else {
      break;
    }
    c++;
    l--;
  }

  // Vérifier les diagonales montantes
  c = colonne;
  l = ligne;
  while (c > 0 && l > 0) {
    c--;
    l--;
  }
  while (c < COLONNES - 1 && l < LIGNES - 1) {
    if ( strcmp ( plateau[c][l].color, plateau[colonne][ligne].color ) == 0 ) {
      score++;
    } else {
      break;
    }
    c++;
    l++;
  }

  return score;
}

#endif
