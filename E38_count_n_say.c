#include <stdio.h>
#include <stdlib.h>

calculate(char* str)
{
    int i = 0;
    int count = 0;
    char temp;
    char result[100000];
    sprintf(result, "");

    while( *(str + i) != '\0' )
    {
        temp = *(str+i);
        count = 0;
        while( temp == *(str + i + count) )
        {
            count++;
        }
        sprintf(result,"%s%d%c", result, count, temp);
        i += count;
    }
    sprintf(str, "%s", result);
}

static char str_res[100000];
static char* countAndSay(int n) {
    int i;

    sprintf(str_res, "1");

    for( i = 1; i < n; i++)
    {
        calculate(str_res);
    }
    return str_res;
}

int main()
{
    //countAndSay(2);
    printf("%s", countAndSay(3));
    return 0;
}
