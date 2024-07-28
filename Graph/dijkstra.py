import networkx as nx

graph = [
    [0,50,float('inf'),40,25,10],
    [50,0,15,20,float('inf'),25],
    [float('inf'),15,0,10,20,float('inf')],
    [40,20,10,0,10,25],
    [25,float('inf'),20,10,0,55],
    [10,25,float('inf'),25,55,0]
]

if __name__ =='__main__':
    path_cost = [0,50,float('inf'),40,25,10] # 只要求c1到其他的最短路径，一个list就行了

    # 遍历矩阵
    for i in range(1,6):
        for j in range(1,6):
            path_cost[j] = min(path_cost[j],graph[i][j]+path_cost[i])

    print(path_cost)

    # 调库验证一下
    G = nx.DiGraph()
    for i in range(len(graph)):
        for j in range(len(graph)):
            if graph[i][j] != float('inf'):
                G.add_edge(i, j, weight=graph[i][j])

    # 使用Dijkstra算法求解最短路径
    shortest_paths = nx.single_source_dijkstra(G, source=0)[0]

    print("第一个顶点到其他顶点的最短路径：", shortest_paths)


