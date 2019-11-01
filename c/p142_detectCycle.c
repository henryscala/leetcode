/* problem 142 of leetcode */ 

struct ListNode {
        int val;
        struct ListNode *next;
};





struct ListNode* hasCycle(struct ListNode *head) {
    struct ListNode *fast = head; 
    struct ListNode *slow = head; 
    if (slow == 0) {
        return 0; 
    }
    fast = slow->next; 
    if (fast == 0) {
        return 0; 
    }
    while (fast != slow) {
        slow = slow->next; 
        fast = fast->next; 
        if (fast == 0) {
            return 0; /*reaches end of list*/
        }
        if (fast == slow) {
            return slow; 
        }
        fast = fast->next; 
        if (fast == 0) {
            return 0; /*reaches end of list*/
        }
       

    }
    return slow; 
}

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* mid = hasCycle(head); 
    struct ListNode* curr = head; 
    if (mid == 0) return 0; 
    while(curr!=mid){
        struct ListNode* next = mid->next; 
        if (next == mid) return next;
        while((next != mid) && (next != curr)) {
            next = next->next; 
        }
        if (next == mid) {
            if (next == curr) {
                return curr; 
            } else {
                curr = curr->next; 
            }
        } else {
            return curr; 
        }
       
    }
    return curr; 
}
