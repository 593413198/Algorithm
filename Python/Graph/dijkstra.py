#!/usr/bin/python3
# @file:  dijkstra.py
# @brief: dijkstra算法求单源最短路径
# @date:  2019/5/14
# @author: luhao

class Graph():
    '''
    无向图，点下标从0开始计，边权重默认是1
    G[x][y] = 1 存在边xy ; G[x][y] = 0 不存在边xy
    '''
    def __init__(self,n):
        # 声明一个有n个点的图G
        self.n = n # |V|点数
        self.node = [i for i in range(n)] # 所有点
        self.G = [[0]*n for i in range(n)] # 邻接矩阵
        self.d = [0]*n  # 记录宽搜中每个点到起点的距离
        self.order = [] # 记录深搜的顺序

    def add(self,x,y,w=0):
        # 添加一条(x,y)的无向边
        # 不输入边权重的情况默认为1
        self.G[x][y] = 1 if not w else w
        self.G[y][x] = 1 if not w else w

    def remove(self,x,y):
        # 删除一条(x,y)的无向边
        self.G[x][y] = 0
        self.G[y][x] = 0

    def neighbour(self,x):
        # 返回与x邻接的点
        # rtype: 列表
        ans = []
        for i in range(self.n):
            if self.G[x][i]==1:
                ans.append(i)
        return ans
            
    def isEdge(self,x,y):
        # 判断点x,y是否邻接
        return self.G[x][y]

    def BFS(self,x):
        # 从点x开始宽搜
        vis = [0]*self.n # 记录节点是否搜索过
        Q = [x]
        while Q:
            v = Q.pop(0)
            vis[v] = 1
            for i in self.neighbour(v):
                if not vis[i]:
                    Q.append(i)
                    self.d[i] = self.d[v] + 1
                    vis[i] = 1

    def show(self,x):
        for i in self.neighbour[x]:
            if not vis[i]:
                print (i)

    
    def DFS(self,x):
        '''
        先从给定起点不回头地往下搜；接着随便找图中还没有搜索的点，分别执行dfs即可
        '''
        vis = [0]*self.n  # 初始化vis
        def dfs(node):
            vis[node] = 1
            self.order.append(node)
            for i in self.neighbour(node):
                 if not vis[i]:
                    dfs(i)
        dfs(x)
        for i in self.node:
            if not vis[i]:
                dfs(i)
        

if __name__ == "__main__":
    G = Graph(5)
    G.add(0,1,4)
    G.add(0,3,2)
    G.add(1,2,4)
    G.add(1,3,1)
    G.add(2,3,1)
    G.add(2,4,3)
    G.add(3,4,7)
    G.BFS(0)
    print (G.d)
    G.DFS(0)
    print (G.order)

