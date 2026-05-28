#include <stdio.h>
#include <math.h>

unsigned char modifyBit(unsigned char, int, int);
void decimalToBinary(unsigned char);

int main()
{
    int number = 0;
    int position;
    int value;
    printf("Enter a value between 0 - 255\n");
    scanf("%u", &number);
    decimalToBinary(number);

    printf("Enter the position of bit to be modified(0 - 7)\n");
    scanf("%u", &position);

    printf("Enter value of the bit to be set\n");
    scanf("%u", &value);

    unsigned char data = modifyBit(number, position, value);
    printf("Value after operations: %u\n",data);
    decimalToBinary(data);
}

unsigned char modifyBit(unsigned char data, int position, int value)
{
    unsigned char mask = 1;
    if(value == 1)
    {               
        mask = mask << position;
        // set bit
        data = data | mask;
    }
    else
    {
        mask = pow(2, position);
        mask = ~mask;
        //unset bit 
        data = data & mask; 
    } 

    return data;
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

