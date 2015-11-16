#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int* nums, int numsSize) {

    int nDup = 0;
    int i, newi = 0;
    for (i = 0; i < numsSize; i++) {
        if (i - 1 >= 0 &&nums[i] == nums[i - 1]) {
            //duplicate, pedding
            nDup = nDup + 1;
        } else {
            nums[newi] = nums[i];
            newi = newi + 1;
        }
    }
    return numsSize - nDup;
}

#define nArr 10
int main(int argc, char *argv[])
{
    int i;
    int array[nArr] = {0, 1, 1, 1, 2, 3, 4, 4, 5, 6};
    //int array[nArr] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int newlen = removeDuplicates(array, nArr);

    for (i = 0; i < newlen; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
