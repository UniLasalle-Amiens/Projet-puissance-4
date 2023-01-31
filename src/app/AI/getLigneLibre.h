#ifndef GET_LIGNE_LIBRE_H
#define GET_LIGNE_LIBRE_H

/**
 * @brief getLigneLibre
 * fonction permettant d'obtenir une colonne de libre
 * @param plateau tableau à double dimension contenant le plateau de jeu
 * @param colonne colonne jouée
*/
int getLigneLibre(Pion plateau[COLONNES][LIGNES], int colonne) {
  for (int ligne = LIGNES - 1; ligne >= 0; ligne--) {
    if (plateau[colonne][ligne].character == ' ') {
      return ligne;
    }
  }

  return -1;
}

#endif