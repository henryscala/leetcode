#ifndef PALINDROME
#define PALINDROME

#include <string.h>
#include <stdio.h>



/*int isParlindrome(char* s, int start,int len){
    int i=start;
    int j=len-1+start;
    while (i < j){
        if (s[i]!=s[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;

}

char* longestPalindrome(char* s) {
    static char buf[1000];
    int len = strlen(s);
    int curLen = len;
    int i;
    while(curLen >0){
        for (i=0;i+curLen<=len;i++){
            if (isParlindrome(s,i,curLen)){
                memcpy(buf,s+i,curLen);
                buf[curLen] = 0;
                return buf;
            }
        }
        curLen --;
    }
    return buf;
}*/

int calcParlindromeLen(char* s, int len, int pos) {
    int i,k;
    i=pos-1;
    k=pos+1;
    int curLen=1;
    for (;i>=0 && k<len;i--,k++){
        if (s[i]!=s[k]){
            break;
        }
        curLen += 2;
    }
    return curLen;
}

char* longestPalindrome(char* s) {
    /* assume the max length is 1000 */
    static char buf[2100]; /* store result */
    static char buf2[2100]; /* store intermediary */
    char filler='#';
    int len = strlen(s);
    int curLen;
    int maxLen=0;
    int i,k;
    int finalLen;

    memset(buf,0,2100);
    memset(buf2,0,2100);

    /* interleave original string with filler char -1 */
    k=0;
    buf2[k]=filler;
    for (i=0; i<len; i++){
        buf2[++k]=s[i];
        buf2[++k]=filler;

    }
    //printf("buf2=%s\n",buf2);

    for (i=0;i<len*2+1;i++){
        curLen = calcParlindromeLen(buf2, len*2+1, i);
        if (curLen > maxLen){
            maxLen = curLen;
            memcpy(buf,buf2+i-maxLen/2,maxLen);
            //printf("pos=%d, s=%s\n",i,buf);
        }

    }

    if (buf[0]==filler){/*filler char*/
        for (i=0;i<maxLen/2+1;i++){
            buf[i]=buf[1+2*i];
        }
        finalLen=maxLen/2;
    } else {
        for (i=0;i<maxLen/2+1;i++){
            buf[i]=buf[2*i];
        }
        finalLen=maxLen/2+1;
    }
    buf[finalLen]=0;

    return buf;
}



void testParlindrome(){
    char input[] = "12343210";
    char expect[] = "1234321";
    char input2[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char input3[] = "abb";
    char* result  = longestPalindrome(input3);
    //printf("result=%s\n",result);
    //assert(strcmp(result,expect)==0);
}

#endif // PALINDROME

