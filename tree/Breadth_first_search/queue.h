/** @file
Questo file contiene la definizione del tipo `Item` e la documentazione delle
funzioni primitive (e non) relative alle liste. Si noti che il comportamento di
queste funzioni Ã¨ indipendente dalla definizione di `ElemType`.
*/

#ifndef QUEUE_H_
#define QUEUE_H_

#include "tree.h"

#include <stdbool.h>
#include <stdio.h>


typedef Node *ElemTypeQ;


/*****************************************************************************/
/*                           Item & Primitives                               */
/*****************************************************************************/

/** @brief Definizione del tipo `struct ItemQ`. */
struct ItemQ {
    ElemTypeQ value; /*!< Valore associato all'`ItemQ`. */
    struct ItemQ *next; /*!< Puntatore all'`ItemQ` successivo. */
};
/** @brief Definizione di un nome alternativo per `struct ItemQ`. */
typedef struct ItemQ ItemQ;

/** @brief La funzione `QueueCreateEmpty()` crea e ritorna una coda vuota, ovvero
           `NULL`.

@return Queue vuota (`NULL`).
*/
ItemQ *QueueCreateEmpty(void);

/** @brief La funzione `QueueInsertHead()` aggiunge un nuovo elemento in testa ad
           una coda e ritorna il puntatore alla nuova coda.

@param[in] e Puntatore all'elemento da aggiugnere in testa alla coda.
@param[in] i Lista a cui aggiungere il nuovo elemento. `i` puÃ² essere una coda
            vuota (NULL).

@return coda risultante.
*/
ItemQ *QueueInsertHead(const ElemTypeQ *e, ItemQ *i);

/** @brief La funzione `QueueIsEmpty(`) verifica se una coda è vuota.

@param[in] i Coda su cui eseguire la verifica.

@return `true` se la Coda è vuota, `false` altrimenti.
*/
bool QueueIsEmpty(const ItemQ *i);

/** @brief La funzione `QueueTop()` un puntatore all'elemento in testa
            alla coda, senza rimuoverlo. Cioè indica il prossimo elemento in coda.

@param[in] i Coda da cui estrarre il valore in testa. Questa coda non puÃ²
         essere vuota, nel caso in cui lo sia la funzione termina il programma
         con codice di errore `1`.

@returns Puntatore all'elemento (costante) in testa alla lista.
*/
const ElemTypeQ *QueueTop(const ItemQ *i);

/** @brief La funzione `Dequeue()` ritorna la coda privata dell'elemento in
           testa, osia toglie l'elemento servito. La funzione NON dealloca la memoria occupata dalla testa
           della lista.

@param[in] i Coda da cui ottenere la coda. La coda non puÃ² essere vuota,
         nel caso in cui lo sia la funzione termina il programma con codice di
         errore `2`.

@return Lista ottenuta dopo l'eliminazione della testa. Il valore di ritorno
        potrebbe essere una lista vuota (`NULL`).
*/
ItemQ *Dequeue(const ItemQ *i);


/** @brief La funzione `Enqueue()` aggiunge un elemento in coda ad una
            lista (anche vuota) e ritorna la coda risultante.

@param[in] i coda a cui aggiungere l'elemento specifciato. Questa coda può
            essere vuota (`NULL`).
@param[in] e Puntatore all'elemento da aggiugnere in testa alla coda. Il valore
         contenuto in e non viene modificato.

@return  coda ottenuta dopo l'aggiunta dell'elemento.
*/
ItemQ *Enqueue(const ElemTypeQ *e, ItemQ *i);

/** @brief La funzione `QueueDelete()` libera la memoria occupata dagli elementi di
           una coda.

@param[in] i coda di cui liberare la memoria, può essere vuota (`NULL`).

@return Non ci sono valori di ritorno.
*/
void QueueDelete(ItemQ *i);

/*****************************************************************************/
/*                             Non Primitives                                */
/*****************************************************************************/

/** @brief La funzione `QueueWrite()` stampa la coda specificata su file.
           Nello specifico, la funzione stampa il carattere "[" seguito dagli
           elementi della lista, separati dai caratter ", ", e dal carattere "]".
           La stampa degli elementi dipende dalla definizione di `ElemTypeQ`.

@param[in] i Lista da stampare su file: può essere vuota e non viene modificata.
@param[in] f `FILE *` su cui stampare la lista.

@return Non ci sono valori di ritorno.
*/
void QueueWrite(const ItemQ *i, FILE *f);

/** @brief La funzione `QueueWriteStdout()` stampa la lista specificata su `stdout`.
           Nello specifico, la funzione stampa il carattere "[" seguito dagli
           elementi della lista, separati dai caratter ", ", e dal carattere "]".
           La stampa degli elementi dipende dalla definizione di `ElemType`.

@param[in] i coda da stampare su `stdout`: può essere vuota e non viene modificata.

@return Non ci sono valori di ritorno.
*/
void QueueWriteStdout(const ItemQ *i);

#endif // QUEUE_H_
