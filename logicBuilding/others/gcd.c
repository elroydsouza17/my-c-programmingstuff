#include <stdio.h>

int main()
{
    int number1 = 27;
    int number2 = 9;


    int commonFactor = 0;
    for(int i = 1; i <= number1; i++)
    {
        if(number1 % i == 0 && number2 % i == 0)
        {
            commonFactor = i;
        }
    }

    printf("Largest common factor is %d",commonFactor);
}

