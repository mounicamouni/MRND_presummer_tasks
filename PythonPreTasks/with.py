'''
class CtxMgr:
    def __init__(self,key):
        self.key=key
    def __enter__(self):
        print("Enter called")
        return self.key
    def __exit__(self, exc_type, exc_val, exc_tb):
        print("exit called ",exc_type,exc_val, exc_tb)
        return True
def test_contextMgr():
    with CtxMgr(2)as someobj:
        print("Value of someobj",someobj)
        raise ValueError("hello")
        print("In the body of with")

if __name__=="__main__":
    test_contextMgr()
'''

from contextlib import contextmanager
@contextmanager
def conMgr():
    print("Enterd contxmgr")
    try:
        yield 10
    finally:
        print("In exit")
        #return
        #raise StopIteration("form methos")
def test_contextMgr():
    with conMgr() as val:
        print("the return val is ",val)
        raise StopIteration("Hello")

def my_gen():
    yield 10
    raise StopIteration("end")

if __name__=="__main__":
    test_contextMgr()
   # gen=my_gen()
   # for x in gen:
    #    print("Got",x)