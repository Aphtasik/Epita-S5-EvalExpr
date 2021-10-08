#include "../src/evalexpr.h"

#include <criterion/criterion.h>

Test(create_token, simple)
{
    
    cr_assert_eq("", res, "EXPECTED: 0, GOT: %d", res);
}
