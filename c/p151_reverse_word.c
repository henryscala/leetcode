#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
/*problem 151 of leetcode*/ 
void reverseString(char *s,int indexLower, int indexUpper ){
    indexUpper--; 
    for(;indexLower<indexUpper;indexLower++,indexUpper--){
        if (s[indexLower] != s[indexUpper]) {
            char t; 
            t=s[indexLower]; 
            s[indexLower] = s[indexUpper]; 
            s[indexUpper] = t; 
        }
    }
} 

int reduceSpaces(char *s, int len){
    int iSpaceBegin=-1;
    int i;
    int index = 0; 
    for (i=0;i<len;i++){
        if (s[i] == ' '){
            if (iSpaceBegin < 0){
                iSpaceBegin = i; 
            } 
        } else {
            if (iSpaceBegin >= 0){
                s[index++]=' ';
                s[index++]=s[i]; 
                iSpaceBegin = -1; 
            } else {
                s[index++]=s[i]; 
            }
        }
    }
    s[index]='\0'; 
    return index; 
} 

int trimString(char *s, int len){
    int newLen = len; 
    int i; 
    int numLeadingSpaces=0; 
    for (i=len-1;i>=0;i--){
        if (s[i] == ' ' || s[i] == '\t'){
            newLen--;
        } else {
            break; 
        }
    }
    for (i=0;i<newLen;i++) {
        if (s[i] == ' ' || s[i] == '\t'){
            numLeadingSpaces++;
        } else {
            break; 
        } 
    } 
    newLen -= numLeadingSpaces; 
    for (i=0;i<newLen && numLeadingSpaces;i++){
        s[i]=s[i+numLeadingSpaces]; 
    }
    s[newLen] = '\0'; 
    return newLen; 
} 

void reverseWords(char *s) {
    int len = strlen(s); 
    int iWordBegin,i; 
    len = trimString(s,len); 
    len = reduceSpaces(s,len); 
    reverseString(s,0,len); 
    if (len <= 1) return;  
    iWordBegin = 0; 
    for(i=0;i<len;i++){
        if (s[i] == ' '){
            reverseString(s,iWordBegin,i);
            iWordBegin = i+1;
        } 
    }
    if(i>iWordBegin){
        reverseString(s,iWordBegin,i);
    }
}

int main() {
    char a[] =" a quick     fox     jump over a dog "; 
    reverseWords(a);
    printf("|%s|\n",a); 
    return 0; 
}

