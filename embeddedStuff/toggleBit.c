#include <stdio.h>

int toggleBit(int);
void decimalToBinary(unsigned char);


int main()
{
    int num;

    printf("Enter the integer\n");
    scanf("%d",&num);
    decimalToBinary(num);
    int data = toggleBit(num);
    decimalToBinary(data);

}

int toggleBit(int n)
{
    n = n ^ (1 << 5);
    return n;
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