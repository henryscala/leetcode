object Solution {
    def searchMatrix(matrix: Array[Array[Int]], target: Int): Boolean = {
        if (matrix.length > 0) {
          if (matrix(0).length > 0 ) {
            val numRow = matrix.length 
            val numCol = matrix(0).length 
            val totalElem = numCol * numRow 
            
            search(matrix,0,totalElem-1,numRow,numCol,target) 
          } else {
            false  
          }
        } else {
          false 
        }
        
    }
    
    def search(matrix: Array[Array[Int]],low:Int,up:Int,numRow:Int,numCol:Int,value:Int):Boolean = {
      if (low  > up) {
        false 
      } else {
        val mid:Int = (up + low)/2 
        val value2 = get(matrix,mid,numRow,numCol) 
        if (value2 == value){
          true 
        } else {
          if (value2 < value) {
            search(matrix, mid+1,up,numRow,numCol,value)
          } else {
            search(matrix, low,mid-1,numRow,numCol,value)
          }
        }
      }
    }
    
    def get(matrix: Array[Array[Int]],index:Int,numRow:Int,numCol:Int):Int = {
      val row:Int = index / numCol
      val col:Int = index % numCol
      matrix(row)(col) 
    }
}

object First extends App {
   
  
  
  
}