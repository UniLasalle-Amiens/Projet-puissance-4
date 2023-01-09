#ifndef AFFICHER_MENU_H
#define AFFICHER_MENU_H

/**
 * Fonction permettant d'afficher le menu pour l'utilisateur
 * @name afficherMenu
 * @param *c Variables contenant le choix de l'utilisateur
 * @return void
*/
void afficherMenu ( int *c ) {
    clear ();
    color ( CYAN );

    printFile ( fopen ( "tools/ASCII-ART.txt", "r" ) );
    color ( RESET );

    printf ( "\n\n\n" );

    printf ( "Bienvenue sur le jeu !\n" );

    printf ( "\t1: Jouer contre l'ordinateur\n" );
    printf ( "\t2: Jouer contre un joueur\n" );
    printf ( "\t3: Règles du jeu\n\n" );
    printf ( "Veuillez faire votre choix: " );

    #ifdef WIN32
    fflush ( stdin );
    #endif
    
    scanf ( "%d", c );
}

#endif