/* problem 461 of leetcode */ 
#include <stdio.h> 

int hammingDistance(int x, int y) {
    int distance = 0; 
    int i=0;
    int leftNum; 
    while ( x!=0 && y!=0 && i<31) {
        if ((x & 1) != (y & 1)){
            distance++;
        }
        i++;
        x >>= 1 ;
        y >>= 1 ;
    }
    if (i==31) {
        return distance; 
    }
    if (x==0) {
        leftNum = y; 
    } else {
        leftNum = x; 
    }
    for(;i<31 && leftNum!=0;i++){
        if (leftNum & 1){
            distance++;
        }
        leftNum >>= 1; 
    }
    return distance; 
}

int main() {
    printf("%d\n",hammingDistance(4,1)); 
    printf("%d\n",hammingDistance(3,1)); 
}

