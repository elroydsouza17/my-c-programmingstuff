#include <stdio.h>
#include <stdint.h>

uint8_t setBitField(uint8_t reg, uint8_t start, uint8_t end);
void printIntBinary(uint8_t num);

int main()
{   
    uint8_t reg = 0b01110000;
    unsigned int start;
    unsigned int end;

    printf("Enter start value of bits to set\n");
    scanf("%d",&start);

    printf("Enter end value of bits to set\n");
    scanf("%d",&end);

    uint8_t newReg = setBitField(reg, start, end);
    printIntBinary(reg);
    printIntBinary(newReg);
    return 0;
}

uint8_t setBitField(uint8_t reg, uint8_t start, uint8_t end)
{
    uint8_t bitMask = ((1u << (end - start + 1)) - 1u) << start;
    bitMask = bitMask | reg;
    return bitMask;

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

