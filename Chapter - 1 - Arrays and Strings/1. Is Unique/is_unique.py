def is_unique(str):
	if len(str)>128:
		return False
	char_set=[None]*128
	for i in range(0,len(str)):
		ascii_char=ord(str[i])
		if char_set[ascii_char]:
			return False
		char_set[ascii_char]=True
	return True

print(is_unique("priyapp"))
