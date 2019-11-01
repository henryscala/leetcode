#include <stdio.h> 
#include <stdlib.h>

/** Problem 206 of leet code 
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* list = NULL; 
    for (;head!=NULL;){
            struct ListNode* next = head->next;
            head->next = list;
            list = head; 
            head = next; 
    }
    return list; 
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
    printList(&n1); 
    head=reverseList(&n1);
    printList(head); 
}

