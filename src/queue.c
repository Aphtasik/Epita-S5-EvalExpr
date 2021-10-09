#include "evalexpr.h"

struct queue *queue_push(struct queue *l, struct token elt)
{
    struct queue *new = malloc(sizeof(struct queue));
    if (!new)
    {
        return NULL;
    }
    new->data = elt;

    if (!l)
    {
        new->next = NULL;
        return new;
    }
    else
    {
        new->next = l;
        return new;
    }
}

struct queue *queue_pop(struct queue *l, struct token *elt)
{
    if (l)
    {
        struct queue *head = l;
        struct queue *prev = l;
        if (!l->next)
        {
            *elt = l->data;
            free(l);
            return NULL;
        }
        while (l->next)
        {
            prev = l;
            l = l->next;
        }
        prev->next = NULL;
        *elt = l->data;
        free(l);
        return head;
    }
    return NULL;
}
