#include <stdio.h>

unsigned char setKthBit(unsigned char num, int k);
void decimalToBinary(unsigned char number);

int main()
{
    int number;
    int position;

    printf("Enter number from 0 -255\n");
    scanf("%d", &number);

    printf("Enter positon of bit to be set\n");
    scanf("%d", &position);

    decimalToBinary(number);

    unsigned char num = setKthBit(number, position);

    printf("the number after %dth bit is set is:", position);
    decimalToBinary(num);
    
}


unsigned char setKthBit(unsigned char num, int k)
{
    unsigned char bitMask = 1 << k;

    // set kth bit to 1 and leave all other bits untouchec
    num = num | bitMask;

    return num;
}

void decimalToBinary(unsigned char number)
{
    int result;

    printf("Binary number is : ");
    for(int i = 7; i >= 0; i--)
    {
        result = (number >> i) &  0b00000001;
        printf("%d",result);
    }
    printf("\n");
}