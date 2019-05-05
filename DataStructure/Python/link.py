#!/usr/bin/python3
# @brief:  队列的python实现
# @date:   2019,5,5
# @author: luhao

'''
Link.isEmpty()  是否空链表
Link.size()     链表大小
Link.add(x)     链表尾部添加x
Link.remove()   链表尾部删除一个
Link.show()     打印链表
Link.reverse()  反转链表

'''

class Node(object):
    def __init__(self,name):
        self.name = name
        self.nex = None

class Link(object):
    def __init__(self):
        self.head = None
        self.tail = None
        self.len = 0

    def isEmpty(self):
        return self.len == 0

    def size(self):
        return self.len

    def add(self,x):
        p = Node(x)
        if self.isEmpty():
            self.head = p
            self.tail = p
        else:
            self.tail.nex = p
            self.tail = p
        self.len += 1

    def remove(self):
        if self.isEmpty():
            print("Error for Empty Link!")
            return
        p = self.head
        while p.nex != None and  p.nex != self.tail:
            p = p.nex
        p.nex = None
        self.tail = p
        self.len -= 1

    def show(self):
        if self.isEmpty():
            print ("Error for Empty Link!")
            return 
        p = self.head
        if self.len == 1:
            print (p.name)
            return 
        while p != self.tail:
            print (p.name,end="->")
            p = p.nex
        print (self.tail.name)

    def reverse(self):
        if self.len <= 1:
            return
        # length at least 2
        p = self.head
        while p.nex != None:
            tmp = p.nex
            p.nex = tmp.nex
            tmp.nex = self.head
            self.head = tmp
            if (p.nex == self.tail):
                self.tail = p

if __name__ == "__main__":
    L = Link()
    L.add(6)
    L.add(2)
    L.add(7)
    L.add(1)
    L.remove()
    L.show()
    L.reverse()
    L.show()


