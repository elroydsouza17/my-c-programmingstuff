#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ENABLE 1u
#define MODE 6u
#define SPEED 56u

uint16_t setRegisterMacros(uint8_t enable, uint8_t mode, uint8_t speed);
void printIntBinary(uint16_t num);


int main()
{
    uint8_t speed;
    uint8_t enable;
    uint8_t mode;

    printf("Enter enable bit value\n");
    scanf("%hhu",&enable);
    printf("Enter mode bits value\n");
    scanf("%hhu",&mode);
    printf("Enter speed bits value\n");
    scanf("%hhu",&speed);

    uint16_t value = setRegisterMacros(enable, mode, speed);
    printIntBinary(value);
    printf("FINAL VALUE IS : %hhu\n",value);
    return 0;
}

uint16_t setRegisterMacros(uint8_t enable, uint8_t mode, uint8_t speed)
{
    uint16_t registerVal = 0;
    registerVal = ENABLE & enable;
    registerVal = registerVal + (MODE & (mode << 1));
    registerVal = registerVal + (SPEED & (speed << 3));

    return registerVal;
}

void printIntBinary(uint16_t num)
{
    unsigned int bitMask;
    for(int i = 15; i >= 0 ; i--)
    {
        bitMask = num >> i;
        printf("%u", bitMask & 1);
    }
    printf("\n");
}