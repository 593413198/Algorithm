#!/usr/bin/python3
# @brief:  队列的python实现
# @date:   2019,5,5
# @author: luhao

class Queue(object):
    def __init__(self):
        self.Q = []

    def isEmpty(self):
        return True if self.Q==[] else False
    
    def size(self):
        return len(self.Q)

    def push(self,x):
        self.Q.append(x)

    def first(self):
        return self.Q[0]

    def pop(self):
        return self.Q.pop(0)

    def show(self):
        # 打印队列中所有元素
        print (self.Q)

if __name__ == "__main__":
    Q = Queue()
    Q.push(1)
    Q.push(2)
    Q.push(3)
    Q.pop()
    print (Q.first())
    Q.show()
