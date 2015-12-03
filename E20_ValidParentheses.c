#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct node {
    char data;
    struct node *next;
}Node;

Node *top = NULL;

char stack_push(char c)
{
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = c;
    new_node->next = top;
    top = new_node;
    printf("push %c\n", top->data);
}
char stack_pop(void)
{
    Node *tmp;
    char ret_char;
    if (top != NULL) {
        ret_char = top->data;
        tmp = top;
        top = top->next;
        free(tmp);
        printf("pop %c\n", ret_char);
        return ret_char;
    } else {
        return NULL;
    }
}

bool isValid(char* s) {
    int idx = 0;
    char tmpc;
    char cmpc;
    top = NULL;
    while(*(s+idx) != NULL) {
        tmpc = *(s+idx);
        if( tmpc == '(' || tmpc == '[' || tmpc == '{') {
            printf("hit %c\n", tmpc);
            stack_push(tmpc);
        } else if (tmpc == ')') {
            cmpc = stack_pop();
            if (cmpc != NULL && cmpc == '(') {
            } else {
                return false;
            }
        } else if (tmpc == ']') {
            cmpc = stack_pop();
            if (cmpc != NULL && cmpc == '[') {
            } else {
                return false;
            }
        } else if (tmpc == '}') {
            cmpc = stack_pop();
            if (cmpc != NULL && cmpc == '{') {
            } else {
                return false;
            }
        }
        idx = idx + 1;
    }
    if (top != NULL)
        return false;
    else
        return true;
}

int main(int argc, char *argv[])
{
    char *teststr = "]";
    printf("test string: %s\n", teststr);
    if (isValid(teststr))
    {
        printf("valid!\n");
    } else
        printf("invalid!\n");
    return 0;
}
