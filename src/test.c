#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

//ocultamos los cambios internos del contenedor


struct juego{
    char nombre[20];
    int16_t year;
    char rating;
    
    Q_anchor anchor;
};


int main(){
    queue estructura_videoJuegos = malloc(Q_containerByteSize());
    if(estructura_videoJuegos == NULL){
        return 1;
    }
    Q_create(estructura_videoJuegos, offsetof(struct juego, anchor));
    
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
    
    assert(!Q_belongs(estructura_videoJuegos, pacman));//no esta por que no lo hemos metido
    
    assert(!Q_enqueue(estructura_videoJuegos, pacman));
    
    assert(Q_belongs(estructura_videoJuegos, pacman));
    
    assert(!Q_enqueue(estructura_videoJuegos, battleCity));
    
    int32_t ret=0;
    
    struct juego *primero = NULL;
    if((ret = Q_peek(estructura_videoJuegos, (void**)&primero)) != 0){
        printf("error %d\n", ret);
        exit(1);
    }
    Q_pop(estructura_videoJuegos);
    
    printf("PRIMERO\n");
    printf("%s\n", primero->nombre);
    printf("%d\n", primero->year);
    
    assert(!Q_enqueue(estructura_videoJuegos, primero));
    
    struct juego *segundo = NULL;
    if((ret = Q_peek(estructura_videoJuegos, (void**)&segundo)) != 0){
        printf("error %d\n", ret);
        exit(1);
    }
    printf("SEGUNDO\n");
    printf("%s\n", segundo->nombre);
    printf("%d\n", segundo->year);
    Q_pop(estructura_videoJuegos);
    
    struct juego *tercero = NULL;
    if((ret = Q_peek(estructura_videoJuegos, (void**)&tercero)) != 0){
        printf("error %d\n", ret);
        exit(1);
    }
    printf("TERCERO\n");
    printf("%s\n", tercero->nombre);
    printf("%d\n", tercero->year);
    
    free(segundo);
    free(primero);
    free(estructura_videoJuegos);
    
    //debug_print(estructura_videoJuegos);
}


