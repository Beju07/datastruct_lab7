#include "DS.h"
/*
  p-ийн зааж буй Stack-т x утгыг оруулна
 */
void s_push(Stack *p, int x)
{
        Elm *new=(Elm *)malloc(sizeof(Elm));
        if (new==NULL) {
          return;
        }      
        
        new->x=x;
        new->next=p->top;
        p->top=new;
        p->len++;
}
/*
  p-ийн зааж буй Stack-аас гарах функц
 */
void s_pop(Stack *p)
{
    if (p->top == NULL) {
            return;
    }

    Elm *temp = p->top;

    p->top = p->top->next;
    free(temp);

    p->len--;
}
/*
    p-ийн зааж буй Stack-д байгаа элементүүдийг хэвлэх функц.
    Хамгийн сүүлд орсон элементээс эхлэн дарааллаар, нэг мөрөнд
    нэг л элемент хэвлэнэ.
 */
void s_print(Stack *p)
{
    Elm *temp = p->top;

    while (temp != NULL) {
        printf("%d\n", temp->x);
        temp = temp->next;
    }
}
