#include <stdio.h>

/*
 *152. Maximum Product Subarray
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 *
 *
 *
 */
int max(int a, int b, int c){
    int temp = a > b ? a : b;
    return temp > c ? temp : c;
}

int min(int a, int b, int c){
    int temp = a < b ? a : b;
    return temp < c ? temp : c;
}


int maxProduct(int *nums, int numsSize){
    int maxResult, maxNow, maxLast, minLast;
    maxResult = maxNow = maxLast  = minLast = nums[0];
    for (int i=1; i<numsSize; i++){
        maxNow = max(maxLast * nums[i], minLast* nums[i], nums[i]);
        minLast = min(maxLast * nums[i], minLast * nums[i], nums[i]);
        maxResult = maxResult > maxNow ? maxResult : maxNow;
        maxLast = maxNow;
    }
    return maxResult;
}


int main(void){
    int nums[] = {-4, -3, -2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);

    printf("nums: ");
    for (int i=0; i<numsSize; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    int result = maxProduct(nums, numsSize);
    printf("maxProduct: %d\n", result);
    return 0;
}
