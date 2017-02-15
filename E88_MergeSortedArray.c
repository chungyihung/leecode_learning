#include<stdio.h>
#include<stdlib.h>

void merge(int* nums1, int m, int* nums2, int n) {
    int total_size = m + n;
    int i, p1 = m, p2 = n;

    /* main algo. */
    for( i = total_size - 1; i >= 0; i-- )
        {
        if( p1 > 0 && p2 > 0 )
            {
            if(nums1[p1-1] > nums2[p2-1])
                {
                nums1[i] = nums1[p1-1];
                p1--;
                }
            else
                {
                nums1[i] = nums2[p2-1];
                p2--;
                }
            }
        else if( p1 == 0 && p2 >0 )
            {
            nums1[i] = nums2[p2-1];
            p2--;
            }
        else if( p1 > 0 && p2 == 0 )
            {
            nums1[i] = nums1[p1-1];
            p1--;
            }
        }
}


#define ARR_SIZE    20
#define ARR1_SIZE   6
#define ARR2_SIZE   14
void main()
{
int array1[ARR_SIZE] = { 1,2,6,23,44,66,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int array2[ARR2_SIZE] = { 3,4,7,21,23,33,34,36,43,44,45,55,67,68 };
int i;
merge(array1, ARR1_SIZE, array2, ARR2_SIZE );

printf("\n");
for( i = 0; i < ARR_SIZE; i++ )
    {
    printf("%d ", array1[i]);
    }
printf("\n");

}
