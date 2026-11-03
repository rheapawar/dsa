from collections import defaultdict
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        # general idea is to find a path between the elements, if it is the reciprocal of an existing edge do 1/edge otherwise need to try and find a path between. make a graph of all the edges and see if u can traverse thru the graph to find a path - would need to do a dfs on all the nodes from a starting transaction, make sure the graph is dual sided
        # how to prevent from falling into a loop with the graph???

        graph = defaultdict(dict)
        ans = []
        for i, (x,y) in enumerate(equations):
            graph[x][y] = values[i]
            graph[y][x] = 1/values[i]
        def dfs(start, end, product, visited):
            if start == end: 
                return product
            visited.add(start)
            for v, w in graph[start].items():
                if v not in visited:
                    res = dfs(v, end, product*w, visited)
                    if res != -1:
                        return res
            return -1
        
        for (x,y) in queries:
            if x not in graph or y not in graph:
                ans.append(-1.0)
            else:
                ans.append(dfs(x,y, 1.0, set()))
        return ans