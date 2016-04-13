//problem 27 of project euler 

fn main() {
    println!("{} is prime {}",4,is_prime(4)); 
    println!("{} is prime {}",7,is_prime(7)); 
    println!("{} is prime {}",3,is_prime(3)); 
    println!("{} is prime {}",2,is_prime(2)); 
    println!("{} is prime {}",9,is_prime(9)); 
    println!("{} is prime {}",31,is_prime(31)); 

    max_consecutive_primes(); 
}

fn is_prime(n:i32)->bool {
    assert!(n>=2); 
    let upper :i32 =  (n as f64).sqrt() as i32; 

    for i in 2..(upper+1) {
        let remainder = n % i; 
        if remainder == 0 {
            return false; 
        }
    }

    true 
}

fn formula(n:i32,a:i32,b:i32)->i32 {
    n * n + n * a + b 
}

fn consecutive_num_primes(a:i32,b:i32)->i32 {
    let mut n = 0; 
    for i in 0.. {
        let num :i32 = formula(i,a,b); 
        if (num <2) || (!is_prime(num)) {
            break; 
        }
        n += 1; 
    }

    n 
}

fn max_consecutive_primes(){
    let mut max_n:i32 = 0; 
    let mut max_a:i32 ; 
    let mut max_b:i32 ; 
    for a in -1000..1000 {
        for b in -1000..1000 {
            let n=consecutive_num_primes(a,b); 
            if n > max_n {
                max_n = n; 
                max_a = a; 
                max_b = b; 
                println!("n={} a={} b={} a*b={}",max_n,max_a,max_b,max_a*max_b);
            }
        }
    } 
}


