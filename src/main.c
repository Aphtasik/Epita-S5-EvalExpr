#define _POSIX_C_SOURCE 200809L
#include <stdio.h>

#include "evalexpr.h"

int main(int argc, char *argv[])
{
    size_t len = 0;
    char *str = NULL;
    if (argc == 1)
    {
        if (getline(&str, &len, stdin) == 0)
            return 1;
        int eval = evalexpr(str, 0);
        printf("%d\n", eval);
        free(str);
    }
    else if (argc == 2 && strcmp("-rpn", argv[1]) == 0)
    {
        if (getline(&str, &len, stdin) == 0)
            return 1;
        int eval = evalexpr(str, 1);
        printf("%d\n", eval);
        free(str);
    }
    else
    {
        return 4;
    }
    return 0;
}
