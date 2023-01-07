#ifndef GAME_H
#define GAME_H

void game ( int choix ) {
    Pion plateau [ COLONNES ] [ LIGNES ];
    
    initCase ( plateau );
    afficherPlateau ( plateau );
}

#endif