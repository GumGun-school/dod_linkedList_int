#ifndef libreria_queue
#define libreria_queue

#include <stdint.h>
#include <stddef.h>

typedef struct Q_anchor{
    struct Q_anchor *next;
} Q_anchor;

typedef struct Q_container *queue;


//int32_t Q_create(struct Q_container **container);
int32_t Q_create(queue container, ptrdiff_t offset);

int32_t Q_pop(queue container);
int32_t Q_peek(queue container, void **holder);
int32_t Q_enqueue(queue container, void *node);
int64_t Q_size(queue container);
int32_t Q_belongs(queue container, void *node);

size_t Q_containerByteSize();

int32_t Q_destroy(queue *container);

int32_t debug_print(queue container);

#endif

//no hace nada
//enqueue no tenia el return 0
