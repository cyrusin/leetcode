#include <stdio.h>

/*
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example,
 * Given input array nums = [1, 1, 2],
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
 * It doesn't matter what you leave beyond the new length.
 *
 */
int removeDuplicates(int* nums, int numsSize) {
    if (nums == NULL){
        return 0;
    }
    if (numsSize <= 0){
        return 0;
    }
    if (numsSize == 1){
        return numsSize;
    }

    int index_use = 1; //store data from this position
    while (index_use < numsSize && nums[index_use] != nums[index_use - 1]){
        index_use++;
    }
    if (index_use == numsSize){ //no duplicated
        return numsSize;
    }
    int i = index_use + 1;
    while (i < numsSize){
        while (i < numsSize && nums[i] == nums[i-1]){
            i++;
        }
        if (i != numsSize){
            nums[index_use++] = nums[i];
        }else{
            break;
        }
        i++;
    }
    return index_use;
}

int main(void){
    int data[] = {1, 1, 1, 1, 2};
    int length = sizeof(data)/sizeof(int);
    printf("data: ");
    for (int i=0; i<length; i++){
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("Remove duplicated: ");
    int new_length = removeDuplicates(data, length);
    for (int j=0; j<new_length; j++){
        printf("%d ", data[j]);
    }
    printf("\n");
    return 0;
}
