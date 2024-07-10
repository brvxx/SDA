#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

#include <string.h>
#include <stdlib.h>

/*****************************************************************************/
/*                           Item & Primitives                               */
/*****************************************************************************/

ItemQ *QueueCreateEmpty(void) {
    return NULL;
}

ItemQ *QueueInsertHead(const ElemTypeQ *e, ItemQ *i) {
    ItemQ *n = malloc(sizeof(ItemQ));
    n->value = *e;
    n->next = i;
    return n;
}

bool QueueIsEmpty(const ItemQ *i) {
    return i == NULL;
}

const ElemTypeQ *QueueTop(const ItemQ *i) {
    if (QueueIsEmpty(i)) {
        printf("ERROR: Alla funzione 'ListGetHead()' e' stata passata una lista vuota (NULL).\n");
        exit(1);
    }
    return &i->value;
}

ItemQ *Dequeue(const ItemQ *i) {
    if (QueueIsEmpty(i)) {
        printf("ERROR: Alla funzione 'ListGetTail()' e' stata passata una lista vuota (NULL).\n");
        exit(2);
    }
	return i->next;
}

ItemQ *Enqueue(const ElemTypeQ *e, ItemQ *i) {

    ItemQ *n = QueueInsertHead(e, QueueCreateEmpty());

    if (QueueIsEmpty(i)) {
        return n;
    }

    ItemQ *tmp = i;
    while (!QueueIsEmpty(Dequeue(tmp))) {
        tmp = Dequeue(tmp);
    }

    tmp->next = n;
    return i;
}

void QueueDelete(ItemQ *i) {
    while (!QueueIsEmpty(i)) {
        ItemQ *tmp = i;
        i = i->next;
        ElemDelete(&tmp->value);
        free(tmp);
    }
}

/*****************************************************************************/
/*                            Non Primitives                                 */
/*****************************************************************************/

void QueueWrite(const ItemQ *i, FILE *f) {
    fprintf(f, "[");
    while (!QueueIsEmpty(i)) {
        ElemWrite(&(*QueueTop(i))->value, f);
        i = Dequeue(i);
        if (!QueueIsEmpty(i)) {
            fprintf(f, ", ");
        }
    }
    fprintf(f, "]\n");
}

void QueueWriteStdout(const ItemQ *i) {
    QueueWrite(i, stdout);
}
