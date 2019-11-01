#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

void prtary(char* result, int len) {
    int i=0; 
    for (i=0; i<len;i++) {
        printf("%d",result[i]);
    } 
    printf("\n"); 
} 

char* times10withPowerN(char *result,int len, int n){
    int i; 
    if (n<=0){
        return result; 
    } 
    for (i=0;i<len-n;i++) {
        result[i] = result[i+n]; 
    }
    for (i=len-n;i<len;i++){
        result[i] = 0; 
    } 
    return result; 
} 

void add(char* result1 , char* result2, int len) {
    int carry=0; 
    int i; 
    for (i=len-1;i>=0;i--){
        result1[i] += result2[i]+carry; 
        carry = result1[i] / 10; 
        result1[i] = result1[i] % 10; 
    } 
} 


char* times(char* result, int len, int n) {
    int carry=0; 
    int i; 

    
    
    for (i=len-1;i>=0;i--){
        result[i] = result[i]*n + carry; 
        carry = result[i] / 10; 
        result[i] = result[i] % 10; 
    } 
    
    
    return result; 
} 

char* multiply(char* num1, char* num2) {
    int len1=strlen(num1);   
    int len2=strlen(num2);
    int maxLen = len1; 
    char *result;
    char *result2; 
    int i,k; 
    int countLeading0=0; 
    int actualLen=0; 
    int pos; 

    if (len2>maxLen) {
        maxLen = len2; 
    }
    maxLen *= 2;
    maxLen ++; 
    /* change from 0x31, 0x32 to 0x01, 0x02 */ 
    for (i=0;i<len1;i++){
        num1[i] &= 0x0F; 
    }
    for (i=0;i<len2;i++){
        num2[i] &= 0x0F; 
    }
    result = malloc(maxLen); 
    result2 = malloc(maxLen); 
    memset(result,0,maxLen); 
     
    /*memcpy(result+maxLen-len1,num1,len1);*/
    pos = 0; 
    for (i=len2-1;i>=0;i--) {
        memset(result2,0,maxLen); 
        memcpy(result2+maxLen-len1,num1,len1);
        times(result2,maxLen,num2[i]); 
        times10withPowerN(result2,maxLen,pos); 
        add(result ,result2,maxLen); 
       
        pos ++; 
    } 
    free(result2); 
    

    for (i=0;i<maxLen;i++){
        if (result[i]==0) {
            countLeading0++; 
        } else {
            break; 
        } 
    }
    /*the result is 0*/
    if (countLeading0 == maxLen){
        result[0] = 0x30; 
        result[1] = '\0'; 
        return result; 
    }
    memmove(result, result+countLeading0,maxLen-countLeading0); 
    result[maxLen-countLeading0] = '\0'; 

    for (i=0;i<maxLen-countLeading0;i++) {
        result[i] |= 0x30; /*change back*/ 

    }
    
    return result; 
    
}

int main() {
    char num1[]="121"; 
    char num2[]="22";
    printf("%s\n",multiply(num1,num2)); 
} 

