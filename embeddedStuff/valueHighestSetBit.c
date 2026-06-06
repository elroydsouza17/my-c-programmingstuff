#include <stdio.h>
#include <stdint.h>

int findHighestBitValue(uint16_t number);

int main()
{
    int number;

    printf("Enter a 16 bit number\n");
    scanf("%d",&number);

    int highestNum = findHighestBitValue(number);
    printf("Value is : %d\n", highestNum);
}

int findHighestBitValue(uint16_t number)
{
    for(char i = 15; i >= 0; i--)
    {
        if((number >> i) & 1)
        {
            return 1u << i;
        }
    }

    return 0;
}
