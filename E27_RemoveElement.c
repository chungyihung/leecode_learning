/*************************************************************************************
 * Given an array and a value, remove all instances of that value in place
 * and return the new length.
 * The order of elements can be changed.
 * It doesn't matter what you leave beyond the new length.
 * **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    /* For example: {1,2,2,3,1,3,3}, remove 3 we get {1,2,2,1}
     * Note that the the keyword "in place" is needed so that creating new array is forbidden*/
    int new_idx = 0, old_idx = 0;
    for (old_idx = 0; old_idx < numsSize; old_idx++) {
        if(nums[old_idx] != val) {
            nums[new_idx++] = nums[old_idx];
        }
    }
    return new_idx;
}


#define nArray 5
int main()
{
    int testarray[nArray] = {1,2,2,3,3};
    int newlength = 0, i = 0;
    newlength = removeElement(testarray, nArray, 2);
    for (i = 0; i < newlength; i++) {
        printf("%d", testarray[i]);
    }
    return 0;
}
