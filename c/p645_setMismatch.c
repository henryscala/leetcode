#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
/**
 * Problem 645 of leetcode
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int size=(numsSize + 1)*sizeof(int);
    int *result = malloc(sizeof(int)*2); 
    int *bucket = (int*)malloc(size); 
    int i; 
    int sum=0; 
    int theorySum; 
    memset(bucket,0,size); 
    
    for(i=0;i<numsSize;i++){
        sum += nums[i]; 
        if (bucket[nums[i]]){
            result[0] = nums[i];
        }
        bucket[nums[i]]=1; 
    }
    theorySum = (1+numsSize)*numsSize/2; 
    result[1]=result[0]+theorySum - sum; 
    *returnSize = 2; 
    free(bucket); 
    return result; 
}
int main(){
    int a[] = {1,2,2,4}; 
    int size; 
    int *result = findErrorNums(a,4,&size);
    printf("%d %d\n",result[0],result[1]); 
    free(result); 
} 

