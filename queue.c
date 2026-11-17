#include "DS.h"

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void q_push(Queue *p, int x)
{
    Elm *newNode = (Elm *)malloc(sizeof(Elm));

    if (newNode == NULL) {
        return;
    }

    newNode->x = x;
    newNode->next = NULL;

    if (p->head == NULL) {
        p->head = newNode;
        p->tail = newNode;
    }
    else {
        p->tail->next = newNode;
        p->tail = newNode;
    }

    p->len++;
}
/* p-ийн зааж буй Queue-с гаргана */
void q_pop(Queue *p)
{
    if (p->head == NULL) {
        return;
    }

    Elm *temp = p->head;
    p->head = p->head->next;

    free(temp);
    p->len--;

    if (p->head == NULL) {
        p->tail = NULL;
    }
}

/*
  p-ийн зааж буй Queue-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void q_print(Queue *p)
{
    Elm *temp = p->head;

    while (temp != NULL) {
        printf("%d\n", temp->x);
        temp = temp->next;
    }
}
