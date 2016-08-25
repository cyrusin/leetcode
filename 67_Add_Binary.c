#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 *
 */

char* addBinary(char* a, char* b) {
    if (a == NULL || b == NULL){
        return NULL;
    }

    int sig = 0; // 进位
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len = len_a>len_b ? len_a : len_b;
    char *temp = (char *)malloc(sizeof(char)*(len+1));
    temp[len] = '\0';
    int va, vb, sum;
    int i = len_a - 1, j = len_b - 1, k = len - 1;
    while (i>=0 || j>=0){
        if (i>=0){
            va = a[i] - '0';
        }else{
            va = 0;
        }
        if (j>=0){
            vb = b[j] - '0';
        }else{
            vb = 0;
        }
        sum = va + vb + sig;
        if (sum > 1){
            sig = 1;
            sum = sum - 2;
        }else{
            sig = 0;
        }
        temp[k--] = '0' + sum;
        i--;
        j--;
    }

    if (sig > 0){
        temp = (char *)realloc(temp, len+2);
        int z=len+1;
        while (z>0){
            temp[z] = temp[z-1];
            z--;
        }
        temp[0] = '0' + sig;
    }
    return temp;
}
int main(void){
    char a[] = "0";
    char b[] = "1";
    char *r = addBinary(a, b);
    printf("r: %s\n", r);
    free(r);
    return 0;
}
