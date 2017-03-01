#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

void normalization(char *input, char *output, unsigned int * cnt )
{
    char *tmp = input;
    while( *tmp != '\0') {
        if( *tmp >= 'A' && *tmp <= 'Z') {
            *output = 'a' + (*tmp - 'A');
            output++;
            (*cnt)++;
        } else if( ( *tmp >= 'a' && *tmp <= 'z' ) ||
                   ( *tmp >= '0' && *tmp <= '9' ) ) {
            *output = *tmp;
            output++;
            (*cnt)++;
        }
        tmp++;
    }
    *output = '\0';
}

bool isPalindrome( char *s ) {
    unsigned long length = strlen( s );
    char *normalstr = NULL;
    unsigned int i;
    unsigned int * nrml_cnt = malloc( sizeof(unsigned int));
    bool ret = true;
    *nrml_cnt = 0;

    if( length > 0 ) {
        normalstr = malloc( length * sizeof(char) );
    } else {
        // If empty, we consider the str as a palindrome
        return true;
    }

    normalization( s, normalstr, nrml_cnt );
    printf("normalstr = %s, nrml_cnt = %d \n", normalstr, *nrml_cnt );

    for( i = 0; i < *nrml_cnt / 2; i++ ) {
        if( *( normalstr + i ) != *(normalstr + *nrml_cnt - i - 1 ) ) {
            ret = false;
            break;
        }
    }

    return ret;
}

/*************************************************
 * Version 2 is from leetcode solution, write here
 * just for backup.
 *************************************************/
bool isPalindrome2(char* s) {
    char *head, *tail;
    int len = strlen(s);
    if( len <= 0 )  return true;

    head = s;
    tail = s + len - 1;

    while(head < tail) {
        if( !isalnum( *head ) ) { head ++; continue;}
        if( !isalnum( *tail ) ) { tail --; continue;}
        if( tolower(*head++) != tolower(*tail--)) { return false;}
    }
    return true;
}


int main()
{
    char *test = "abcdbba";

    if( isPalindrome( test ) ) {
        printf("True!\n");
    } else {
        printf("False!\n");
    }

    if( isPalindrome2( test ) ) {
        printf("True!\n");
    } else {
        printf("False!\n");
    }

    return 0;
}
