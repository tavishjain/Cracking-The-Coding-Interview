def listify(str):
        lis=[]
        for i in str:
                lis.append(i)
        return lis

def replace_Spaces(str):
        new_str=listify(str)
        new_lis=[]
        for i in new_str:
                if i==' ':
                        i='%20'
                new_lis.append(i)
        return ''.join(new_lis)


user_string=input("Enter string to URLify")
print(replace_Spaces(user_string))
