#include <stdio.h>
#include <stdlib.h>

/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode *pFirst = head, *pSecond = head->next;
    struct ListNode *pThird = pSecond->next;

    struct ListNode *pNewHead = pSecond;
    pSecond->next = pFirst;
    pFirst->next = pThird;
    struct ListNode *pFront = pFirst;
    while (pThird != NULL && pThird->next != NULL){
        pFirst = pThird;
        pSecond = pThird->next;
        pThird = pThird->next->next;
        pFront->next = pSecond;
        pSecond->next = pFirst;
        pFirst->next = pThird;
        pFront = pFirst;

    }
    return pNewHead;
}

int main(void){
    int a1[] = {1, 3, 5, 7, 9};

    int size = sizeof(a1)/sizeof(int);
    struct ListNode *l1, *p;
    printf("l1: ");
    for (int i=0; i<size; i++){
        printf("%d ", a1[i]);
        if (i==0){
            l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
            l1->val = a1[0];
            l1->next = NULL;
            p = l1;
        }else{
            p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->next->val = a1[i];
            p->next->next = NULL;
            p = p->next;
        }
    }
    printf("\n");
    p = swapPairs(l1);
    printf("swap: ");
    while (p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    return 0;
}
