#include <stdio.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strs == NULL){
        return NULL;
    }

    if (strsSize == 0 ){
        char *rs = (char *)malloc(1);
        *rs='\0';
        return rs; 
    }
    char *s = strs[0];
    int num = 0;
    int flag = 1;
    while (*s != '\0'){
        for (int i=1; i<strsSize; i++){
            if (strs[i] == NULL || strs[i][num] != *s){
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            break;
        s++;
        num++;
    }
    char *r = (char *)malloc((num+1) * sizeof(char));
    for (int j=0; j<num; j++){
        r[j] = strs[0][j];
    }
    r[num] = '\0';
    return r;
}

int main(void){
    char s1[] = "abc";
    char s2[] = "abcde";
    char s3[] = "abcdefg";
    char s4[] = "abchlk";
    char *s[4] = {s1, s2, s3, s4};
    printf("Strings:\n");
    int size = 4;
    for (int i=0; i<4; i++){
        printf("%d: %s\n", i, s[i]);
    }
    char *r = longestCommonPrefix(s, size);
    printf("result: %s\n", r);
    free(r);
    return 0;
}
