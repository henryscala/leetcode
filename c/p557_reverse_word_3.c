#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
/*problem 557 of leetcode*/ 
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

char* reverseWords(char *s) {
    int len = strlen(s); 
    int iWordBegin,i; 
    if (len <= 1) return s;  
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
    return s;
}

int main() {
    char a[] ="a quick fox jump over a dog"; 
    reverseWords(a);
    printf("|%s|\n",a); 
    return 0; 
}

