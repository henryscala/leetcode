//problem 29 of project euler 
//distinct powers 



const LEN:usize = 101;


type Factors = [usize;LEN] ; 




//n is less than or equal to 100 
fn factors(n:usize)->Factors {
	
	let mut result:Factors = [0;LEN];
	let mut n = n; 
	let mut i = 2; 
	while i <= n {
		if n % i == 0 {
			result[i] += 1; 
			n /= i; 
		} else {
			i += 1; 
		}
	}
	result 
}

fn power(n1:usize,n2:usize)->Factors{
	let mut fs = factors(n1); 
	println!("n1={} n2={} ",n1,n2);
	for i in 0..LEN{
		fs[i]*=n2; 
	}
	fs 
} 

fn equal (f1:&Factors,f2:&Factors)->bool{
	for i in 0..f1.len(){
		if f1[i] != f2[i] {
			return false; 
		}
	}
	true 
}

fn main (){
	let mut set:Vec<Factors> = Vec::new(); 

	for i in 2..(100+1) {
		for k in 2..(100+1) {
			let p=power(i,k);
			let mut found:bool = false; 
			for p2 in set.iter() {
				if equal(&p,&p2) {
					found = true; 
					break; 
				}
			}
			if !found {
				set.push(p); 
			}
		}
	}

	
	
	println!("{:?}",set.iter().count()); 
	
	

	
}



