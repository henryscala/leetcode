//problem 25 of project euler 
use std::ops::Add; 
use std::ops::Mul;
use std::fmt;

#[derive( Clone)]
struct  BigNum{
    val:String, 
}

impl fmt::Display for BigNum{
    fn  fmt (&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{}", self.val)
    }
}

impl   BigNum{
     fn   len(&self)->usize {
        self.val.len()
    }
}

fn is_zero(num:&BigNum) -> bool {
    if num.val.len() == 0 {
    	return true; 
    }
    
    let bs = num.val.as_bytes();
    for i in 0..num.val.len() {
    	if bs[i] != 0x30 {
    		return false; 
    	}
    }
    
    true 
    
}

//multiply num by 10 
fn mul10(num:&BigNum)->BigNum {
    if is_zero(num) {
    	return BigNum{val:"0".to_string()}; 
    } 
    
    let s:String=String::from(num.val.as_str()) +"0"; 
    BigNum{val:s} 
}

fn mul_digit(num:&BigNum, digit:u8)->BigNum {
	if is_zero(num) {
  	return BigNum{val:"0".to_string()}; 
  } 
  
  let mut i : usize = 0; 
  let mut carry: u8 = 0; 
  let mut result:String=String::new(); 
  let len:usize = num.len(); 
  let bytes:&[u8] = num.val.as_bytes();
  
  while i< len {
  	let digit_char = bytes[len-i-1]; 
  	let digit1 = digit_char - 0x30; 
  	let sum = digit1 * digit + carry; 
  	carry = sum / 10;  
    let digit1 = sum % 10; 
    
    let mut digit_str:String = String::new(); 
    digit_str.push( (digit1 + 0x30) as u8 as char ); 
    result = digit_str + &result;  
    i += 1; 
  }
  if carry > 0 {
    let mut digit_str:String = String::new(); 
    digit_str.push( (carry + 0x30) as u8 as char ); 
    result = digit_str + &result;  

  }
  
  BigNum{val:result}
  
} 




impl Add for BigNum  {
    type Output = BigNum;

    fn add(self, other: BigNum) -> BigNum {
        let  val_min:String ; 
        let  val_max:String ; 
        let  len_min ; 
        let  len_max ; 
        
        if self.len() < other.len() {
            len_min = self.len();
            len_max = other.len(); 
            val_max=other.val; 
            val_min = self.val; 
        } else {
            len_min = other.len(); 
            len_max = self.len(); 
            val_max=self.val; 
            val_min = other.val; 
            
        }

        let mut i : usize = 0; 
        let mut carry: u8 = 0; 
        let mut result:String=String::new(); 
        while i<len_min {
            let digit_char1 = val_min.as_bytes()[len_min-i-1]; 
            let digit_char2 = val_max.as_bytes()[len_max-i-1]; 
            let digit1 = digit_char1  - 0x30; 
            let digit2 = digit_char2  - 0x30; 
            let sum = digit1 + digit2 + carry ; 

            carry = sum / 10;  
            let digit = sum % 10; 
            let mut digit_str:String = String::new(); 
            digit_str.push( (digit + 0x30) as u8 as char ); 
            result = digit_str + &result;  
            i += 1; 
        }

        while i<len_max {
            let digit_char2 = val_max.as_bytes()[len_max-i-1]; 
            let digit2 = digit_char2 - 0x30; 
            let sum = digit2 + carry ; 

            carry = sum / 10;  
            let digit = sum % 10; 
            let mut digit_str:String = String::new(); 
            digit_str.push( (digit + 0x30) as u8 as char ); 
            result = digit_str + &result; 
            i += 1; 
        }

        if carry > 0 {
            let mut digit_str:String = String::new(); 
            digit_str.push( (carry + 0x30) as u8 as char ); 
            result = digit_str + &result; 

        } 

        
        BigNum { val: result}
    }
}

impl Mul for BigNum {
    type Output = BigNum;

    fn mul(self, other: BigNum) -> BigNum {
        if is_zero(&self) || is_zero(&other) {
            return BigNum{val:"0".to_string()}; 
        } 
			  
        let len=other.len(); 
        let mut i:usize = 0; 
        let bytes = other.val.as_bytes(); 
        let mut result = BigNum{val:"0".to_string()}; 
        let mut curr = BigNum{val:String::from(self.val.as_str())}; 
        while i < len {
            let digit_char = bytes[len-i-1]; 
            let digit1 = digit_char - 0x30; 
  		    
            if i != 0 {
                curr = mul10(&curr); 
            }
            result = result + mul_digit(&curr,digit1);
  			//to do , mul10 and mul this digit 
  				
			i+=1; 
        }

        result 
			  
    }
}

fn fibonacci() {
    let mut a = BigNum { val: "1".to_string() }; 
    let mut b = BigNum { val: "1".to_string() }; 
    let mut index:usize = 0; 
    let mut max_len:usize = 0;
    loop {
        index += 1; 
        if a.len() > max_len {
            max_len = a.len(); 
            println!("reach to len {}",max_len);
        }
        if a.len() == 1000 {
            println!("the 1000 digit fibnacci number's index is {}", index);
            break; 
        }

        //println!("a={}",a);
        //println!("b={}",b);
        //println!("b.clone={}",b.clone());
        let c = a + b.clone(); 
        //println!("c={}",c);
        a=b;
        //println!("a={}",a);
        b=c; 

        //println!("b={}",b);
        //println!("======="); 
        //if index == 5 { break; }  
    }

}


fn main() {
    let b = BigNum { val : "123".to_string() }; 
    println!("{}",b); 
    println!("{}",b.len()); 

    let b1 = BigNum { val: "789".to_string() }; 

    let b2 = b + b1; 
    println!("{}",b2); 
    println!("{}",b2.len()); 

    let b3 = BigNum { val : "19".to_string() }; 
    let b4 = BigNum { val : "19".to_string() }; 

    let b5 = b3 * b4; 
    println!("{}",b5); 

    fibonacci(); 
}

