//problem 22 of project euler 
use std::io; 
use std::io::Read; 

fn score(ith:u32,word:&str) ->u32 {
	const A_VAL:u32 = 'A' as u32;
	let mut val:u32 = 0; 
	for c in word.chars() {
		val += (c as u32) - A_VAL + 1;
	}
	ith * val 
} 

fn main() {
	let mut input = String::new(); 
	io::stdin().read_to_string(&mut input).expect("read failed"); 
	
	let v = &input.split(",").collect::<Vec<&str>>(); 
	let mut words:Vec<&str> = v.iter().map(|w| w.trim_matches('\"')).collect(); 
	words.sort(); 
	
	let mut total:u32 = 0; 
	for (i,&word) in words.iter().enumerate() {
		total += score((i+1) as u32,&word)
	}
	
	
	println!("total={}", total); 
	
	
}