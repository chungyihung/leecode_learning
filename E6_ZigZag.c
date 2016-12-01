#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

/********************************************************
 * n = 5:
 *   1       9       17     x-----8---x
 *   2     8 10    16       x---6--2--x
 *   3    7  11   15        x--4--4---x
 *   4  6    12 14          x--2---6--x
 *   5       13             x----8----x
 * n = 4:
 *   1    7    13           x---6----x
 *   2  6 8  12             x--4--2--x
 *   3 5  9 11              x-2---4--x
 *   4    10                x -- 6 --x
 *
 * n = 3
 *   1   5   9              x----4---x
 *   2 4 6 8 10             x---2--2-x
 *   3   7                  x---4----x
 *******************************************************/
char* convert(char* s, int numRows) {
    int totalPed = numRows * 2 - 2;
    int lidx, ridx;
    int i, sp;
    unsigned int len = strlen(s);
    unsigned int stridx = 0;
    static char retstr[65536];
    memset(retstr, 0, sizeof(retstr));

    // initialize
    lidx = totalPed;
    ridx = 0;

    if(numRows == 1)
        {
        strcpy(retstr, s);
        }
    else
        {
        for( i = 0; i < numRows; i++)
            {
            sp = i;

            //Initialize first char
            if( sp < len)
                {
                retstr[stridx] = *(sp + s);
                stridx++;
                printf("%c ", *(sp+s));
                }
            else
                {
                break;
                }

            while( sp < len )
                {
                if( lidx != 0 )
                    {
                    if ((sp + lidx) < len)
                        {
                        sp = sp + lidx;
                        retstr[stridx] = *(sp + s);
                        stridx++;
                        printf("%c ", *(sp+s));
                        }
                    else
                        {
                        break;
                        }
                    }

                if( ridx != 0 )
                    {
                    if ((sp + ridx) < len)
                        {
                        sp = sp + ridx;
                        retstr[stridx] = *(sp + s);
                        stridx++;
                        printf("%c ", *(sp+s));
                        }
                    else
                        {
                        break;
                        }
                    }

                }
            printf("\n");
            lidx -=2;
            ridx +=2;
            }
        retstr[stridx] = '\0';
        }

    return retstr;
}

int main()
{
    printf("%s\n", convert("123456789ABC", 1));
    return 0;
}
