#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isPalindrome(int x) {
    int quotient = x, remain, reverse = 0;
    while(quotient > 0)
    {
        remain = quotient % 10;
        quotient = quotient / 10;
        reverse = reverse * 10 + remain;
    }
    if (reverse == x)
        return true;
    else
        return false;
}

int main(int argc, char *argv[])
{
    int input, result;
    printf("plz input an integer: ");
    scanf("%d", &input);
    printf("%d is %s\n", input, isPalindrome(input) ? "Palindrome" : "NOT Palindrome");

    return 0;
}
