#include "../src/evalexpr.h"

#include <criterion/criterion.h>

Test(simple, mod)
{
    int res = evalexpr("5 % 2");
    cr_assert_eq(1, res, "EXPECTED: %d, GOT: %d", 1, res);
}

Test(simple, add)
{
    int res = evalexpr("3 +4");
    cr_assert_eq(7, res, "EXPECTED: %d, GOT: %d", 7, res);
}

Test(simple, sub)
{
    int res = evalexpr("7 - 2");
    cr_assert_eq(5, res, "EXPECTED: %d, GOT: %d", 5, res);
}

Test(simple, mul)
{
    int res = evalexpr("3*4");
    cr_assert_eq(12, res, "EXPECTED: %d, GOT: %d", 12, res);
}

Test(two_op, add_mul)
{
    int res = evalexpr("3+4*2");
    cr_assert_eq(11, res, "EXPECTED: %d, GOT: %d", 11, res);
}

Test(two_op, mul_sub)
{
    int res = evalexpr("3*4-2");
    cr_assert_eq(10, res, "EXPECTED: %d, GOT: %d", 10, res);
}

Test(two_op, add_sub)
{
    int res = evalexpr("3+4-2");
    cr_assert_eq(6, res, "EXPECTED: %d, GOT: %d", 6, res);
}

