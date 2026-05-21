#include <stdio.h>

int getNumOfDigits(int);
int getArmstrong(int, int);
int power(int, int);


int main()
{
    int number;
    printf("Enter number\n");
    scanf("%d", &number);

    int numDigits = getNumOfDigits(number);
    int checkNum = getArmstrong(number, numDigits);

    if(checkNum == number)
    {
        printf("Number %d is an amstrong number\n",number);
    } 
    else
    {
        printf("Number %d is not an amstrong number\n",number);
    }

}

int getNumOfDigits(int num)
{   
    int digits = 0;
    while(num != 0)
    {
        num = num / 10;
        digits++;
    }
    return digits;
}

int getArmstrong(int n, int numDigits)
{
    int armstrong = 0;
    while(n != 0)
    {
        armstrong += power((n % 10), numDigits);
        printf("power is %d\n",power((n % 10), numDigits));
        n = n / 10; 
    }
    return armstrong;
}

int power(int base, int exp)
{
    int num = 1;
    for(int i = 0; i < exp; i++)
    {
        num *= base; 
    }
    return num;
}