#ifndef UTILS_H
#define UTILS_H

#ifdef WIN32
    #define clear() system ( "cls" )
#else
    #define clear() system ( "clear" )
#endif

// Constantes de Jeu
#define LIGNES 6
#define COLONNES 7

#define NB_PIONS 42

#define AI_PLAYER 2
#define HUMAN_PLAYER 1


// Constantes Couleurs
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define BLEU "\033[0;34m"
#define ROUGE "\033[0;31m"
#define JAUNE "\033[0;33m"
#define VERT "\033[0;32m"
#define BLANC "\033[0;37m"

#define RESET "\033[0m"

/**
 * Permet de faire une pause dans le programme
 * @name PAUSE
 * @return void
*/
void PAUSE () {
    #ifndef WIN32
        printf ( "\n\nAppuyer sur entree pour continuer..." );
        getchar ();

    #else
        printf ( "\n\n" );
        system ( "pause" );
    #endif
}

/**
 * Permet d'afficher de la couleur dans la console à l'aide de code ANSI
 * @name color
 * @param c Chaine de caractères contenant le code ANSI
 * @return void
*/
void color ( char c [] ) {
    printf ( "%s", c );
}

/**
 * Permet d'afficher dans la console le contenu du fichier ouvert
 * @name printFile
 * @param *file fichier possédant le contenue à afficher
 * @return integer | void
*/
int printFile ( FILE *file ) {
    char line [ 256 ];

    if (file == NULL) {
        clear ();
        printf("Error opening file!\n");
        return EXIT_FAILURE;

    } else {
        while ( fgets ( line, sizeof ( line ), file ) != NULL )
            printf ( "\t%s", line );
    }
}


/**
 * @brief min
 * Fonction de comparaison ; retourne le plus petit
 * @param a Premier entier
 * @param b Deuxième entier
 * @return a | b
*/
int min ( int a, int b ) {
    return ( a < b ) ? a : b;
}


/**
 * @brief max
 * Fonction de comparaison ; retourne le plus grand
 * @param a Premier entier
 * @param b Deuxième entier
 * @return a | b
*/
int max ( int a, int b ) {
    return ( a > b ) ? a : b;
}


/**
 * @brief get_row
 * @param plateau Plateau de jeu
 * @param column Colonne où placer le pion
 * @return row - ligne vide où placer le pion dans la colonne choisie
*/
int get_row ( Pion plateau [ COLONNES ] [ LIGNES ], int column ) {
    bool down = true;
    int line = 0;
    
    do {
        if ( plateau [ column ] [ line ].character != '0' && line < LIGNES )
            line++;

        else
            down = false;

    } while ( down );

    return line - 1;
}

/**
 * Permet de retourner un nombre aléatoire entre 0 7 inclus
 * @name random_number
 * @return Nombre entier entre 1 et 7 inclus
*/
int random_number() {
    srand(time(NULL));  // Initialisation de rand() avec une seed différente à chaque exécution
    return rand() % 7 + 1;  // Retourne un nombre entier aléatoire compris entre 0 et 7 (inclus)
}

#ifdef __linux__
    /**
     * Permet de vider la cache stdin
     * @name flush_linux
     * @return void
    */
    void flush_linux () {
        char c;
        while ( ( c = getchar () ) != '\n' && c != EOF );
    }
#endif

#endif