#GOAL
Evalexpr is a program that reads on the standard input an arithmetic expression and writes the result
of that expression on the standard output. The input will be of arbitrary size and can be given in
reverse polish notation (RPN) or standard (infix) notation.

#OPTIONS
-rpn : RPN input

#ERRORS
- 0: No expression
- 1: Lexical Error
- 2: Syntax Error
- 3: Arithmetical Error (div by 0/ mod 0)
- 4: Other (bad arg)

#EXEMPLES
42sh$ echo "1 1 +" | ./evalexpr -rpn
2
42sh$ echo $?
0
42sh$ echo "5 2 2 ^ 3 + *" | ./evalexpr -rpn | cat -e
35$

42sh$ echo "1+1" | ./evalexpr
2
42sh$ echo $?
0
42sh$ echo "5*(2^2+3)" | ./evalexpr | cat -e
35$
