//problem 24 of project euler 
//using recursive way 
use std::cmp::Ordering;

fn fac(n:u64)->u64 {
    let mut product:u64 = 1;
    for i in 1..(n+1) {
        product *= i;
    }
    product 
}

fn permutation_num(n:u64,r:u64)->u64 {
    fac(n)/fac(n-r)
}

//end is exclusive 
fn permutation(start:u64,end:u64) -> Vec<Vec<u64>> {
    if start+1 == end {
        return vec![vec![start]];
    } else {
        let vec_vec = permutation (start+1,end);     
        return extend(&vec_vec,start); 
    }
}

fn extend(perms:&Vec<Vec<u64>>,elem:u64) -> Vec<Vec<u64>>{
    let mut rows: Vec<Vec<u64>>= Vec::new(); 

    

    for perm in perms {
        let new_rows = extend_perm(&perm,elem);
        rows.extend_from_slice(&new_rows);
    }
    rows 
}

fn compare(a:&Vec<u64>, b:&Vec<u64>)->Ordering {
    for (i,e) in a.iter().enumerate() {
        let e2=b[i]; 
        if e2>*e {
            return Ordering::Less; 
        } else if e2 < *e {
            return Ordering::Greater; 
        } else {
            continue; 
        }
    }
    Ordering::Equal 
}


fn extend_perm(perm:&Vec<u64>,elem:u64)->Vec<Vec<u64>> {
    let mut rows: Vec<Vec<u64>>= Vec::new(); 
    for i in 0 .. perm.len(){
        
        let mut row:Vec<u64> = Vec::new(); 
        for (idx,val) in perm.iter().enumerate() {
            if idx == i {
                row.push(elem); 
            }
            row.push(*val);
        }
        rows.push(row); 
    } 
    let mut row:Vec<u64> = Vec::new(); 
    row.extend_from_slice(perm); 
    row.push(elem); 
    rows.push(row); 
    rows 
}



fn main() {
    let r=fac(4);
    println!("fac4={}",r);
    let total = permutation_num(10,10);
    println!("total={}",total); 
    let mut vec_vec = permutation(0,10); 
    vec_vec.sort_by(compare); 

    for v in &vec_vec {
        for e in  v {
            print!("{}",e);
        }
        println!(""); 
    }

    println!("the 1000000th is :");

    for e in &vec_vec[1000000-1] {
        print!("{}",e);
    }
    println!(""); 
}



