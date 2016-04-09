//problem 26 of project euler 
fn div(numerator:usize, denominator:usize) -> (Vec<usize>,usize,bool) {
    let mut quotients:Vec<usize> = Vec::new();
    let mut nums :Vec<usize> = Vec::new(); 

    
    let mut remainder = numerator; 
    
    let mut index: usize=0; 
    let mut is_cycle=false; 

    while remainder != 0 {
        let num = remainder; 
        let index_exist = nums.iter().position(|&e| e == num ); 
        match index_exist {
            Some(i) => { 
                        is_cycle = true; 
                        index = i; 
                        break;

                        }
            None => {
                 
            }
        }

        
        let quotient = remainder / denominator; 
        remainder = remainder % denominator; 
        quotients.push(quotient);
        nums.push(num); 
        remainder = remainder * 10; 
    } 
     

    (quotients,index,is_cycle)

}

fn longest_cycle(){
    let mut longest:usize = 0; 
    let mut denominator:usize = 1; 
    let mut digits:Vec<usize> = Vec::new(); 

    for i in 1..1000 {
        let (v,index,cycle) = div(1,i); 
        if !cycle { continue; } 
        let cycle_len = v.len() - index; 
        if cycle_len > longest {
            longest = cycle_len; 
            digits = v; 
            denominator = i; 
        }
    }
    println!("longest cycle: 1/{}, {}, {:?}",denominator,longest,digits);
}


fn main() {
    let (v,i,cycle)=div(1,7); 
    println!("{:?}",v);
    println!("{}",i);
    println!("{}",cycle);

    let (v1,i1,cycle1)=div(1,8); 
    println!("{:?}",v1);
    println!("{}",i1);
    println!("{}",cycle1);

    let (v2,i2,cycle2)=div(1,6); 
    println!("{:?}",v2);
    println!("{}",i2);
    println!("{}",cycle2);

    longest_cycle(); 
}


