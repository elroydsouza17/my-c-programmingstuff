#include <stdio.h>

unsigned int setBits(unsigned int reg, unsigned char position, unsigned char len);
unsigned int setBitsEasily(unsigned int reg, unsigned char position, unsigned char len);
void printIntBinary(unsigned int num);

int main()
{

    unsigned int num;
    unsigned char position;
    unsigned char lenght;

    printf("Enter the number\n");
    scanf("%u",&num);

    printf("Enter the position\n");
    scanf("%hhu",&position);

    printf("Enter the length\n");
    scanf("%hhu",&lenght);

    printIntBinary(num);
    unsigned int value = setBitsEasily(num, position, lenght);
    printIntBinary(value);
}

unsigned int setBits(unsigned int reg, unsigned char position, unsigned char len)
{
    unsigned int bitMask = 0xFFFFFFFF;
    bitMask = bitMask << len;
    bitMask = ~bitMask;
    bitMask = bitMask << position;
    reg = reg | bitMask;

    return reg;
}

unsigned int setBitsEasily(unsigned int reg, unsigned char position, unsigned char len)
{
    unsigned int bitMask = (1 << len) - 1;
    bitMask = bitMask << position;
    reg = reg | bitMask;

    return reg;
}

void printIntBinary(unsigned int num)
{
    unsigned int bitMask;
    for(int i = 31; i >= 0 ; i--)
    {
        bitMask = num >> i;
        printf("%u", bitMask & 1);
    }
    printf("\n");
}