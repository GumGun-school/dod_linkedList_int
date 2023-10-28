#include "lib.h"
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

struct Q_container{
    struct Q_anchor *next;
    struct Q_anchor *last;
    int64_t size;
    ptrdiff_t offset;
};

//statics
inline static Q_anchor* s_startToAnchor(queue container, void *node);
inline static Q_anchor* s_anchorToHead(queue container, void *node);

//implementations


int32_t 
Q_create(queue container, ptrdiff_t offset){
    if(container == NULL){
        return 1;
    }
    *container = (struct Q_container){
        .next = NULL,
        .last = NULL,
        .size = 0,
        .offset = offset,
    };
    
    return 0;
}

int32_t 
Q_pop(queue container){
    if(container == NULL){
        return 1;
    }
    Q_anchor *holder = container->next;
    if(container->size == 1){
        container->next = NULL;
        container->last = NULL;
    }else{
        container->next = container->next->next;
    }
    holder->next = NULL;
    
    container->size--;
    return 0;
}

int32_t 
Q_peek(queue container, void **holder){
    if(container == NULL){
        return 1;
    }
    if(*holder != NULL){
        return 2;
    }
    *holder = s_anchorToHead(container, container->next);
    return 0;
}

int32_t 
Q_enqueue(queue container, void *node){
    struct Q_anchor *anchor = s_startToAnchor(container, node);
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
    return 0;
}

int32_t
Q_belongs(queue container, void *node){
    struct Q_anchor *anchor = s_startToAnchor(container, node);
    if(anchor->next != NULL){
        return 1;
    }
    return 0;
}


int64_t
Q_size(queue container){
    return container->size;
}

size_t 
Q_containerByteSize(){
    return sizeof(struct Q_container);
}



//static implementations

inline
static
Q_anchor*
s_startToAnchor(queue container, void *node){
    return (struct Q_anchor*)((int8_t*)node+container->offset);
}


inline
static
Q_anchor*
s_anchorToHead(queue container, void *node){
    return (void*)(((int8_t*)container->next)-container->offset);
}


#ifdef DEBUG 
#include <stdio.h>

int32_t 
debug_print(queue container){
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
#endif


