#include <stdio.h>
#include <stdlib.h>

/*2. Add Two Numbers
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 */
typedef struct _node{
    int val;
    struct _node *next;
}ListNode;

ListNode *AddList(ListNode *l1, ListNode *l2){
    if (l1 == NULL || l2 == NULL){
        return (l1 == NULL) ? l2 : l1;
    }
    
    ListNode *p1 = l1, *p2 = l2;
    ListNode *p = NULL, *r = NULL, *c=NULL;
    int addition = 0, sum = 0;
    int n1, n2;
    while (p1 != NULL || p2 != NULL){
        if (p1 != NULL){
            n1 = p1->val;
        }else{
            n1 = 0;
        }
        if (p2 != NULL){
            n2 = p2->val;
        }else{
            n2 = 0;
        }

        sum = n1 + n2 + addition;
        c = (ListNode *)malloc(sizeof(ListNode));
        if (sum >= 10){
            addition = 1;
            c->val = sum - 10;
        }else{
            c->val = sum;
            addition = 0;
        }

        c->next = NULL;
        printf("sum: %d\n", c->val);
        if (p == NULL){
            p = c;
            r = p;
        }else{
            p->next = c;
            p = p->next;
        }
        if (p1 != NULL){
            p1 = p1->next;
        }
        if (p2 != NULL){
            p2 = p2->next;
        }
    }

    if (addition != 0 && sum>=10){//最后一次相加是否需要进位
        c->next = (ListNode *)malloc(sizeof(ListNode));
        c->next->val = addition;
        c->next->next = NULL;
    }
    return r;
}
int main(void){
    int input1[] = {9};
    int input2[] = {1, 9, 9, 9, 9, 9, 9, 8, 9, 9, 9};
    ListNode *l1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *l2 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p1 = l1, *p2 = l2;
    int s1 = sizeof(input1)/sizeof(input1[0]);
    int s2 = sizeof(input2)/sizeof(input2[0]);
    for (int i=0; i<s1; i++){
        ListNode *c = (ListNode *)malloc(sizeof(ListNode));
        c->val = input1[i];
        c->next = NULL;
        p1->next = c;
        p1 = p1->next;
        printf("%d ", c->val);
    }
    printf("\n");
    for (int j=0; j<s2; j++){
        ListNode *c = (ListNode *)malloc(sizeof(ListNode));
        c->val = input2[j];
        c->next = NULL;
        p2->next = c;
        p2 = p2->next;
        printf("%d ", c->val);
    }
    printf("\n");

    ListNode *r = AddList(l1->next, l2->next);
    while (r != NULL){
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;
}
