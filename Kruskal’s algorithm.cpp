class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.edges = []

    def add_edge(self, u, v, weight):
        self.edges.append((weight, u, v))

    def find(self, parent, i):
        if parent[i] != i:
            parent[i] = self.find(parent, parent[i])
        return parent[i]

    def union(self, parent, rank, x, y):
        root_x = self.find(parent, x)
        root_y = self.find(parent, y)

        if rank[root_x] < rank[root_y]:
            parent[root_x] = root_y
        elif rank[root_x] > rank[root_y]:
            parent[root_y] = root_x
        else:
            parent[root_y] = root_x
            rank[root_x] += 1

    def kruskal(self):
        result = []
        self.edges.sort()

        parent = list(range(self.V))
        rank = [0] * self.V

        total_weight = 0

        for weight, u, v in self.edges:
            root_u = self.find(parent, u)
            root_v = self.find(parent, v)

            if root_u != root_v:
                result.append((u, v, weight))
                self.union(parent, rank, root_u, root_v)
                total_weight += weight

            if len(result) == self.V - 1:
                break

        print("Edges in Minimum Spanning Tree:")
        for u, v, weight in result:
            print(f"{u} - {v} : {weight}")

        print("Total Minimum Cost:", total_weight)

g = Graph(4)

g.add_edge(0, 1, 10)
g.add_edge(0, 2, 6)
g.add_edge(0, 3, 5)
g.add_edge(1, 3, 15)
g.add_edge(2, 3, 4)

g.kruskal()
