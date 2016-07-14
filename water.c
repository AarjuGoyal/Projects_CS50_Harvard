#include<stdio.h>

int main(void)
{
        int m;
        printf("minutes: ");
        scanf("%d", &m);
        printf("bottles: %d", m*192/16);
}