#ifndef GAME_H
#define GAME_H

/**
 * Fonction de lancement du jeu
 * @name game
 * @param choix Variable de type integer contenant le choix du joueur pour le type de partie
 * @param level_IA Choix par l'utilisateur du level de l'IA pour le jeu
 * @param *loop Variables de type boolean pour la bouclle du jeu
 * @return void
*/
void game ( int choix, int level_IA, bool *loop ) {
    Pion plateau [ COLONNES ] [ LIGNES ]; // Création du plateau

    bool reply;

    int joueur = 2; // 1 ou 2 En fonction du joueur qui doit jouer
    int col; // Colonne choisie par l'utilisateur ou par l'IA

    initCase ( plateau );
    
    while ( *loop ) {
        color ( RESET );
        afficherPlateau ( plateau ); // Affichage du plateau

        if ( !reply )
            joueur = tourJoueur ( joueur ); // Permet le changement de joueur

        if ( joueur == 1 )
            color ( ROUGE );
        else if ( choix == 2 )
            color ( JAUNE );
        

        // On vérifie si le joueur qui doit jouer est l'IA ou non par rapport au choix du joueur au lancement du jeu
        if ( choix == 1 ) {
            if ( joueur == 1 ) {
                printf ( "\n\nJoueur %d à vous de jouer", joueur );
                color ( RESET );
                
                printf ( "\n\nVeuillez choisir une colonne: " );

                #ifdef WIN32
                fflush ( stdin );
                #endif

                scanf ( "%d", &col );

            } else {
                if ( level_IA == 1 )
                    col = random_number (); // Génération d'un nombre entier aléatoire entre 1 et 7 inclus
            }

        } else {
            printf ( "\n\nJoueur %d à vous de jouer", joueur );
            color ( RESET );
            
            printf ( "\n\nVeuillez choisir une colonne: " );

            #ifdef WIN32
            fflush ( stdin );
            #endif

            scanf ( "%d", &col );
        }
        
        // On vérifie si la colonne choisie n'est pas pleine
        if ( plateau [ col - 1 ] [ 0 ].character == '0' ) {
            if ( joueur != 2 && choix == 1 || choix == 2 ) {
                reply = true;

                clear ();
                printf ( "Cette colonne est pleine, veuillez en choisir une autre" );

                #ifndef WIN32
                flush_linux ();
                #endif
                PAUSE ();

            }

        } else {
            reply = false;

            #ifndef WIN32
            flush_linux ();
            #endif

            ajouterPion ( plateau, col, joueur );
        }

    }
}

#endif