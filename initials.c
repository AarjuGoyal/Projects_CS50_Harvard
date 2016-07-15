#include<ctype.h>
#include<stdio.h>
#include<cs50.h>

int main(void)
{
    string name;
    name = GetString();
    for(int i=0 ; name[i]!='\0'; i++)
    {
        if(i==0 || name[i-1] ==' ')
        {
            printf("%c",toupper(name[i]));
        }
        
    }
    printf("\n");
}