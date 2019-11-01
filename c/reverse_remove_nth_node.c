/* leet code problem 19 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct ListNode {
      int val;
      struct ListNode *next;
};


 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode** reserve;
    struct ListNode* node; 
    struct ListNode* prevNode; 
    int curr = -1;
    
    int size=n+1; 
    int count=0;

    if (head == NULL) {
        return NULL; 
    }

    reserve = (struct ListNode**)malloc(sizeof(struct ListNode*)*size);
    memset(reserve,0,sizeof(struct ListNode*)*size); 

    for (node=head;node!=NULL;node=node->next) {
        curr ++; 
        curr = curr % size; /*recycle queue*/
        reserve[curr]=node;
        count ++; 
    }

    if (count == 1) {
        free(head); 
        free(reserve); 
        return NULL;
    }

    curr = curr - n + 1; /*the node index to be removed */ 
    if ( curr < 0 ) {
        curr += size; 
    }
    node = reserve[curr];
    curr --;
    if (curr < 0) {
        curr += size; 
    }

    
    prevNode = reserve[curr]; /* prior node of the deleted node */
    if (node == head) {
        head = node->next; 
    } else {
        prevNode->next = node -> next; 
    }
    free(node); 


    /*now there are at least two nodes in the head*/


    free(reserve); 

    return head; 

}

int main() {
    return 0; 
}

