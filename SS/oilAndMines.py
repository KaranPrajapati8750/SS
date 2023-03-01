# Python3 code to minimize the difference 
# between the highest and lowest value containing company 

# This function constructs the solution array 
# recursively and returns the difference 
# between the highest and lowest value. 
def func(solArr, arr, index, n): 
	
	# If the values have been distributed, 
	# compute the difference 
	if n == 0: 
		for i in range(len(solArr)-1): 
			solArr[i] = solArr[i] - solArr[i + 1] 
			
		return max(solArr) - min(solArr) 
		
	else: 
		
		# solArr can be constructed even if we 
		# don't include the current value 
		if index >= n: 
			return min(func(solArr[:] + [arr[index]], arr, index-1, n-1), 
					func(solArr[:], arr, index-1, n)) 
		
		# solArr can't be constructed hence 
		# we have to include the current value	 
		else: 
			return func(solArr[:] + [arr[index]], arr, index-1, n-1) 
			
n = 2
arr = [1, 34, 5, 7,3 ,21, 90,81, 32,4,23,42,84,11,29] 

# Construct array such that value at each index 
# contains the sum of current and all previous 
# values in the array. 
for i in range(1, len(arr)): 
	arr[i] += arr[i-1] 

# Include the last value of 
# the array in our solution array. 
solArr = [arr[-1]] 
	
print(func(solArr[:], arr, len(arr)-2, n-1)) 
