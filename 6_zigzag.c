#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 6. ZigZag Conversion
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 *
 */
char* convert(char* s, int numRows) {
    if (s == NULL){
        return NULL;
    }
    if (numRows == 1){
        return s;
    }
    int length = 0;
    char *p = s;
    while (*p != '\0'){
        length++;
        p++;
    }

    char *r = (char *)malloc(sizeof(length+1));
    if (length<=numRows){
        memcpy(r, s, length+1);
        return r;
    }
    int count = 0;
    int step = 2 * (numRows -1);
    for (int i=0; i<numRows; i++){
        int interval = step - 2*i;
        for (int j=i; j<length; j+=step){
            r[count] = s[j];
            count++;
            if (interval<step && count<length && interval>0 && (j+interval)<length){
                r[count] = s[j+interval];
            count++;
            }
        }
   }
    r[length] = '\0';
    return r;
}

int main(void){
    char s[] = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
    int numRows = 3;
    printf("%s %d\n", s, numRows);
    char *r = convert(s, numRows);
    printf("%s\n", r);
    free(r);
    return 0;
}
