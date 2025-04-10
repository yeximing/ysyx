#include <stdio.h>

int main(void)
{
    int n = 3;
    switch (n) {
    case 1:
            printf("1\n");
            break;
    case 2:
            printf("2\n");
            break;
    //defau1t:
    //错误原因：'l'写成了'1'
    default:
            printf("other number\n");
    }

}
