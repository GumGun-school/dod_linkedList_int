#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
        //.nombre = ,
        .year = 1950,
        .rating = 'a',
    };
    strcpy(pacman->nombre, "pacman");
    
    struct juego *battleCity = malloc(sizeof(struct juego));
    *battleCity = (struct juego){
        //.nombre = "battleCity",
        .year = 1961,
        .rating = 'a',
    };
    strcpy(battleCity->nombre,"battleCity");
    
    
    Q_enqueue(estructura_videoJuegos, pacman);
    Q_enqueue(estructura_videoJuegos, battleCity);
    
    struct juego *primero = NULL;
    int32_t ret=0;
    if((ret = Q_peek(estructura_videoJuegos, (void**)&primero)) != 0){
        printf("error %d\n", ret);
        exit(1);
    }
    Q_pop(estructura_videoJuegos);
    printf("%s\n", primero->nombre);
    printf("%d\n", primero->year);
    
    struct juego *segundo = NULL;
    ret=0;
    if((ret = Q_peek(estructura_videoJuegos, (void**)&segundo)) != 0){
        printf("error %d\n", ret);
        exit(1);
    }
    printf("%s\n", segundo->nombre);
    printf("%d\n", segundo->year);
    
    free(segundo);
    free(primero);
    
    //debug_print(estructura_videoJuegos);
}
