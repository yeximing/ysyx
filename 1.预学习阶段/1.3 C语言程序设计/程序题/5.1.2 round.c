#include <stdio.h>
#include <math.h>

double myRound(double x)
{
    int integerPart = (int)x;
    double decimalPart = x - integerPart;
    if (x >=0)
    {
        if (decimalPart >= 0.5)
        {
            integerPart++;
            return (double)integerPart;
        }
        else
        {
            return (double)integerPart;
        }
    }
    else
    {
        if (decimalPart <= -0.5)
        {
            integerPart--;
            return (double)integerPart;
        }
        else
        {
            return (double)integerPart;
        }
    }
}

int main(void)
{
    double x1 = -3.51, x2 = 4.49 ;
    printf("myRound(%f) = %f\n", x1, myRound(x1));
    printf("myRound(%f) = %f\n", x2, myRound(x2));
    return 0;
}