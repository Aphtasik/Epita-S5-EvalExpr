#include "evalexpr.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    const char * test = "3 +4*2";
    int eval = evalexpr(test);
    printf("%d\n", eval);
    return 0;
}
