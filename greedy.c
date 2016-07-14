#include<stdio.h>
#include<cs50.h>
#include<math.h>

//int remainder(int , int)

/*int remainder(int num, int divident)
{
    int rem;
    rem = num - (num/divident)*divident;
    return rem;
}*/
int main(void)
{
    float change;
    int  numberOfCoins=0;
    
    printf("O hai, ");
    do
    {
        printf("how much change is owed?\n");
        change = GetFloat();
    }while(change<0);
    change = change*100;
    //printf("%f\n", change);
    
    change = round(change);
    //printf("%f\n", change);
    int changeUseForCalc;
    changeUseForCalc = (int) change; 
   
   
    numberOfCoins = numberOfCoins + changeUseForCalc/25;
    changeUseForCalc = changeUseForCalc%25;
    numberOfCoins = numberOfCoins + changeUseForCalc/10;
    changeUseForCalc = changeUseForCalc%10;
    numberOfCoins = numberOfCoins + changeUseForCalc/5;
    changeUseForCalc = changeUseForCalc%5;
    numberOfCoins = numberOfCoins + changeUseForCalc;
    printf("%d\n", numberOfCoins);
    
}