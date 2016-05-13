//problem 31 of project euler
//coin sums

const LEN : usize = 8;
const COINS :[u8;LEN]=[200,100,50,20,10,5,2,1];
const MAX :u8= 200;

//this method return the number of ways to give the changes.
//it is a recursive method.
//the strategy shall be divide and counquer(divide the task of size n to sub tasks of size n-1 and 1).
//it can be improved to use the dynamic programming strategy(store the intermediate result in a map and query it before calculation).
//My first way of try solving this issue is a brute-force(or enumerate) way, it does not work because it takes so long time.
fn f(index:usize,max:usize)->usize{
 let coin_value = COINS[index] as usize;
 if index == 0 {
  if max / coin_value > 0 && max % coin_value == 0 {
   return 1; //1 way
  } else {
   return 0; //no way
  }
 }

 if max == 0 {
  return 0;
 }
 //previous solutions + solutions only using the coins in index column
 let mut sum:usize = f(index - 1, max);
 if max / coin_value > 0 && max % coin_value == 0 {
  sum += 1;
 }
 let mut i:usize = 1;
 loop {
  let scale = i*coin_value ;
  if max > scale{
   let next_max = max-scale ;
   sum += f(index-1,next_max) ;
  } else {
   break;
  }
  i += 1;
 }
 sum

}

fn main (){
 let total = f(LEN-1,MAX as usize);
 println!("total={}",total);
}



