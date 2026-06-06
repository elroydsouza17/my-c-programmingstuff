#include <stdio.h>
#include <stdint.h>

uint8_t setBits(uint8_t reg, uint8_t positions[], int size);
uint8_t clearBits(uint8_t reg, uint8_t positions[], int size);
uint8_t toggleBits(uint8_t reg, uint8_t positions[], int size);
void printIntBinary(uint8_t num);

int main()
{
    uint8_t number;
    int num_of_bits_set;
    int num_of_bits_clear;
    int num_of_bits_toggle;

    printf("Enter a number between 0-255\n");
    scanf("%hhu", &number);

    printIntBinary(number);

    printf("Enter number of bits to be set\n");
    scanf("%d", &num_of_bits_set);
    uint8_t setBitPositons [num_of_bits_set];

    for(int i = 0; i < num_of_bits_set; i++)
    {
        printf("Enter positon of %dth to be set\n", i);
        scanf("%hhu", &setBitPositons[i]);
    }

    for(int i = 0; i < num_of_bits_set; i++)
    {
        printf("value of %dth value : %hhu\n", i, setBitPositons[i]);
    }

    uint8_t num_after_set = setBits(number, setBitPositons, num_of_bits_set);

    printIntBinary(num_after_set);

    printf("Enter number of bits to be cleared\n");
    scanf("%d", &num_of_bits_clear);
    uint8_t clearBitPositons [num_of_bits_clear];

    for(int i = 0; i < num_of_bits_clear; i++)
    {
        printf("Enter positon of %dth to be cleared\n", i);
        scanf("%hhu", &clearBitPositons[i]);
    }

    for(int i = 0; i < num_of_bits_clear; i++)
    {
        printf("value of %dth bit value : %hhu\n", i, clearBitPositons[i]);
    }

    uint8_t num_after_clear = clearBits(num_after_set, clearBitPositons, num_of_bits_clear);

    printIntBinary(num_after_clear);
    
    printf("Enter number of bits to be toggled\n");
    scanf("%d", &num_of_bits_toggle);
    uint8_t toggleBitPositons [num_of_bits_toggle];

    for(int i = 0; i < num_of_bits_toggle; i++)
    {
        printf("Enter positon of %dth to be toggled\n", i);
        scanf("%hhu", &toggleBitPositons[i]);
    }

    for(int i = 0; i < num_of_bits_toggle; i++)
    {
        printf("value of %dth bit value : %hhu\n", i, toggleBitPositons[i]);
    }

    uint8_t num_after_toggle = toggleBits(num_after_clear, toggleBitPositons, num_of_bits_toggle);

    printIntBinary(num_after_toggle);

    return 0;
}

uint8_t setBits(uint8_t reg, uint8_t positions[], int size)
{
    uint8_t bitMask = 0;
    for(int i = 0; i < size; i++)
    {
        bitMask |= (uint8_t)(1u << positions[i]);
    }

    reg |= bitMask;
    return reg;
}

uint8_t clearBits(uint8_t reg, uint8_t positions[], int size)
{
    uint8_t bitMask = 0;
    for(int i = 0; i < size; i++)
    {
        bitMask |= (uint8_t)(1u << positions[i]);
    }

    reg &= ~bitMask;
    return reg;
}

uint8_t toggleBits(uint8_t reg, uint8_t positions[], int size)
{
    uint8_t bitMask = 0;
    for(int i = 0; i < size; i++)
    {
        bitMask |= (uint8_t)(1u << positions[i]);
    }

    reg ^= bitMask;
    return reg;
}

void printIntBinary(uint8_t num)
{
    for(int i = 7; i >= 0 ; i--)
    {
        printf("%u", (num >> i) & 1);
    }

    printf("\n");
}