#include <stdio.h>

/*
 * 查找数组中出现次数超过一半的数
 *
 *
 */
int find(int data[], int num){
    int nTimes = 0, candidate;
    candidate = data[0];
    for (int i=1; i<num; i++){

        if (nTimes == 0){
            candidate = data[i];
            continue;
        }
        if (candidate == data[i]){
            nTimes++;
        }else if (candidate != data[i]){
            nTimes--;

        }
    }
    return candidate;
}
int main(void){
    int data[] = {1, 2, 1, 1, 2, 3, 4, 1, 5, 1, 1, 6, 1, 1};
    int num = sizeof(data)/sizeof(data[0]);
    printf("data:\n");
    for (int i=0; i<num; i++){
        printf("%d", data[i]);
    }
    printf("\n");
    int target = find(data, num);
    printf("result: %d\n", target);
    return 0;
}
