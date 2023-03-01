def fun(a,b):
    if(a<b):
        return fun(b,a)
    elif(b!=0):
        return(a * fun(a,b-1))
    else:
        return 0

print(fun(5,5))