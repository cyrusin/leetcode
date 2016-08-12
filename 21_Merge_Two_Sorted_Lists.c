#include <stdio.h>
#include <stdlib.h>

/*
 *Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};
//Two sorted lists
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL){
        return l2;
    }
    if (l2 == NULL){
        return l1;
    }

    struct ListNode *pHead, *pMerged, *p = l1, *q = l2;
    if (p->val <= q->val){
        pHead = p;
        p = p->next;
        pHead->next = NULL;
    }else{
        pHead = q;
        q = q->next;
        pHead->next = NULL;
    }

    pMerged = pHead;
    while (p!=NULL && q != NULL){
        if(p->val <= q->val){
            pMerged->next = p;
            p = p->next;
            pMerged = pMerged->next;
            pMerged->next = NULL;
        }else{
            pMerged->next = q;
            q = q->next;
            pMerged = pMerged->next;
            pMerged->next = NULL;
        }
    }
    if (p == NULL){
        pMerged->next = q;
    }
    if (q == NULL){
        pMerged->next = p;
    }
    return pHead;
}
int main(void){
    int a1[5] = {1, 3, 5, 7, 9};
    int a2[5] = {2, 4, 6, 8, 10};

    struct ListNode *l1, *l2, *p;
    printf("l1:\n");
    for (int i=0; i<5; i++){
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
    printf("l2:\n");
    for (int j=0; j<5; j++){
        printf("%d ", a2[j]);
        if (j == 0){
            l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
            l2->val = a2[0];
            l2->next = NULL;
            p = l2;
        }else{
            p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->next->val = a2[j];
            p->next->next = NULL;
            p = p->next;
        }
    }
    printf("\n");
    printf("Merged:\n");
    p = mergeTwoLists(l1, l2);
    struct ListNode *pDelete=NULL;
    while (p != NULL){
        printf("%d ", p->val);
        pDelete = p;
        p = p->next;
        pDelete->next = NULL;
        free(pDelete);
    }
    printf("\n");
    return 0;
}
