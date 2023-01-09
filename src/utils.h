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
#define NB_PIONS_EQUIPE 21


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
        printf ( "\n\nAppuyer sur une entree pour continuer..." );
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
 * @return void
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
 * Permet de retourner un nombre aléatoire entre 0 7 inclus
 * @name random_number
 * @return Nombre entier entre 1 et 7 inclus
*/
int random_number() {
    srand(time(NULL));  // Initialisation de rand() avec une seed différente à chaque exécution
    return rand() % 7 + 1;  // Retourne un nombre entier aléatoire compris entre 0 et 7 (inclus)
}

#ifndef WIN32
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