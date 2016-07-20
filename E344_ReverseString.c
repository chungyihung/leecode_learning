#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* s) {
    int length = strlen(s);
    int i;
    char temp;
    for(i = 0; i < length/2; i++) {
        temp = *(s + i);
        *(s + i) = *(s + length - i - 1);
        *(s + length - i - 1) = temp;
    }
    return s;
}

int main(int argc, char* argv[]) {
    if (argc != 2 )
        return 0;
    else {
        printf("%s\n", reverseString(*(argv + 1)));
        return 0;
    }

}
