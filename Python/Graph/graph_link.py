#!/usr/bin/python3
# @file:  graph_link.py
# @brief: 图的邻接链表表示，和简易操作
# @date:  2019/5/13
# @author: luhao

class Node():
    '''
    定义节点: i是点的序列，nex是指向下一个邻接点的指针
    '''
    def __init__(self,name,nex):
        self.name = name
        self.nex = nex


class Graph():
    '''
    无向图，点下标从0开始计
    '''
    def __init__(self,n):
        # 声明一个有n个点的图G
        self.n = n # |V|点数
        self.G = [Node(i,None) for i in range(n)] # 一个存放所有链表头部的数组

    def add(self,x,y):
        # 添加一条(x,y)的无向边
        p = self.G[x]
        while p.nex and p.name!=y:
            p = p.nex
        p.nex = Node(y,None)
    
        p = self.G[y]
        while p.nex and p.name!=x:
            p = p.nex
        p.nex = Node(x,None)

    def remove(self,x,y):
        # 删除一条(x,y)的无向边
        p = self.G[x]
        while p.nex.name!=y:
            p = p.nex
        p.nex = p.nex.nex

        p = self.G[y]
        while p.nex.name!=x:
            p = p.nex
        p.nex = p.nex.nex

    def neighbour(self,x):
        # 返回与x邻接的点
        # rtype: 列表
        ans = []
        p = self.G[x].nex
        while p:
            ans.append(p)
            p = p.nex
        return ans

    def isEdge(self,x,y):
        # 判断点x,y是否邻接
        p = self.G[x]
        while p:
            if p.name==y:
                return True
            p = p.nex
        return False


if __name__ == "__main__":
    G = Graph(3)
    G.add(0,1)
    G.add(0,2)
    G.add(1,2)
    for i in G.neighbour(0):
        print (i.name)
