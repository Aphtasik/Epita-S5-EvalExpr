#include "evalexpr.h"

#include <stdio.h>
#include <string.h>

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
    }
    else if (argc == 2 && strcmp("-rpn", argv[1]) == 0)
    {
        if (getline(&str, &len, stdin) == 0)
            return 1;
        int eval = evalexpr(str, 1);
        printf("%d\n", eval);
    }
    else
    {
        return 4;
    }
    return 0;
}
