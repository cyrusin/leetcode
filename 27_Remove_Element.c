#include <stdio.h>

/*
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 * Your function should return length = 2, with the first two elements of nums being 2.
 */

int removeElement(int* nums, int numsSize, int val) {
    if (nums == NULL){
        return 0;
    }
    if (numsSize <= 0){
        return 0;
    }

    int i;
    for (i=0; i<numsSize; i++){
        if (nums[i] == val){
            break;
        }
    }

    if (i == numsSize){
        return numsSize;
    }

    if (i == numsSize-1){
        return numsSize - 1;
    }

    int pos = i; // store data from this position
    i = i + 1;
    while (i<numsSize){
        if (nums[i] != val){
            nums[pos++] = nums[i];
        }
        i++;
    }

    return pos;
}
int main(void){
    int data[] = {3, 2, 2, 3};
    printf("data: ");
    int size = sizeof(data)/sizeof(int);
    for (int i=0; i<size; i++){
        printf("%d ", data[i]);
    }
    printf("\n");
    int new_size;
    new_size = removeElement(data, size, 3);
    printf("Remove element: 3, ");
    for (int j=0; j<new_size; j++){
        printf("%d ", data[j]);
    }
    printf("\n");
    return 0;
}
