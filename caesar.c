#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char* argv[])

{
    if(argc!=2)
    {
        printf("you need to give a single number");
        return 1;
    }
    int k, i;
    k = atoi(argv[1]);
    string phrase;
    phrase = GetString();
    k = k % 26;
    
    for(i = 0; i<strlen(phrase); i++)
    {
        if(isalpha(phrase[i]))
        {
            
            if(isupper(phrase[i]))
            {
                if(phrase[i] + k > 90)
                    phrase[i] = k + phrase[i] -26;
                else
                    phrase[i] = k + phrase[i];
            }
            else
            {
                if(phrase[i] + k > 122)
                    phrase[i] = k + phrase[i] -26;
                else
                    phrase[i] = k + phrase[i];    
            }
        }
        printf("%c", phrase[i]);
        
    }
    printf("\n");
    
}
