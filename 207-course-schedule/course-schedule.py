from collections import deque
class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        #need to create an adjacency list for each element where we have the number of classes that require b as a prereq
        indeg = [0] * numCourses
        graph = defaultdict(list)
        for x,y in prerequisites:
            graph[y].append(x)
            indeg[x] += 1
        q = deque()
        for i in range(0, numCourses):
            if indeg[i] == 0:
                q.append(i)
        numSeen = 0
        while q:
            u = q.popleft()
            numSeen += 1
            for course in graph[u]:
                indeg[course] -=1
                if indeg[course] == 0:
                    q.append(course)
        return numCourses == numSeen

    

        
        
        
        