//problem 28 of project euler 
//straight forward way, not smart way 
const LEN:usize = 1001;
const MAX:usize = LEN * LEN;   
type Matrix = [[usize;LEN];LEN] ; 
type Vector = (i32,i32); 

const CYCLE_VEC : [Vector;4] = [(1,0),(0,1),(-1,0),(0,-1)]; //right,down,left,up 

fn main (){
	let mut  matrix: Matrix = [[0;LEN];LEN]; 
	
	

	let half = (LEN / 2 ) as i32; 
	let center :Vector = (half,half); 
	matrix[center.1 as usize][center.0 as usize]=1; 
	let mut index:usize = 0; 

	let mut last_num:usize = 1;
	let mut pos :Vector = center.clone(); 
	while last_num < MAX {
		pos = extend_matrix(&mut matrix,last_num,pos,&center,&mut index); 
		last_num += 1; 
	}

	println!("final matrix:"); 
	out_matrix(&matrix); 

	println!("sum={}",diagnal_sum(&matrix)); 
}



fn extend_matrix(m:&mut Matrix,last_num:usize,last_pos:Vector,center:&Vector,cycle_index:&mut usize)->Vector{
	println!("handling {}",last_num); 
	//out_matrix(m); 
	//if last_num == MAX {
	//	return;
	//}
	let attempt_next_pos1 :Vector = add(&last_pos,&CYCLE_VEC[*cycle_index]); 
	let attempt_next_pos2 :Vector = add(&last_pos,&CYCLE_VEC[(*cycle_index+1) % 4]);
	let x1 = attempt_next_pos1.0 as usize; 
	let y1 = attempt_next_pos1.1 as usize; 
	let x2 = attempt_next_pos2.0 as usize; 
	let y2 = attempt_next_pos2.1 as usize; 
	let dist1 = distance(&attempt_next_pos1,center);
	let dist2 = distance(&attempt_next_pos2,center); 
	let new_pos:Vector; 

	if x1 >= LEN || y1 >= LEN {
		m[y2][x2] = last_num + 1 ;
		*cycle_index = (*cycle_index  + 1) % 4; 
		new_pos = attempt_next_pos2;
		
		return new_pos; 
	} 

	if x2 >= LEN || y2 >= LEN {
		m[y1][x1] = last_num + 1 ;
		new_pos = attempt_next_pos1;
		extend_matrix(m,last_num+1,new_pos,center,cycle_index);
		return new_pos; 
	}

	if dist1 == dist2 {
		if m[y1][x1] == 0 {
			m[y1][x1] = last_num + 1 ;
			new_pos = attempt_next_pos1;
		} else {
			m[y2][x2] = last_num + 1 ;
			*cycle_index = (*cycle_index  + 1) % 4; 
			new_pos = attempt_next_pos2;
		}
	} else {
		if dist1 < dist2 {
			if m[y1][x1] == 0 {
				m[y1][x1] = last_num + 1 ;
				new_pos = attempt_next_pos1;
			} else {
				m[y2][x2] = last_num + 1 ;
				*cycle_index = (*cycle_index  + 1) % 4; 
				new_pos = attempt_next_pos2;
			}
		} else {
			if m[y2][x2] == 0 {
				m[y2][x2] = last_num + 1 ;
				*cycle_index = (*cycle_index  + 1) % 4; 
				new_pos = attempt_next_pos2;
			} else {
				m[y1][x1] = last_num + 1 ;
				new_pos = attempt_next_pos1;
				
			}
		}
	}
	return new_pos; 
}

fn distance(v1:&Vector,v2:&Vector) -> usize {
	let mut x:i32 = v1.0 - v2.0; 
	let mut y:i32 = v1.1 - v2.1; 
	
	x=x.abs();
	y=y.abs(); 

	std::cmp::max(x,y) as usize 
	
}

fn add(v1:&Vector,v2:&Vector)->Vector {
	(v1.0+v2.0,v1.1+v2.1)
}

fn diagnal_sum(m:&Matrix)->usize{
	let mut sum:usize = 0;
	for i in 0..LEN {
		sum += m[i][i] + m[LEN-i-1][i];
	} 
	sum -= 1; 
	sum 
}

fn out_matrix(m:&Matrix){
	for row in 0..LEN {
		for col in 0..LEN {
			print!("{0:5}",m[row][col]);
		}
		println!("");
	}
	
}