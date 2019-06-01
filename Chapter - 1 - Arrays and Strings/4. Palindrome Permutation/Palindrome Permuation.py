def check_palindrome_permutation(str):
	freq_char={}
	count=0
	str=str.replace(' ','')
	
	for i in str:
		if i in freq_char:
			freq_char[i] += 1
		else:
			freq_char[i] =1
	for i in freq_char:
		if freq_char[i]%2==1:
			count=count+1
		if count>2:
			return False
	return True


str1=input("Enter the string")
print(check_palindrome_permutation(str1))
