#include <stdio.h>
#include <stdlib.h>

/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 *
 */

/* 
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL){
        return NULL;
    }

    struct ListNode *p = head, *temp = NULL;
    while (p->next != NULL){
        if (p->val == p->next->val){
            temp = p->next;
            p->next = p->next->next;
            free(temp);
        }else{
            p = p->next;
        }
    }

    return head;
}
int main(void){
    int values[] = {1, 1, 2, 2, 3};
    int i, size = sizeof(values)/sizeof(int);
    struct ListNode *p, *head;
    for (i=0; i<size; i++){
        printf("%d ", values[i]);
        if (i==0){
            head = p = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->val = values[i];
            p->next = NULL;
        }else{
            p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->next->next = NULL;
            p->next->val = values[i];
            p = p->next;
        }
    }
    printf("\n");
    head = deleteDuplicates(head);
    p = head;
    while (p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    return 0;
}
