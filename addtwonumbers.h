#ifndef ADDTWONUMBERS
#define ADDTWONUMBERS



/* problem 2 of leetcode */



/**
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry=0;
    int sum = 0;
    struct ListNode* head=0;
    struct ListNode* tail=0;
    struct ListNode* curr = 0;
    struct ListNode* remain = 0;

    while(l1 != 0 && l2 !=0){
        sum = l1->val + l2->val + carry;
        if (sum >= 10){
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }
        curr = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->val = sum;
        curr ->next = 0;
        if (head==0){
            head = tail = curr;
        } else {
            tail->next = curr;
            tail = curr;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    if (l1!=0){
        remain = l1;
    } else {
        remain = l2;
    }

    if (remain !=0){

        while (remain !=0){
            curr = (struct ListNode*)malloc(sizeof(struct ListNode));
            curr ->next = 0;
            sum = remain->val + carry;
            if (sum >= 10){
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            curr->val = sum;

            if (head==0){
                head = tail = curr;
            } else {
                tail->next = curr;
                tail = curr;
            }
            remain = remain->next;
        }
    }
    if (carry != 0){
        curr = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr ->next = 0;
        curr->val =  carry;
        carry = 0;
        if (head==0){
            head = tail = curr;
        } else {
            tail->next = curr;
            tail = curr;
        }
    }

    return head;
}

void testAddTwoNumbers(){
    struct ListNode* l1=0;
    struct ListNode* l2=0;

    addTwoNumbers(l1,l2);
}

#endif // ADDTWONUMBERS

