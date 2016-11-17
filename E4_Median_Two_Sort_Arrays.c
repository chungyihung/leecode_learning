#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int mergesize = nums1Size + nums2Size;
    bool isOdd = mergesize % 2 == 0 ? false:true;
    int medidx = isOdd == true ? mergesize / 2 + 1 : mergesize / 2;
    int i, j1 = 0, j2 = 0;
    int currval = 0, nextval = 0;
    double ret = 0;

    for( i = 0; i < medidx; i++ )
        {
        if( j1 != nums1Size && j2 != nums2Size )
            {
            if( nums1[j1] < nums2[j2] )
                {
                currval = nums1[j1];
                j1++;
                }
            else
                {
                currval = nums2[j2];
                j2++;
                }
            }
        else if( j1 == nums1Size && j2 != nums2Size )
            {
            currval = nums2[j2];
            j2++;
            }
        else if( j1 != nums1Size && j2 == nums2Size )
            {
            currval = nums1[j1];
            j1++;
            }
        }
    /* Now we get the medium value */
    if( isOdd != true )
        {
        if( j1 != nums1Size && j2 != nums2Size )
            {
            if( nums1[j1] < nums2[j2] )
                {
                nextval = nums1[j1];
                j1++;
                }
            else
                {
                nextval = nums2[j2];
                j2++;
                }
            }
        else if( j1 == nums1Size && j2 != nums2Size )
            {
            nextval = nums2[j2];
            j2++;
            }
        else if( j1 != nums1Size && j2 == nums2Size )
            {
            nextval = nums1[j1];
            j1++;
            }
        ret = ( (double)currval + (double)nextval ) / 2;
        }
    else
        {
        ret = (double)currval;
        }
    return ret;
}

void main()
{
    int array1[10] = {1,3,6,11,34,56,88,123,155,611};
    int array2[6] = {3,6,21,39,74,82};
    double medium = 0;

    medium = findMedianSortedArrays(&array1[0], 10, &array2[0], 6);
    printf("medium is %f\n", medium );

}
