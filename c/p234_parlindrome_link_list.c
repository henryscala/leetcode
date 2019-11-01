#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

/** Problem 206 of leet code 
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      struct ListNode *next;
  };

int lenListNode(struct ListNode* l) {
    int len=0;
    for (;l!=NULL;l=l->next){
        len++;
    }
    return len; 
}

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

bool isPalindrome(struct ListNode* head) {
    struct ListNode* mid,*node1,*node2;    
    int i,midCount,len; 
    bool result=true;
    len = lenListNode(head); 

    if (len & 1){
        midCount = len/2+1;
    } else {
        midCount = len/2; 
    }
    for(mid=head,i=0;i<midCount;i++,mid=mid->next){
        ;/*do nothing*/
    }
    mid=reverseList(mid); 
    for(node1=head,node2=mid;node2!=NULL;node1=node1->next,node2=node2->next){
        if (node1->val!=node2->val){
            result=false;
            break; 
        }
    }
    mid=reverseList(mid); 
    return result; 
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
    n3.val = 3; 
    n4.val = 4; 
    n1.next = &n2; 
    n2.next = &n3; 
    n3.next = &n4; 
    n4.next = NULL; 
    printf("%d\n",(int)isPalindrome(&n1));
}

