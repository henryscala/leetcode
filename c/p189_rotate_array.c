#include <stdio.h> 
#include <stdlib.h>
/* fromIndex inclusive, toIndex exclusive */ 
void reverseArray(int* nums, int fromIndex, int toIndex){
    toIndex--; 
    while(fromIndex < toIndex) {
        int tmp; 
        tmp = nums[fromIndex]; 
        nums[fromIndex] = nums[toIndex]; 
        nums[toIndex] = tmp; 
        fromIndex++; 
        toIndex--; 
    } 
}

void rotate(int* nums, int numsSize, int k) {
    if (numsSize <= 0) return; 
    k %= numsSize; 
    reverseArray(nums, 0, numsSize); 
    reverseArray(nums, 0, k ); 
    reverseArray(nums, k, numsSize); 
}

int main() {
    int a[] = {1,2,3,4,5};
    int i; 
    rotate(a,5,2); 
    for(i=0;i<sizeof(a)/sizeof(int);i++) {
        printf("%d",a[i]); 
    }
    printf("\n"); 
}

