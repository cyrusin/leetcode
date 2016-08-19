#include <stdio.h>
#include <stdlib.h>
/*
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 */
char *resolve(char *src);
char *countAndSay(int n){
    if (n == 0){
        return NULL;
    }

    char *result = (char *)malloc(2 * sizeof(char));
    result[0] = '1';
    result[1] = '\0';
    int count = 1;
    while(count < n){
        result = resolve(result);
        //printf("result: %s\n", result);
        count++;
    }
    return result;
}

char *resolve(char *src){
    if (src == NULL){
        return NULL;
    }

    int count = 0;
    char *current = src, *same = src;
    char *result;
    int size_now = 0;
    while (*current != '\0'){
        //printf("%c ", *current);
        count++;
        current++;
        if (*current != *same){
            if (size_now == 0){ //first alloc memory
                result = (char *)malloc(2 * sizeof(char));
                result[0] = '0'+count;
                result[1] = *same;
                //printf("malloc: %c %c\n",result[0], result[1]);
                size_now += 2;
            }else{
                size_now += 2;
                result = (char *)realloc(result, size_now);
                result[size_now-2] = '0'+count;
                result[size_now-1] = *same;
                //printf("realloc: %c %c\n", result[size_now-2], result[size_now-1]);
            }
            same = current;
            count = 0;
        }
    }
    result = (char *)realloc(result, size_now+1);
    result[size_now] = '\0';
    free(src);// free old result
    src=NULL;
    return result;
}
int main(void){
    int n = 7;
    char *s = countAndSay(n);
    printf("n: %d, s: %s\n", n, s);
    free(s);
    return 0;
}
