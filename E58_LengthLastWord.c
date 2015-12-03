#include<stdio.h>
#include<stdlib.h>

int lengthOfLastWord(char* s) {
    int len = 0;
    int idx = 0;
    char tmpc;
    //First find the tail of the string
    while(*(s + idx) != NULL) {
        idx++;
    }

    //Skip the space at the tail
    while(*(s + idx - 1) == ' '){
        idx--;
    }

    if(idx > 0) {
        while(idx > 0 && *(s + idx - 1) != ' ')
        {
            idx--;
            len++;
        }
    } else
        return 0;
    return len;
}

int main(int argc, char *argv[])
{
    char *teststr = "a ";
    printf("The length of last word = %d\n", lengthOfLastWord(teststr));
    return 0;
}
