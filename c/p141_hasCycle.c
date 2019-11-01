/* problem 141 of leetcode */ 

struct ListNode {
        int val;
        struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = head; 
    struct ListNode *slow = head; 
    if (slow == 0) {
        return false; 
    }
    fast = slow->next; 
    if (fast == 0) {
        return false; 
    }
    while (fast != slow) {
        slow = slow->next; 
        fast = fast->next; 
        if (fast == 0) {
            return false; /*reaches end of list*/
        }
        if (fast == slow) {
            return true; 
        }
        fast = fast->next; 
        if (fast == 0) {
            return false; /*reaches end of list*/
        }
       

    }
    return true; 
}

