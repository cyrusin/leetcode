#include <stdio.h>

/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 * Do not use recursion!!!
 */

int climbStairs(int n) {
    if (n<=2){
        return n;
    }

    int a = 1; // 1st step
    int b = 2;// 2nd step
    int temp;
    int i = 2;
    while (i<n){
        temp = a + b;
        a = b;
        b = temp;
        i++;
    }
    return b;
}
int main(void){
    int steps;
    printf("Input the steps of stair:\n");
    scanf("%d", &steps);
    int nsteps = climbStairs(steps);
    printf("%d steps to the top\n", nsteps);
    return 0;
}
