//problem 23 of project euler 
use std::collections::BTreeMap;

fn divisors(num:u32)->Vec<u32> {
    let mut v:Vec<u32> = Vec::new(); 
    for i in 1..(num / 2+1) {
        if num % i == 0 {
            v.push(i); 
        }
    }
    v
}

fn sum(v: &Vec<u32>) -> u32 {
    v.iter().fold(0,|acc,n| acc + n ) 
}

fn is_abundant(num:u32)->bool {
    sum(&divisors(num)) > num 
}

const LIMIT:u32 = 28123; 

fn abundant_nums() -> Vec<u32> {
    let mut v:Vec<u32> = Vec::new(); 
    for i in 1..(LIMIT+1) {
        if is_abundant(i) {
            v.push(i); 
        }
    }
    v 
}

fn all_sums(v:&Vec<u32>) -> BTreeMap<u32,u32> {
    let mut map = BTreeMap::new(); 
    for i in v.iter() {
        for k in v.iter() {
            let sum = i + k; 
            if sum <= LIMIT { 
                map.insert(i+k,i+k); 
            }    
        }
    }
    map
}






fn main() {
    
    let ab_nums = abundant_nums();
    println!("len num={}",ab_nums.len()); 
    let a_sums = all_sums(&ab_nums); 
    println!("len sum={}",a_sums.len());

    let mut sum:u32 = 0;

    for i in 1..(LIMIT+1) {
        if !a_sums.contains_key(&i) {
            sum += i; 
        }
    } 

    println!("result={}",sum); 
}


