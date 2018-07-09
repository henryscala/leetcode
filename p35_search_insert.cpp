/* problem 35 of leetcode
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.*/
#include <assert.h>
#include <stdio.h>
int searchInsert(int* nums, int numsSize, int target) {
    int low=0;
    int high=numsSize-1;
    int mid = 0;
    while(low<=high){
        mid=low + (high - low)/2;

        if (nums[mid] == target){
            return mid;
        }
        if (nums[mid] < target){
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    if (target < nums[mid]){
        return mid;
    }
    return mid+1;

}

void testSearchInsert(){
    printf("test begin\n");
    int a[] = {1,3,5,6};
    assert(searchInsert(a,sizeof(a)/sizeof(int),5)==2);
    assert(searchInsert(a,sizeof(a)/sizeof(int),2)==1);
    assert(searchInsert(a,sizeof(a)/sizeof(int),7)==4);
    assert(searchInsert(a,sizeof(a)/sizeof(int),0)==0);
    printf("test end\n");
}
