object Solution {
    def uniquePaths(m: Int, n: Int): Int = {
        combination(m-1+n-1,n-1)
    }
    def combination(m:Int,n:Int):Int = {
      val num = factorial(m) 
      val denom1 = factorial(n) 
      val denom2 = factorial(m-n)
      val res :BigInt = num/denom1/denom2 
      return res.toInt
    }
    
    def factorial(n:Int):BigInt = {
      var f:BigInt = BigInt(1); 
      for ( i <- 2 to n) {
        f *= i; 
      }
      f 
    }
    
}

object First extends App {
   
  
  
  println(Solution.uniquePaths(7, 3))
}