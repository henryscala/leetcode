



def search_col(matrix, numrow, numcol, col, target) 
  low = 0 
  high = numrow - 1 
  
  while low <= high  
    mid = (low + high) / 2
    if matrix[mid][col] == target 
      return true 
    end 
    if target < matrix[mid][col] 
      high = mid - 1 
    else 
      low = mid + 1 
    end
  end 
  return false 
end

def search_row(matrix, numrow,numcol,row, target) 
  low = 0 
  high = numcol -1 
  
  while low <= high  
    mid = (low + high) / 2
    if matrix[row][mid] == target 
      return true 
    end 
    if target < matrix[row][mid] 
      high = mid - 1 
    else 
      low = mid + 1 
    end
  end 
  return false 
end

# @param {Integer[][]} matrix
# @param {Integer} target
# @return {Boolean}
def search_matrix(matrix, target)
  numrow = matrix.length 
  return false if numrow <= 0 
  
  numcol = matrix[0].length 
  return false if numcol <= 0 

  row = 0 
  col = 0 
  while row < numrow && col < numcol  
    found = search_row(matrix,numrow,numcol,row,target) 
    if !found 
      found = search_col(matrix,numrow,numcol,col,target)
    end
    return true if found 
    row += 1 
    col += 1 
  end 
  return false 
end

m = [
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

puts search_matrix(m,5)
puts search_matrix(m,20)
