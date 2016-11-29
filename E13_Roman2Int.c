#include<stdio.h>
#include<stdlib.h>

#define M 1000
#define D 500
#define C 100
#define L 50
#define X 10
#define V 5

int romanToInt(char* s) {
    int res = 0;
    while( *s != '\0') {
        switch(*s) {
            case 'I':
                if( *(s+1) == 'V') {
                    res += 4;
                    ++s;
                } else if ( *(s+1) == 'X') {
                    res += 9;
                    ++s;
                } else {
                    res +=1;
                }
                break;
            case 'V':
                res += 5;
                break;
            case 'X':
                if( *(s+1) == 'L' ) {
                    res +=40;
                    ++s;
                } else if( *(s+1) == 'C' ){
                    res += 90;
                    ++s;
                }
                else {
                    res += 10;
                }
                break;

            case 'L':
                res += 50;
                break;

            case 'C':
                if( *(s+1) == 'D') {
                    res += 400;
                    ++s;
                    break;
                } else if( *(s+1) == 'M') {
                    res += 900;
                    ++s;
                } else {
                    res += 100;
                }
                break;

            case 'D':
                res += 500;
                break;

            case 'M':
                res += 1000;
                break;

            default:
                break;
        }
        ++s;
    }
    return res;
}

int main()
{
    char input[100];
    int res = 0;
    fgets(input, sizeof(input), stdin);
    res = romanToInt(input);
    printf("%s = %d\n", input, res);
    return 0;
}
