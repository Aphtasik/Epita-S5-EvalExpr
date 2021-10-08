#ifndef EVALEXPR_H
#define EVALEXPR_H

#include <stdlib.h>
#include <stddef.h>

enum oper
{
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    EXP
};

struct token
{
    int is_operator;
    int value;
};

int my_add(int a, int b);
int my_sub(int a, int b);
int my_mul(int a, int b);
int my_div(int a, int b);
int my_mod(int a, int b);
int my_pow(int a, int b);

struct stack
{
    struct token data;
    struct stack *next;
};

struct stack *stack_push(struct stack *s, struct token elt);
struct stack *stack_pop(struct stack *s);

struct queue
{
    struct token data;
    struct queue *next;
};

struct queue *queue_push(struct queue *l, struct token elt);
struct queue *queue_pop(struct queue *l, struct token *elt);

struct queue *evalexpr(const char* operations);

#endif
