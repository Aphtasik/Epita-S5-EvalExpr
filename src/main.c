#include "evalexpr.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    const char * test = "3 +4";
    struct queue *t_queue = NULL;
    t_queue = evalexpr(test);
    while(t_queue)
    {
        printf("%d\n", t_queue->data.value);
        t_queue = t_queue->next;
    }
    return 0;
}
