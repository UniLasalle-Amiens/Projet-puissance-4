#ifndef GAME_H
#define GAME_H

/**
 * Fonction de lancement du jeu
 * @name game
 * @param choix Variable de type integer contenant le choix du joueur pour le type de partie
 * @param *loop Variables de type boolean pour la bouclle du jeu
 * @return void
*/
void game ( int choix, bool *loop ) {
    Pion plateau [ COLONNES ] [ LIGNES ]; // Création du plateau

    int joueur = 2; // 1 ou 2 En fonction du joueur qui doit jouer
    int col; // Colonne choisie par l'utilisateur

    initCase ( plateau );
    
    while ( *loop ) {
        afficherPlateau ( plateau ); // Affichage du plateau

        tourJoueur ( &joueur ); // Tour de chaque joueurs

        if ( joueur == 1 )
            color ( ROUGE );
        else
            color ( JAUNE );

        printf ( "\n\nJoueur %d à vous de jouer", joueur );
        color ( RESET );
        
        printf ( "\n\nVeuillez choisir une colonne: " );

        #ifdef WIN32
        fflush ( stdin );
        #endif

        scanf ( "%d", &col );
        
        if ( plateau [ col - 1 ] [ 0 ].character == '0' ) {
            clear ();
            printf ( "Cette colonne est pleine veuillez en choisir une autre" );

            #ifndef WIN32
            flush_linux ();
            #endif
            
            PAUSE ();

        } else
            ajouterPion ( plateau, col, joueur );
    }
}

#endif