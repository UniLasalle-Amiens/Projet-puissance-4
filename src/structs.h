typedef struct {
    char character;
    char color [ 256 ];
    int x;
    int y;
} Pion;

typedef struct {
    Pion pion;
} Plateau;