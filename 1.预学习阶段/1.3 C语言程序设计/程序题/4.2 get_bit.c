#include <stdio.h>

int getUnitDigit(int x)
{
    return x % 10;
}

int getTensDigit(int x)
{
    return (x / 10) % 10;
}

void getUnitAndTensDigit(int x)
{
    printf("Unit digit of %d is %d\n", x, getUnitDigit(x));
    printf("Tens digit of %d is %d\n", x, getTensDigit(x));
}


int main(void)
{
    int x = 1234;
    getUnitAndTensDigit(x);
    return 0;
}