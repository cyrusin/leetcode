#include <stdio.h>

/*
 * 9. Palindrome Number
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 */

#define bool char
#define true 1
#define false 0

bool isPalindrome(int x){
    if (x<0){
        return false;
    }
    if (x<10){
        return true;
    }
    int y = x;
    int left = 1;
    while (y/10 != 0){
        y = y/10;
        left *= 10;
    }
    int right = 1;
    while (left >= right){
        if (x/left%10 != x/right%10){
            return false;
        }
        left /= 10;
        right *= 10;
    }
    return true;
}

int main(void){
    int input;
    printf("Input Number:\n");
    scanf("%d", &input);
    bool result = isPalindrome(input);
    if (result){
        printf("true\n");
    }else{
        printf("false\n");
    }
    return 0;
}
