# def dec(fun):
#     def inner(*args,**kwargs):
#         return fun(*args,**kwargs)
#
#     return inner
# @dec
# def add(x,y):
#     print("x+y",x+y)
#
# add(1,2)
#
# def f():
#     i=0
#     while(i<3):
#         yield i
#         i=i+1
#
# def fyn():
#     g=f()
#     while(True):
#         x=next(g)
#         print(x)
#
# #fyn()
#
#
# class xx:
#     def __init__(self):
#         self.count=0
#     def decor(self,fun):
#         def inner(n):
#             fun(n)
#             self.count+=1
#             print(self.count)
#         return inner
# x=xx()
#
#
# @x.decor
# def fib(n):
#     if(n<=2):
#         return 1
#     return fib(n-1)+fib(n-2)
#
#
# fib(3)

import time
def count_calls(skip_recursion=True):
    def inner(func):
        func.called = False
        def inner1(*args,**kwargs):
            if skip_recursion and func.called: return func(*args,**kwargs)
            else:
                if hasattr(func, 'count'):
                    func.count += 1
                else:
                    setattr(func, 'count', 1)
                setattr(inner1, 'count', func.count)
                func.called = True
                start = time.time()
                result = func(*args,**kwargs)
                end = time.time()

                time_cal=end-start
            #    print("start",start,"end",end,"tim cal is :",time_cal)
                if hasattr(func, 'time'):
                    func.time=func.time+time_cal
                else:
                    setattr(func, 'time', time_cal)
                setattr(inner1, 'time', time_cal)


                func.called=False
                return result
        return inner1
    return inner


@count_calls(skip_recursion=False)
def fib(n):
    if n <= 0:
        raise ValueError("n <= 0")
    if n == 1 or n == 2:
        return 1
    return fib(n-1) + fib(n-2)
print(fib(5))
print(fib.count)
print(fib.time)

