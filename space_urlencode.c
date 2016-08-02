#include <stdio.h>
#include <stdlib.h>

/*
 *"We are happy" -> "We%20are%20happy"
 *
 * O(n)
 */
char *SpaceEncode(char *s){
    if (s == NULL){
        return NULL;
    }

    int StringLength = 0, SpaceNumber = 0;
    char *p = s;
    while (*p != '\0'){
        if (*p == ' '){
            SpaceNumber++;
        }
        StringLength++;
        p++;
    }
    int length = StringLength + 2 * SpaceNumber + 1;
    char *result = (char *)malloc(length * sizeof(char));
    int i = 0, j = 0;
    while (i <= StringLength){
        if (s[i] != ' '){
            result[j] = s[i];
        }else{
            result[j++] = '%';
            result[j++] = '2';
            result[j] = '0';
        }
        i++;
        j++;
    }
 
    result[j] = '\0';

    return result;
}
int main(void){
    char s[] = "We are happy hello world ";
    printf("raw string: %s\n", s);
    char *r = SpaceEncode(s);
    //We%20are%20happy%20hello%20world%20
    printf("Space encode: %s\n", r);
    free(r);
    return 0;
}
