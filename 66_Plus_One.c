#include <stdio.h>
#include <stdlib.h>

/*
 * Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 */

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if (digits == NULL || digitsSize <= 0 ){
        return NULL;
    }

    int *result = (int *)malloc(sizeof(int) * digitsSize);
    int i = digitsSize-1;
    int sig = 0;
    while (i>=0){
        if (i == (digitsSize-1)){
            result[i] = digits[i]+1;    
        }else{
            result[i] = digits[i] + sig;
        }
        
        if (result[i]>9){
            sig = 1;
            result[i] = result[i] - 10;
        }else{
            sig = 0;
        }
        //printf("%d ", result[i]);
        i--;
    }
    //printf("\n");
    if (sig > 0){ //最后有进位
        result = (int *)realloc(result, sizeof(int)*(digitsSize+1));
        for (int j=digitsSize; j>0; j--){
            result[j] = result[j-1];
        }
        result[0] = sig;
        *returnSize = digitsSize + 1;
    }else{
        *returnSize = digitsSize;
    }
    return result;
}

int main(void){
    int data[] = {9, 9, 9, 9, 9, 9, 9};
    int size = sizeof(data)/sizeof(int);
    int *r_size = (int *)malloc(sizeof(int));
    int *r_data = plusOne(data, size, r_size);
    printf("digits: ");
    for (int i=0; i<size; i++){
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("Plus one: ");
    if (r_data != NULL){
        for (int j=0; j<*r_size; j++){
            printf("%d ", r_data[j]);
        }
        printf("\n");
    }else{
        printf("r_data: NULL\n");
    }
    free(r_size);
    free(r_data);
    return 0;
}
