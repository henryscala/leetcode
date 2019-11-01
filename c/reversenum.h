#ifndef REVERSENUM
#define REVERSENUM

#include <stdio.h>


int reverse(int x) {
    printf("size=%d\n",sizeof(int));
    int sign=1;
    if (x==0) return x;
    if (x<0) {
        sign = -1;
        x = -x;
    }
    int result=0;
    int lastResult = 0;
    int rem;
    while(x!=0){
        rem=x % 10;
        x = x / 10;
        lastResult = result;
        result = result * 10;
        printf("r1=%d\n",result);
        result = result + rem;
        printf("r2=%d\n",result);
        if ( result < 0){
            result = 0;
            printf("over flow happens 1\n");
            break;//overflow happens
        } else if(lastResult > result){
            result = 0;
            printf("over flow happens 2\n");
            break;//overflow happens
        } else if (lastResult >0 && (result /lastResult) < 10){
            result = 0;
            printf("over flow happens 3\n");
            break;//overflow happens
        }
    }
    return result * sign;
}

void testRevereNum(){
    int i = 1534236469;
    int r = reverse(i);
    assert(r==0);
    i = 8192;
    r = reverse(i);
    assert(r==2918);
}

#endif // REVERSENUM

