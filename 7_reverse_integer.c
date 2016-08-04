#include <stdio.h>

/*
 * 7. Reverse Integer
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 * If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 * Did you notice that the reversed integer might overflow?
 * Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 *
 */
int reverse(int x){
    if (x % 10 == x){
        return x;
    }
    int sign;
    int MAX;
    int data = x;
    if (x < 0){
        sign = -1;
        MAX = -(((unsigned)~0)>>1) - 1;
    }else{
        sign = 1;
        MAX = ((unsigned)~0) >> 1;
    }

    while ((data % 10) == 0){
        data = data / 10;
    }

    int reversed = 0, rest = 0;
    int max_reversed = MAX / 10, max_rest = MAX % 10;
    while (data != 0){

        rest = data % 10;
        data = data / 10;

        if (sign > 0){
            if (reversed > max_reversed){
                return 0;
            }

            if (reversed == max_reversed && rest > max_rest){
                return 0;
            }

        }else{
            if (reversed < max_reversed){
                return 0;
            }
            if (reversed == max_reversed && rest < max_rest){
                return 0;
            }
        }
        
        reversed = reversed * 10 + rest;
    }
    return reversed;
}

int main(void){
    int input;
    int MAX = ((unsigned)~0) >> 1;
    int NEG_MAX = -(((unsigned)~0)>>1) - 1;
    unsigned int max = (unsigned int)MAX;
    unsigned int neg_max = (unsigned int)NEG_MAX;
    printf("MAX: %d\n", MAX);
    printf("NEG_MAX: %d\n", NEG_MAX);
    printf("max: %o\n", max);
    printf("neg_max: %o\n", neg_max);
    printf("Input integer:\n");
    scanf("%d", &input);
    int result = reverse(input);
    printf("Reverse integer: %d\n", result);
    return 0;
}
