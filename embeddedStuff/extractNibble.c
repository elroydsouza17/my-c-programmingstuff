#include <stdio.h>
#include <stdint.h>

uint8_t getNibble(uint8_t reg, uint8_t position);
void printIntBinary(uint8_t num);

int main()
{
    uint8_t reg;
    uint8_t position;

    printf("Enter register value\n");
    scanf("%x",&reg);

    printf("Enter position value\n");
    scanf("%hhu",&position);

    printIntBinary(reg);
    

    uint8_t nibble = getNibble(reg, position);
    printIntBinary(nibble);
    printf("value of nibble is %hhu\n",nibble);
    return 0;
}

uint8_t getNibble(uint8_t reg, uint8_t position)
{
    uint8_t nib = 0;
    if (position == 0u)
    {
        nib = (reg) & (uint8_t)15u;
    }
    else
    {
        nib = (reg >> 4) & (uint8_t)15u;

    }
    return nib;
}

void printIntBinary(uint8_t num)
{
    unsigned int bitMask;
    for(int i = 7; i >= 0 ; i--)
    {
        bitMask = num >> i;
        printf("%u", bitMask & 1);
    }
    printf("\n");
}