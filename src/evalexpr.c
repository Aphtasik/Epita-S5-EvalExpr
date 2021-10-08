#include "evalexpr.h"

#include <stdio.h>

typedef int (* const operation)(const int, int);

static const int pritority[] =
{
    [ADD] = 0,
    [SUB] = 0,
    [MUL] = 1,
    [DIV] = 1,
    [MOD] = 1,
    [EXP] = 1
};

static const operation operations[] =
{
    [ADD] = my_add,
    [SUB] = my_sub,
    [MUL] = my_mul,
    [DIV] = my_div,
    [MOD] = my_mod,
    [EXP] = my_pow
};

static int my_atoi(char *str)
{
    if (!str)
    {
        return 0;
    }

    int i = 0;
    int isNeg = 0;
    while (str[i] == ' ')
    {
        i++;
    }

    if (str[i] < '0' || str[i] > '9')
    {
        if (str[i] == '-')
        {
            isNeg = 1;
        }
        else if (str[i] != '+')
        {
            return 0;
        }
        i++;
    }

    int res = 0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        res = res * 10 + (str[i] - '0');
        i++;
    }

    return isNeg ? (-res) : res;
}

static int what_char(char c)
{
    if (c <= '9' && c >= '0')
    {
        return 0;
    }
    else
    {
        if (c ==  '+' || c == '-' || c == '/' || c == '*' || c == '%')
        {
            return 1;
        }
        if (c == '(' || c == ')' || c == '%' || c == '^')
        {
            return 1;
        }
        if (c == ' ')
        {
            return 2;
        }
        exit(1);
    }
}

//TODO: handle unary / multiple operator
static struct queue *create_tokens(const char* operations)
{
    int i = 0;
    char *curr_token = malloc(sizeof(char) * 126);
    int curr_i = 0;
    int w_char;
    struct queue *t_queue = NULL;
    struct token t_char;

    while (operations[i])
    {
        w_char = what_char(operations[i]);
        if (w_char == 0)
        {
            while (operations[i] && what_char(operations[i]) == 0)
            {
                curr_token[curr_i] = operations[i];
                curr_i++;
                i++;
            }
            curr_token[curr_i] = '\0';
            t_char.value = my_atoi(curr_token);
            t_char.is_operator = 0;
            t_queue = queue_push(t_queue, t_char);
            curr_i = 0;
        }
        else if (w_char == 1)
        {
            t_char.value = operations[i];
            t_char.is_operator = 1;
            t_queue = queue_push(t_queue, t_char);
            i++;
        }
        else
        {
            i++;
        }
    }
    free(curr_token);
    return t_queue;
}

//TODO: add parenthesis handle / priority in stack
struct queue *to_rpn(struct queue *q_tokens)
{
    while(q_tokens)
    {
        printf("%d\n", q_tokens->data.value);
        q_tokens = q_tokens->next;
    }
    struct stack *operators = NULL;
    struct queue *rpn = NULL;
    struct token t;
    q_tokens = queue_pop(q_tokens, &t);

    while (q_tokens)
    {
        if (!t.is_operator)
        {
            rpn = queue_push(rpn, t);
        }
        else
        {
            operators = stack_push(operators, t);
        }
        q_tokens = queue_pop(q_tokens, &t);
    }
    return rpn;
}

struct queue *evalexpr(const char* operations)
{
    struct queue* toks = create_tokens(operations);
    struct queue *rpn = to_rpn(toks);
    return rpn;
}
