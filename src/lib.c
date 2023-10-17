#include "lib.h"
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


struct Q_container{
    struct Q_anchor *next;
    struct Q_anchor *last;
    int64_t size;
    ptrdiff_t offset;
};


int32_t Q_create(queue *container, ptrdiff_t offset){
    if(*container != NULL){
        return 1;
    }
    *container = malloc(sizeof(struct Q_container));
    if(*container == NULL){
        return 1;
    }
    **container = (struct Q_container){
        .next = NULL,
        .last = NULL,
        .size = 0,
        .offset = offset,
    };
    return 0;
}

int32_t Q_pop(queue container, void **holder){
    
}

int32_t Q_peek(queue container, void **holder){
    
}

int32_t Q_enqueue(queue container, void *node){
    struct Q_anchor *anchor = (struct Q_anchor*)((int8_t*)node)+container->offset;
    if(anchor->next != NULL){
        return 1;
    }
    anchor->next = anchor;
    if(container->size != 0){
        container->last->next = anchor;
        container->last = anchor;
    }else{
        container->next = anchor;
        container->last = anchor;
    }
    container->size++;
}

int64_t Q_size(queue container){
    
}

int32_t Q_destroy(queue *container){
    
}

int32_t debug_print(queue container){
    printf("next: %p\n", container->next); 
    printf("last: %p\nsize: %ld\noffset: %d\n", container->last, container->size, container->offset);
    
    Q_anchor *pivot = container->next;
    int32_t index=0;
    
    if(container->size != 0){
        while(pivot->next!=pivot){
            printf("nodo %d\n", index);
            pivot = pivot->next;
            index++;
            
        }
        printf("nodo %d\n", index);
    }
}
