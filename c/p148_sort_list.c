#include <stdio.h> 
#include <stdlib.h>

/** Problem 148 of leet code 
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      struct ListNode *next;
  };

int isListLength1(struct ListNode* head) {
    return (head != NULL) && (head->next == NULL); 
}

/* the list is at least with length 2 */ 
void splitList(struct ListNode* head,  struct ListNode** half2  ) {
     struct ListNode* slow = head;
     struct ListNode* fast = head;
     struct ListNode* prevSlow = head;
     while (fast != NULL) {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast) {
            fast = fast->next; 
        }
     }
     prevSlow->next = NULL; 
     *half2 = slow; 
}

struct ListNode* mergeList(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head, *tail; 
    head = NULL; 
    tail = NULL;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            if (tail ==NULL) {
                head = tail = l1; 
            } else {
                tail->next = l1; 
                tail = l1; 
            }
            l1=l1->next; 
        } else {
            if (tail == NULL) {
                head = tail = l2; 
            } else {
                tail->next = l2; 
                tail = l2; 
            }
            l2=l2->next; 
        }
    }
    if (l1 != NULL) {
       tail->next = l1;  
    } else if (l2 != NULL) {
       tail->next = l2; 
    } else {
        tail->next = NULL;
    }
    return head; 
}

struct ListNode* sortList(struct ListNode* head) {
    struct ListNode* half2=NULL;
    struct ListNode* half1=NULL;
    if (head == NULL || isListLength1(head)) {
        return head; 
    }
    splitList(head,&half2); 
    half1=sortList(head);
    half2=sortList(half2);
    return mergeList(half1,half2); 
}

void printList(struct ListNode* l){
    for (;l!=NULL;l=l->next){
        printf("%d",l->val);
    }
    printf("\n"); 
}

int main() {
    struct ListNode n1,n2,n3,n4,*head; 
    n1.val = 4; 
    n2.val = 3;
    n3.val = 2; 
    n4.val = 1; 
    n1.next = &n2; 
    n2.next = &n3; 
    n3.next = &n4; 
    n4.next = NULL; 
    head=sortList(&n1);
    printList(head); 
}

