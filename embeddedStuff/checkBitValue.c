#include <stdio.h>

int checkBitSet(int, int);
void decimalToBinary(unsigned char);


int main()
{
    int n;
    int k;

    printf("Enter integer\n");
    scanf("%d", &n);


    printf("Enter position of bit\n");
    scanf("%d", &k);

    decimalToBinary(n);

    int flag = checkBitSet(n, k);
    
    printf("value of %dth bit is %d\n", k, flag);

}

int checkBitSet(int num, int position)
{
    // get kth bit to lsb
    num = num >> position;

    // zero all bits except lsb and check lsb.
    num = num & 1;

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