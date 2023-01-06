#ifndef AFFICHER_REGLES_H
#define AFFICHER_REGLES_H

void afficherRegles () {
    clear ();
    
    color ( BLEU );
    printf ( "Fonctionnement du jeu:" );
    color ( RESET );

    color ( ROUGE );

    printf ( "\nLe programme vous demandera automatiquement avant chaque coup la ligne ainsi que la colonne où vous voulez jouer\n" );
    printf ( "Le programme traite automatiquement toutes les regles du jeu et vous indiquera si le pion est jouable ou pas\n" );

    color ( RESET );
    
    color ( BLEU );
    printf ( "\n\nGagner une partie:" );
    printf ( "\nAfin de gagner une partie, il suffit d'être le premier à aligner 4 jetons \nhorizontalemente, verticalementainsi que diagonalement" );
    
    color ( RESET );
    PAUSE ();
}

#endif