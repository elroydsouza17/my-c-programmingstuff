#include <stdio.h>
#include <stdint.h>

uint32_t extractBits(uint32_t reg, uint8_t position, uint8_t length);
void printIntBinary(uint32_t num);

int main()
{
    uint32_t reg;
    uint32_t position;
    uint32_t length;

    printf("Enter 32 bit register value ");
    scanf("%u",&reg);

    printf("Enter position value ");
    scanf("%u",&position);

    printf("Enter length value ");
    scanf("%u",&length);

    printIntBinary(reg);
    uint32_t val = extractBits(reg, position, length);
    printIntBinary(val);
    printf("iNTEGER VALUE IS: %u\n",val);
    return 0;
}

uint32_t extractBits(uint32_t reg, uint8_t position, uint8_t length)
{
    uint32_t bitMask = ((1 << length) - 1);
    reg = reg >> position;
    reg = reg & bitMask;

    return reg;
}

void printIntBinary(uint32_t num)
{
    unsigned int bitMask;
    for(int i = 31; i >= 0 ; i--)
    {
        bitMask = num >> i;
        printf("%u", bitMask & 1);
        if(i % 8 == 0) printf(" ");

    }
    printf("\n");
}
