#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

int reverse(int x) {
    bool sign;
    int result = 0, temp = x;
    int remain;
    if (x < 0)
        sign = false;
    else
        sign = true;
    //-----------------------
    while(abs(temp) > 0)
    {
        if (result > INT_MAX/10 && sign == true)
            return 0;
        if (result < INT_MIN/10 && sign == false)
            return 0;
        remain = temp % 10;
        temp = temp / 10;
        result = result * 10 + remain;
    }
    return result;
}

int main(int argc, char *argv[])
{
    int input;
    printf("INT_MAX = %d, INT_MIN = %d\n", INT_MAX, INT_MIN);
    printf("Plz input an integer: ");
    scanf("%d", &input);
    if (input > INT_MAX || input < INT_MIN)
        printf("Your input is invalid and is recognized as %d", input);
    printf("%d\n", reverse(input));
    return 0;
}
