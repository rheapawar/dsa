from collections import deque
class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
        graph = defaultdict(list)
        indeg = [0]*numCourses
        for x,y in prerequisites:
            graph[y].append(x)
            indeg[x] += 1
        q = deque()
        for i in range(0, numCourses):
            if indeg[i] == 0:
                q.append(i)
        numSeen = 0
        schedule = []
        while q:
            u = q.popleft()
            schedule.append(u)
            numSeen += 1
            for v in graph[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    q.append(v)
        if numSeen == numCourses:
            return schedule
        else:
            return []