#include <stdio.h>

/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example, 
 * Given s = "Hello World",
 * return 5.
 *
 */
int lengthOfLastWord(char *s){
    if (s == NULL){
        return 0;
    }

    char *p = s;
    int num = 0;
    while (*p != '\0'){
        if (*p == ' '){
            if (*(p+1) == '\0'){ //空格在最后，直接跳出循环，使用上一个有效计数即可
                break;
            }
            if (*(p+1) != ' '){ //只有下一个字符是有效字符，才清零计数器
                num = 0;
            }
        }else{
            num++;
        }
        p++;
    }
    return num;
}
int main(void){
    char s[] = "    hello    world       ";
    printf("%s\n", s);
    int length = lengthOfLastWord(s);
    printf("%d\n", length);
    return 0;
}
