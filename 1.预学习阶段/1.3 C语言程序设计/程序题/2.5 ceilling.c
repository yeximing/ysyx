#include <stdio.h>

int ceiling(int x, int n)
{
    return (x + n - 1) / n;
}

int main(void)
{
    int x1 = 17, x2 = 16;
    int n = 4;   

    printf("ceiling(%d/%d) = %d\n", x1, n, ceiling(x1, n));
    printf("ceiling(%d/%d) = %d\n", x2, n, ceiling(x2, n));

    return 0;
                 
}                
                 
                 
                 