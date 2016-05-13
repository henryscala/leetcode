//problem 31 of project euler 
//coin sums 

const LEN : usize = 8; 
const COINS :[u8;LEN]=[200,100,50,20,10,5,2,1]; 
const MAX :u8= 200; 


fn sum(ary:&[u8])->bool{
	let mut s:usize = 0; 
	for i in 0..ary.len() {
		s += ((ary[i] as usize) * (COINS[i] as usize)) as usize; 
		if s > MAX as usize{
			return false; 
		}
	}
	if s == (MAX as usize ) {
		true
	} else {
		false
	}
	
}

fn increase(ary:&mut [u8])->bool{
	let mut index :usize = 0; 
	
	loop {
		let max = MAX / COINS[index]; 
		if ary[index] < max {
			ary[index]+=1;
			return true; //able to continue 
		} else {
			if index +1 >= ary.len(){
				return false; 
			}
			ary[index]=0;
			index += 1; 
		}
	}	
}

fn main (){
	let mut num_coins:[u8;LEN]=[0;LEN]; 

	
	let mut total :usize = 0; 



	loop {
		let s = sum(&num_coins); 

		if s  {
			total += 1; 
			if total % 500 == 0 {println!("total reaches={}", total)};
		}
		let go_on=increase(&mut num_coins);
		if !go_on {break;}
		
		
		
	}
	
	println!("total={}",total);

	

}



