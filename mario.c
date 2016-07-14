#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int h, i, j;
    do
    {
            printf("height: ");
            h = GetInt();
    }while(h<1 || h>23);
    for(i=1; i<=h; i++)
    {
            for(j=i; j<h; j++)
            {
                printf(" ");
            }
            for(j=0; j<=i; j++)
            {
                printf("#");
            }
            printf("\n");
    }
}