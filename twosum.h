#ifndef TWOSUM
#define TWOSUM

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



/* problem 1 of leetcode */



int *numsCopy;

void merge(int* nums, int beginIndex, int midIndex, int endIndex){
    int i,k,curr;
    curr = 0;
    for (i=beginIndex, k=midIndex; i<midIndex && k<endIndex; ){
        if (nums[i]<=nums[k]){
            numsCopy[curr++]=nums[i];
            i++;
        } else {
            numsCopy[curr++]=nums[k];
            k++;
        }
    }

    for (;i<midIndex;i++){
        numsCopy[curr++] = nums[i];
    }
    for (;k<endIndex;k++){
        numsCopy[curr++] = nums[k];
    }
    memcpy(nums+beginIndex, numsCopy, (endIndex - beginIndex)*sizeof(int));
}

void mergeSort1(int* nums, int beginIndex /*included*/, int endIndex /*excluded*/){
    int numElems = endIndex - beginIndex;
    int numElemsLeft, numElemsRight;
    if (numElems<=1){
        return;
    }

    numElemsLeft = numElems / 2;
    numElemsRight = numElems - numElemsLeft;
    mergeSort1(nums,beginIndex,beginIndex+numElemsLeft);
    mergeSort1(nums,beginIndex+numElemsLeft,endIndex);
    merge(nums,beginIndex, beginIndex+numElemsLeft, endIndex);
}

/* n*logn */
void mergeSort(int* nums, int numsSize){
    numsCopy = (int*)malloc(numsSize * sizeof(int));
    mergeSort1(nums,0,numsSize);
    free(numsCopy);
}


int binarySearch(int* nums, int beginIndex,int endIndex, int value){
    if (beginIndex >= endIndex){
        return -1;
    }

    int idx = beginIndex + (endIndex - beginIndex)/2;
    //printf(" begin %d end %d idx %d value %d\n",beginIndex,endIndex,idx,value);
    if (nums[idx] == value){
        return idx;
    }
    if (value < nums[idx]){
        return binarySearch(nums,beginIndex,idx,value);
    } else {
        return binarySearch(nums,idx+1,endIndex,value);
    }
}

int sequenceSearch(int* nums, int numsSize, int value, int excludingIdx){
    int i;
    for (i=0;i<numsSize;i++){
        if (i == excludingIdx){
            continue;
        }
        if (value == nums[i]){
            break;
        }
    }
    if (i<numsSize){
        return i;
    }
    return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i,k;
    int* result = (int*)malloc(sizeof(int)*2);
    int* numsBak = (int*)malloc(numsSize*sizeof(int));
    memcpy(numsBak,nums,numsSize*sizeof(int));

    mergeSort(numsBak,numsSize);

    for (i=0;i<numsSize;i++){
        //printf("%d\n",numsBak[i]);
    }

    for (i=0;i<numsSize;i++){
        //printf("call bs %d %d\n", nums[i], target-numsBak[i]);
        k = binarySearch(numsBak,0,numsSize,target - numsBak[i]);
        if (k!=-1){
            break;
        }
    }

    //printf("i=%d k=%d\n",i,k);
    //printf("%d %d\n",numsBak[i],numsBak[k]);
    i = sequenceSearch(nums,numsSize,numsBak[i],-1);
    k = sequenceSearch(nums,numsSize,numsBak[k],i);
    i ++;
    k ++;
    result[0] = i<k?i:k;
    result[1] = i<k?k:i;

    free(numsBak);
    return result;
}

void testTwoSum(){

    int numbers[] = {-1,-2,-3,-4,-5};
    int target = -8;
    int* result = twoSum(numbers,sizeof(numbers)/sizeof(int),target);


    assert(result[0]==3);
    assert(result[1]==5);
    free(result);
}

#endif // TWOSUM

