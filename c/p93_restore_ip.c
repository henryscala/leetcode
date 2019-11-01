/*problem 93, restore IP
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
/* the buf for string in return value */
#define BUF_SIZE 16 



int equal(int* s1, int*s2){
    int i; 
    for (i=0;i<3;i++){
        if (s1[i] != s2[i]){
            return 0; 
        }
    }
    return 1; 
}

void inc(int* s,int index) {
    if (index>=3){
        return; 
    }
    s[index]+=1; 
    if (s[index]<3){
        return;
    }
    s[index]=0;
    inc(s,index+1); 
}

int valid(char *s, int* segments) {
    int i; 
    int totalLen = strlen(s); 
    char digits[4][4]; 
    int startIndex = 0; 
    int len=0;
    int lastLen=0;
    int num; 
    for (i=0;i<4;i++){
        printf("===\n");
        printf("%d\n",segments[i]);
    }
    for (i=0;i<4;i++) {
        len=segments[i]+1; 
        strncpy(digits[i],&s[startIndex],len);
        if (len == 3) {
            num = atoi(digits[i]); 
            if (num >255){
                return 0;  
            }
        }
        if (len>1) {
            /* if leading char is 0, but there are more than one digits */ 
            if (digits[i][0]==0x30){
                return 0; 
            }
        }
        startIndex += len; 
    }
    return 1; 
}

char* toIP(int *segments, char *s){
    char* ip = (char*)malloc(BUF_SIZE); 
    memset(ip,0,BUF_SIZE); 
    int startIndex = 0;  
    int len; 
    int i; 
    for (i=0;i<4;i++) {
        len=segments[i]+1; 
        strncat(ip,s+startIndex,len); 
        strcat(ip,"."); 
        startIndex += len; 
    }
    len = strlen(ip); 
    ip[len-1]='\0'; 
    return ip; 
} 
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** restoreIpAddresses(char* s, int* returnSize) {
    int len = strlen(s); 
    int i; 
    int segmentsLen = 0; 
    int lastSegmentLen = 0; 
    char* ip ; 
    char** ips = (char**)malloc(sizeof(char*)*28); 
    int num=0;
    int segmentLen[4] = {-1,0,0};
    int end[4] = {2,2,2}; 
    while (!equal(segmentLen, end)){
        inc(segmentLen,0);
        segmentsLen = 0; 
        for (i=0;i<3;i++){
           segmentsLen+=segmentLen[i]+1 ;  
        }
        lastSegmentLen = len - segmentsLen;
        if (lastSegmentLen <=0 || lastSegmentLen >3){
            continue; 
        }
        segmentLen[3]=lastSegmentLen-1; 
        if (valid(s,segmentLen)){
            ip=toIP(segmentLen,s); 
            ips[num++]=ip; 
        }
    }
    *returnSize = num; 
    return ips; 
}

int main() {
    int num;
    char **ips;
    int i; 
    /*ips=restoreIpAddresses("172162541",&num);*/
    ips=restoreIpAddresses("1111",&num);
    for (i=0;i<num;i++) {
        printf("%s\n",ips[i]); 
    } 
} 


