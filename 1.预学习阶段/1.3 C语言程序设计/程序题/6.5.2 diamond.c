#include <stdio.h>
#include <stdlib.h>

int diamond(int n, char c)
{
    if (n%2 == 1) 
    {
        int i ,j;
        for (i = 1; i <= (n+1)/2; i++)
        {
             for (j = 1; j <= (n+1)/2 - i; j++)
                printf(" \t");
             for (j = 1; j <= 2*i-1; j++)
                printf("%c\t", c);
             printf("\n");
        }    
        for (i =  (n+1)/2 + 1; i <= n; i++)
        {
             for (j = 1; j <= i - (n+1)/2; j++)
                printf(" \t");
             for (j = 1; j <= 2*(n-i)+1; j++)
                printf("%c\t", c);
             printf("\n");
        }    

        return 0;
    }
    else {
    return 1;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
    printf("Usage: %s <odd_number> <character>\n", argv[0]);
    return 1;
    }
    int n = atoi(argv[1]); // 将字符串转换为整数
    char c = argv[2][0];   // 获取第二个参数的第一个字符
    if (diamond(n, c) == 1) {
        printf("Error: Input must be an odd number.\n");
    }
    return 0;
}
