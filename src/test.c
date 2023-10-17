#include "lib.h"
#include <stdlib.h>

struct juego{
    char nombre[20];
    int16_t year;
    char rating;
    
    Q_anchor anchor;
};

int main(){
    queue estructura_videoJuegos = NULL;
    Q_create(&estructura_videoJuegos, offsetof(struct juego, anchor));
    
    struct juego *pacman = malloc(sizeof(struct juego));
    *pacman = (struct juego){
        .nombre = "pacman",
        .year = 1950,
        .rating = 'a',
    };
    
    struct juego *battleCity = malloc(sizeof(struct juego));
    *pacman = (struct juego){
        .nombre = "battleCity",
        .year = 1961,
        .rating = 'a',
    };
    
    Q_enqueue(estructura_videoJuegos, pacman);
    Q_enqueue(estructura_videoJuegos, battleCity);
    
    debug_print(estructura_videoJuegos);
}
