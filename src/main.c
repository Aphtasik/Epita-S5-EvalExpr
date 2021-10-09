#include "evalexpr.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    /** char *line = NULL; */
    /** size_t len = 0; */
    /** if (argc == 1) */
    /** { */
    /**     if (getline(&line, &len, stdin) == 0) */
    /**     { */
    /**         exit(1); */
    /**     } */
    /**     int eval = evalexpr(line); */
    /**     printf("%s\n%d\n", line, eval); */
    /** } */
    /** return 0; */
    
    size_t len = 0;
    char *s = NULL;
    if (argc == 1)
    {
        if (getline(&s, &len, stdin) == 0)
            return 1;
        int s_juste = evalexpr(s);
        printf("%i\n", s_juste);
    }
    else
    {
        return 4;
    }
    return 0;
}
