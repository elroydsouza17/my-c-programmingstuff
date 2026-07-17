#include <stdio.h>
#include <stdint.h>

int countSetBits(uint32_t reg);

int main()
{
    uint32_t num;
    printf("Enter number\n");
    scanf("%u",&num);

    int num_bits_set = countSetBits(num);
    printf("%d\n", num_bits_set);

    return 0;
}

int countSetBits(uint32_t reg)
{
    uint32_t bitMask = 1;
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((reg >> i) & bitMask == 1) count++; 
    }

    return count;
}