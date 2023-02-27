#ifndef GAME_H
#define GAME_H

/**
 * Fonction de lancement du jeu
 * @name game
 * @param choix Variable de type integer contenant le choix du joueur pour le type de partie
 * @param level_IA Choix par l'utilisateur du level de l'IA pour le jeu
 * @return void
*/
void game ( int choix, int level_IA ) {
    Pion plateau [ COLONNES ] [ LIGNES ]; // Création du plateau

    bool reply, loop = true;
    int score;
    int joueur = 2; // 1 ou 2 En fonction du joueur qui doit jouer
    int col; // Colonne choisie par l'utilisateur ou par l'IA
    int ligne; // Ligne où le pion est tombé
    int count; // Compteur de pions joué - tour par tour

    bool ask; // Variable locale pour la gestion d'erreur de saisie de l'utilisateur

    initCase ( plateau );
    
    while ( loop ) {
        color ( RESET );
        afficherPlateau ( plateau ); // Affichage du plateau

        if ( score == 1 ) {
            color ( ROUGE );
            printf ( "\n\nLe joueur 1 à gagné !!" );
            color ( RESET );

            #ifdef __linux__
            flush_linux ();
            #elif __APPLE__
            fflush ( stdin );
            #endif

            PAUSE ();
            loop = false;
            break;

        } else if ( score == 2 ) {
            color ( JAUNE );
            printf ( "\n\nLe joueur 2 à gagné !!" );
            color ( RESET );

            #ifdef __linux__
            flush_linux ();
            #elif __APPLE__
            fflush ( stdin );
            #endif

            PAUSE ();
            loop = false;
            break;
        }

        if ( count == NB_PIONS ) {
            color ( CYAN );
            printf ( "\n\nAucun des deux joueurs n'a gagné !\n" );
            printf ( "Match nul" );
            color ( RESET );

            #ifdef __linux__
            flush_linux ();
            #elif __APPLE__
            fflush ( stdin );
            #endif

            PAUSE ();
            loop = false;
            break;
        }

        if ( !reply )
            joueur = tourJoueur ( joueur ); // Permet le changement de joueur
        

        // On vérifie si le joueur qui doit jouer est l'IA ou non par rapport au choix du joueur au lancement du jeu
        if ( choix == 1 ) {
            if ( joueur == 1 ) {
                do {
                    color ( ROUGE );

                    printf ( "\n\nJoueur %d à vous de jouer", joueur );
                    color ( RESET );
                    
                    printf ( "\n\nVeuillez choisir une colonne: " );

                    #ifdef WIN32
                    fflush ( stdin );
                    #endif

                    scanf ( "%d", &col );

                    // Gestion des potentielles erreurs de saisie de l'utilisateur
                    if ( col < 1 || col > COLONNES ) {
                        printf ( "\n\nVous devez choisir une colonne parmis celles disponibles sur la plateau" );

                        #ifdef __linux__
                        flush_linux ();
                        #endif

                        PAUSE ();

                        if ( !ask )
                            ask = true;

                    } else
                        ask = false;

                } while ( ask );


            // Tour de l'IA
            } else {
                if ( level_IA == 1 )
                    col = random_number (); // Génération d'un nombre entier aléatoire entre 1 et 7 inclus

                else if ( level_IA == 2 )
                    col = meilleurCoup ( plateau, 2, joueur ) + 1;
                
                else
                    col = meilleurCoup ( plateau, 4, joueur ) + 1;
            }

        } else {
            do {
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

                // Gestion des potentielles erreurs de saisie de l'utilisateur
                if ( col < 1 || col > 7 ) {
                    printf ( "\n\nVous devez choisir une colonne parmis celles disponibles sur la plateau" );

                    #ifdef __linux__
                    flush_linux ();
                    #elif __APPLE__
                    fflush ( stdin );
                    #endif

                    PAUSE ();

                    if ( !ask )
                        ask = true;

                } else
                    ask = false;
                    
            } while ( ask );
        }
        
        // On vérifie si la colonne choisie n'est pas pleine
        if ( plateau [ col - 1 ] [ 0 ].character == '0' ) {
            reply = true;

            if ( joueur != 2 && choix == 1 || choix == 2 ) {
                clear ();
                printf ( "Cette colonne est pleine, veuillez en choisir une autre" );

                #ifdef __linux__
                flush_linux ();
                #elif __APPLE__
                fflush ( stdin );
                #endif
                PAUSE ();
            }

        } else {
            reply = false;

            printf ( "\n\n" );

            if ( score != 1 && score != 2 )
                ajouterPion ( plateau, col, &ligne, joueur );
            

            score = win ( plateau, ligne, col, joueur );
            count++;
        }
    }
}

#endif