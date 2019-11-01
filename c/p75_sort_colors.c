/*problem 75 of leetcode
sort colors in one pass 
there are 3 colors that are standed by 0,1,2 

112200

I didn't figure out the solution. The solution first count the number of 0,1,2 respectively, and then refill the array. 
There are more clever solutions that only require one-pass, but are difficult to understand for me. I'm not clever enough. 
*/


#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

void printAry(int* nums, int numsSize) {
	int i; 
	for (i=0;i<numsSize;i++) {
		printf("%d, ", nums[i]); 
	}
	printf("\n"); 
}

void sortColors(int* nums, int numsSize) {    
    int i, count0,count1,count2; 
    count0=count1=count2=0; 
    for (i=0;i<numsSize;i++){
    	if (nums[i]==0){
    		count0++;
    	} else if (nums[i]==1) {
    		count1++;
    	} else {
    		count2++; 
    	}
    }
    for (i=0;i<numsSize;++i) {
    	if (i<count0){
    		nums[i] = 0; 
    	} else if (i>=count0 && i<count0+count1) {
    		nums[i] = 1; 
    	} else {
    		nums[i] = 2; 
    	}
    }
}



int main() {
	int ary1[] = {1,1,2,0,2,0}; 
	int ary2[] = {2,1}; 
	int ary3[] = {0,1}; 
	int ary4[] = {2,0,1}; 
	int *ary[4] = {ary1,ary2,ary3,ary4};
	int size[4] = {6,2,2,3}; 
	int i; 
	int num; 

	for (i=0;i<4;i++) {
		num = size[i]; 
		printf("num=%d\n",num); 
		printAry(ary[i],num); 
		sortColors(ary[i],num); 
		printAry(ary[i],num);
	}
	
	
	
}