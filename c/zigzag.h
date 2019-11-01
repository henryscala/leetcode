#ifndef ZIGZAG
#define ZIGZAG
#include <stdio.h>
#include <string.h>

int calcrow(int index, int numRows){
    if (numRows == 1){
        return 0;
    }
    int a = index % (2*numRows - 2);
    int row;
    if (a<=numRows-1){
        row = a;
    } else {
        row = 2 * numRows - 2 - a;
    }
    return row;
}

int calccolumn(int index, int numRows){
      if (numRows == 1){
          return index;
      }
      int rem = index % (2*numRows - 2);
      int div = index / (2*numRows - 2);
      int col;
      if (rem <= numRows -1){
          col = 0;
      } else {
          col = rem - numRows + 1;
      }
      return col + div * (numRows-1);
}

char *zigzagbuf;

char* convert(char* s, int numRows) {

    int size = strlen(s);
    zigzagbuf = (char*)malloc(size+1);
    memset(zigzagbuf,0,size+1);
    int maxColumnSize = calccolumn(size-1,numRows)+1+1;
    int *indices = (int*)malloc(numRows*sizeof(int));
    char **result = (char**)malloc(numRows*sizeof(char*));
    int i;
    for (i=0;i<numRows;i++){
        result[i] = (char*)malloc(maxColumnSize);
        memset(result[i],0,maxColumnSize);
    }
    memset(indices,0,numRows*sizeof(int));

    int row;

    for (i=0;i<size;i++){
        row = calcrow(i,numRows);
        result[row][indices[row]]=s[i];
        indices[row] ++;
    }

    for (i=0;i<numRows;i++){
        strcat(zigzagbuf,result[i]);
    }

    //free memories
    free(indices);
    for (i=0;i<numRows;i++){
        free(result[i]);
    }
    free(result);

    return zigzagbuf;
}

void testZigZag(){
    char* result=convert("PAYPALISHIRING", 3);
    assert(strcmp("PAHNAPLSIIGYIR",result) == 0);
}

#endif // ZIGZAG

