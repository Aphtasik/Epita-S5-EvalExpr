#include "evalexpr.h"

struct stack *stack_push(struct stack *s, struct token elt)
{
    struct stack *new = malloc(sizeof(struct stack));
    if (!new)
    {
        return s;
    }
    new->data = elt;
    new->next = s;

    return new;
}

struct stack *stack_pop(struct stack *s)
{
    if (!s)
    {
        return NULL;
    }
    struct stack *next = s->next;
    free(s);
    return next;
}
