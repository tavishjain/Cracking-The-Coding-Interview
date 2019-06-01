def listify(str):
	lis=[]
	for i in str:
		lis.append(i)
	return lis

def check_permutation_sort(str1,str2):
	if len(str1)!=len(str2):
		return False

	if (listify(str1)).sort()==(listify(str2)).sort():
		return True
	else:
		return False

def check_permutation_count(str1,str2):
	if len(str1)!=len(str2):
		return False
	letters=[0]*128
	new_char=listify(str1)
	for i in new_char:
		letters[ord(i)]=1
	for i in range(0,len(str2)):
		val=ord(str2[i])
		letters[val]=letters[val]-1
		if letters[val]<0:
			return False
	return True

str1=input("Enter First String: ")
str2=input("Enter Second String: ")
print(check_permutation_sort(str1,str2))
print(check_permutation_count(str1,str2))
