/* **************************************************************************************************
 * Question:
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target,
 * where index1 must be less than index2. Please note that your returned answers
 * (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 ****************************************************************************************************/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * The object is to find the index of two number which the sum equal to "target"
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int value;
    unsigned index;
} numNode;

int qsort_cmp(const void *a, const void *b) {
    return (*(numNode *)a).value - (*(numNode *)b).value;
}

int *twoSum(int *nums, int numsSize, int target) {
    int i, j, exceed_idx = numsSize;
    int *answer = malloc(sizeof(int) * 3);
    numNode numNodes[numsSize];
    /* Step 1: Init unsorted number as struct Node and qsort them*/
    for(i = 0; i < numsSize; i++) {
        numNodes[i].value = nums[i];
        numNodes[i].index = i + 1;
    }
    qsort(numNodes, numsSize, sizeof(numNodes[0]), qsort_cmp);

    /* Step 2: Try adding*/
    for(i = 0; i < numsSize; i++) {
        for(j = i + 1; j < numsSize; j++) {
            if (numNodes[i].value + numNodes[j].value == target) {
                if (numNodes[i].index > numNodes[j].index) {
                    answer[1] = numNodes[i].index;
                    answer[0] = numNodes[j].index;
                } else {
                    answer[0] = numNodes[i].index;
                    answer[1] = numNodes[j].index;
                }
                return answer;
            }
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    return 0;
}
