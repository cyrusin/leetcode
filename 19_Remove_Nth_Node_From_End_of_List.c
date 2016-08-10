#include <stdio.h>
#include <stdlib.h>

/*
 * 19. Remove Nth Node From End of List
 * Given a linked list, remove the nth node from the end of list and return its head.
 * For example,
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 *
 */

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (head == NULL || n<=0){
        return head;
    }

    struct ListNode* p = head;
    int length = 0;
    while(p != NULL){
        p = p->next;
        length++;
    }

    if (length < n){
        return head;
    }

    int position = length - n;
    struct ListNode *pBefore, *pRemove=NULL;
    if (position == 0){ //remove head
        pRemove = head;
        head = head->next;
        pRemove->next = NULL;
        free(pRemove);
    }else{
        pBefore = head;
        for (int i=1; i<position; i++){
            pBefore = pBefore->next; 
            }
        pRemove = pBefore->next;
        if (pRemove->next == NULL){ //remove tail
            pBefore->next = NULL;
            free(pRemove);
        }else{
            pBefore->next = pRemove->next;
            pRemove->next = NULL;
            free(pRemove);
        }
    }
    return head;

}

void pprint(struct ListNode *pHead){
    if (pHead == NULL){
        return;
    }
    struct ListNode *p = pHead;
    while (p != NULL){
        printf("%d", p->val);
        if (p->next != NULL){
            printf("->");
        }
        p = p->next;
    }
    printf("\n");
    
}

int main(void){
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int size = sizeof(data)/sizeof(int);
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = data[0];
    head->next = NULL;
    struct ListNode *p = head, *pNode;
    for (int i=1; i<size; i++){
        pNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNode->val = data[i];
        pNode->next = NULL;
        p->next = pNode;
        p = p->next;
    }

    printf("List:\n");
    pprint(head); 
    printf("Remove nth node, input n:");
    int n;
    scanf("%d", &n);
    struct ListNode *pAfterRemove = removeNthFromEnd(head, n);
    printf("Rmove %dth node:\n", n);
    pprint(pAfterRemove);
    return 0;
}
