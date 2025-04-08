#include <stdio.h>

int getUnitDigit(int x)
{
    return x % 10;
}

int getTensDigit(int x)
{
    return (x / 10) % 10;
}

int count9(int x)
{
    int n = 1;
    int count = 0;
    while (n <= x)
    {
        if (getTensDigit(n) == 9 || getUnitDigit(n) == 9)
             count ++;
        
        n++;
    }
    return count;
}


int main(void)
{
    int x;
    scanf("%d", &x);
    printf("%d has %d 9\n", x, count9(x));
    return 0;
}
