#include <stdio.h>
#include <stdlib.h>

int getGCD(int x, int y)
{
    int a = abs(x);
    int b = abs(y);
    if (a%b == 0)
    {
        return b;
    }
    else 
    {
        return getGCD(b, a%b);
    }
}


int main(void)
{
    int a,b;

    printf("Please input two numbers: \n");
    scanf( "%d%d",&a, &b);

    printf("GCD of %d and %d is: %d.\n", a, b, getGCD(a, b));

    return 0;
}
