//problem 30 of project euler 
//digit fifth power
//n digit number has a lower limit, which is 10^(n-1) , because the first digit is greater than 1  <-----first item 
//the sum of fifth power of the digits has a upper limit, which is n*10^5<10^6      <------second item 
//the first item grows fast than the second item. We only need to consider the numbers with at most 6 digits, 
//otherwise, there is not overlap between the first item and the second item 


fn nth_power_sum_of_digits(num:usize,n:usize)->usize {
	let mut num :usize= num; 
	let mut sum :usize= 0; 
	while num > 0 {
		let digit = num % 10;
		if digit > 0 {
			sum += digit.pow(n as u32); 
		}
		num = num / 10; 
	}
	sum 
}

fn main (){
	let mut total = 0; 
	let mut sum = 0; 
	for i in 10..((10 as usize).pow(6 as u32)) {
		let j = nth_power_sum_of_digits(i,5); 
		if i==j {
			println!("{}",i);
			sum += i; 
			total += 1; 
		}
	}

	println!("total={}",total);
	println!("sum={}",sum);
}



