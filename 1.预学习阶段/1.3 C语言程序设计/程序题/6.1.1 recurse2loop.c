#include <stdio.h>
#include <stdlib.h>

int getGCD(int x, int y)
{
    int a = abs(x);
    int b = abs(y);
    while ( a%b != 0 )
    {
        int temp;
        temp = a%b;
        a = b;
        b = temp;
    }
    return b;
}

int fib(int f)
{
    if (f == 1)
        return 1;
    if (f == 0)
        return 1;
    int minorOne = 1, minorTwo = 1;
    int n = 2;
    int temp = 0;
    while(n <= f)
    {
        temp = minorOne + minorTwo;
        minorTwo = minorOne;
        minorOne = temp;
        n++;
    }
    return minorOne;
    
}

int main(void)
{
    int a,b,f;
    printf("Please input a,b,f\n");
    scanf("%d %d %d", &a, &b, &f);

    printf("GCD of %d and %d is: %d\n", a, b, getGCD(a, b ));
    printf("Fibonacci of %d is: %d\n", f, fib(f));

    return 0;

}
