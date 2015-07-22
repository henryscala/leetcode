#ifndef LONGSUBSTR
#define LONGSUBSTR
#include "stdio.h"
#include "assert.h"
/* problem 3 of leetcode */

/*
 * I tried two solutions. The first solution, which commented out, is not work.
 * The second solution works, it is accepted by leetcode, but it takes over 500 ms which is not the best.
 * In the following link, there is solution in linear time.
 * http://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
*/


//int rightLongestSubString(char* s, int index, int len){
//    int i,k;
//    int maxLen=0;
//    int found;
//    for (i=len-1+index;i>=index;i--){
//        found = 0;
//        for (k=len-1+index;k>i;k--){
//            if (s[k]==s[i]){
//                found = 1;
//                break;
//            }
//        }
//        if (found){
//            break;
//        } else {
//            maxLen ++;
//        }
//    }
//    return maxLen;
//}

//int leftLongestSubString (char* s, int index, int len){
//    int i,k;
//    int maxLen = 0;
//    int found;

//    for (i=index;i<index+len;i++){
//        found = 0;
//        for (k=index;k<i;k++){
//            if (s[k]==s[i]){
//                found = 1;
//                break;
//            }
//        }
//        if (found){
//            break;
//        } else {
//            maxLen ++;
//        }
//    }
//    return maxLen;
//}

//int mergeLongestRightToLeft(char* s, int indexLeft,int lenLeft, int indexRight, int lenRight){
//    int maxLen = lenLeft;
//    int i,k,found;
//    for (i=0;i<lenRight;i++){
//        found = 0;
//        for (k=0;k<lenLeft;k++){
//            if (s[k+indexLeft]==s[i+indexRight]){
//                found = 1;
//                break;
//            }
//        }
//        if (found){
//            break;
//        } else {
//            maxLen ++;
//        }
//    }
//    return maxLen;
//}

//int mergeLongestLeftToRight(char* s, int indexLeft,int lenLeft, int indexRight, int lenRight){
//    int maxLen = lenRight;
//    int i,k,found;
//    for (i=lenLeft-1;i>=0;i--){
//        found = 0;
//        for (k=0;k<lenRight;k++){
//            if (s[k+indexRight]==s[i+indexLeft]){
//                found = 1;
//                break;
//            }
//        }
//        if (found){
//            break;
//        } else {
//            maxLen ++;
//        }
//    }
//    return maxLen;
//}

//int imax(int a, int b){
//    if (a > b){
//        return a;
//    }
//    return b;
//}

//int mergeLongest(char* s, int indexLeft,int lenLeft, int indexRight, int lenRight){
//    int len1 = mergeLongestRightToLeft(s,indexLeft,lenLeft,indexRight,lenRight);
//    int len2 = mergeLongestLeftToRight(s,indexLeft,lenLeft,indexRight,lenRight);


//    return imax(len1,len2);
//}

////for debug
//char *buffer=NULL;

//int lengthOfLongestSubstringHelper(char* s, int index, int len){


//    if (len<=1){
//        return len;
//    }
//    int halfLen = len / 2;

//    int leftLen = lengthOfLongestSubstringHelper(s, index,halfLen);
//    int rightLen = lengthOfLongestSubstringHelper(s,index+halfLen,len - halfLen);



//    //right end of left part
//    int maxLenOfRightEnd = rightLongestSubString(s, index, halfLen);
//    //left end of right part
//    int maxLenOfLeftEnd =  leftLongestSubString(s,index+halfLen,len - halfLen);
//    int maxLenMiddle = mergeLongest(s,index+halfLen-maxLenOfRightEnd,maxLenOfRightEnd,index+halfLen,maxLenOfLeftEnd);

//    memcpy(buffer,s+index,len);
//    buffer[len]=0;
//    printf("str=%s leftLen=%d rightLen=%d maxLenOfRightEnd=%d  maxLenOfLeftEnd=%d maxLenMiddle=%d \n",
//           buffer, leftLen, rightLen, maxLenOfRightEnd, maxLenOfLeftEnd, maxLenMiddle);
//    return imax( imax(leftLen,rightLen), maxLenMiddle);

//}

//int lengthOfLongestSubstring(char* s) {
//    buffer = (char*)malloc(strlen(s)+1);
//    int len = lengthOfLongestSubstringHelper(s,0,strlen(s));
//    free(buffer);
//    return len;
//}

int lengthOfLongestSubstring(char* s) {
    int total = strlen(s);
    int bottom=0;
    int top=1;
    if (total <= 1){
        return  total;
    }
    int next;
    int found;

    int curLen=top-bottom;
    int maxLen=curLen;
    int i;
    for (;bottom <= top && top < total;){
        found = 0;
        for ( i=bottom;i<top;i++){
            if (s[i]==s[top]){
                found = 1;
                break;
            }
        }
        if (found){
            curLen = top - bottom;
            if (curLen>maxLen){
                maxLen = curLen;
            }
            bottom ++;
            top = bottom+1;
        } else {
            top ++;
        }
    }
    curLen = top - bottom;
    if (curLen>maxLen){
        maxLen = curLen;
    }
    return maxLen;


}

void testLongSubStr(){

    assert(lengthOfLongestSubstring("abcabcc")==3);
    assert(lengthOfLongestSubstring("bdb")==2);
    assert(lengthOfLongestSubstring("abcb")==3);
    assert(lengthOfLongestSubstring("bziuwnklhqzrxnb")==11);
}

#endif // LONGSUBSTR

