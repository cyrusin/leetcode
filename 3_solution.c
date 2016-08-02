#include <stdio.h>
#include <string.h>

/*
 * Longest Substring Without Repeating Characters
 *
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 *Given "pwwkew", the answer is "wke", with the length of 3.
 *Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 *
 */
int lengthOfLongestSubstring(char* s) {
    int result=0, left=0;
    char *p = s;
    int length=0;
    while(*p!='\0'){
        length++;
        p++;
    }
    int last[255], current=0;
    memset(last, -1, sizeof(last));
    for (int i=0;i<length;i++){
        if (last[s[i]]>=left){
            left=last[s[i]]+1;
        }
        last[s[i]]=i;
        current = i-left+1;
        result=result>current?result:current;
    }
    return result;
}

int main(void){
    char s[] = "abcabcbb";
    printf("string: %s\n", s);
    int result = lengthOfLongestSubstring(s);
    printf("result: %d\n", result);
    return 0;
}
