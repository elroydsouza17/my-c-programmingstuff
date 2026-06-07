/******************************************************* 
Bit	Meaning
0	Power On
1	Error
2	Tx Ready
3	Rx Ready
4	Overheat
5	Undervoltage
6	Timeout
7	Reserved
*******************************************************/

#include <stdio.h>
#include <stdint.h>

void decodeRegisterValue(uint8_t reg);
void printIntBinary(uint8_t num);

int main()
{   
    uint8_t reg = 0;

    printf("Enter an 8 bit number\n");
    scanf("%hhu", &reg);

    printIntBinary(reg);

    decodeRegisterValue(reg);

    return 0;
}

void decodeRegisterValue(uint8_t reg)
{   
    for (int i = 0; i < 8; i++)
    {
        if ((reg >> i) & 1)
        {
    //      switch((1u << i) & reg)  already checked the position is set, so (1u << i) & reg will be always equal to 1u << i
    //      switch((1u << i)) use i as switch condition it's cleaner and we know for that i, 1u << i is set so. use numbers 0, 1, 2 etc as the case number.
            switch (i)
            {
                case 0:
                    printf("Power On\n");
                    break;

                case 1:
                    printf("Error\n");
                    break;

                case 2:
                    printf("Tx ready\n");
                    break;

                case 3:
                    printf("Rx ready\n");
                    break;

                case 4:
                    printf("Overheat\n");
                    break;

                case 5:
                    printf("Undervoltage\n");
                    break;

                case 6:
                    printf("Timeout\n");
                    break;

                case 7:
                    printf("Reserved\n");
                    break;

                default:
                    printf("Invalid register value\n");
                    break;
            }
        }
    }
}

void printIntBinary(uint8_t num)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%u", (num >> i) & 1);
    }

    printf("\n");
}