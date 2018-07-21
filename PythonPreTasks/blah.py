def blah(func):
    def inner(*args,**kwargs):
        print( "Entered: " ,func.__name__,"with arguments",args,kwargs)
        res= func(*args,**kwargs)
        print(func.__name__,"returnd",res)
        return res
    return inner
@blah
def sum(a,b):
   return (a+b)
@blah
def sub(a,b):
    return a-b
print(sum(10,20))
print(sub(20,10))