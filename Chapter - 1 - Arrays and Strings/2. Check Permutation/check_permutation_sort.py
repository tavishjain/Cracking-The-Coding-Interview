def listify(str):
	lis=[]
	for i in str:
		lis.append(i)
	return lis
def check_permutation(str1,str2):
	if len(str1)!=len(str2):
		return False

	if (listify(str1)).sort()==(listify(str2)).sort():
		return True
	else:
		return False

str1=input("Enter First String: ")
str2=input("Enter Second String: ")
print(check_permutation(str1,str2))

