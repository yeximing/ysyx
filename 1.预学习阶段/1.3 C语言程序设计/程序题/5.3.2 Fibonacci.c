#include <stdio.h>

int fib(int f)
{
    if (f == 0 | f == 1)
        return 1;
    else
        return (fib(f - 1) + fib(f - 2));
}

int main(int argc, char *argv[])
{
    int n;
    printf("Please input a number to calculate its fibonacci.\n");
    scanf("%d", &n);

    printf("%d's fibonacci is: %d\n", n, fib(n));
    return 0;
}
