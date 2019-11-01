#include <stdio.h> 
/*problem 287 of leet code
 * referred to https://www.youtube.com/watch?v=iZVBVCpmugI
 * */
int findDuplicate(int* nums, int numsSize) {
    int i; 
    int slow;
    int fast; 
    if (numsSize <= 2) {
        return -1; 
    }
    slow = nums[0]; 
    fast = nums[nums[0]];
    /* slow and fast meet(fast is 2 times the speed of slow), 
     * it means there is cycle in the array represented link list */
    while (slow!=fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    /* slow and fast meet again(fast and slow have the same speed) */ 
    slow = 0; 
    while (fast!=slow){
        fast = nums[fast]; 
        slow = nums[slow]; 
    }
    return fast; 
}


