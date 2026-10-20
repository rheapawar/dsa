class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*would the idea be to build out an adjacency list graph type thing and each time when u are inserting a prereq, check if the other elemnt has that one listed as well, do we need to check for interdependencies 
        kahns algo, first build adjacnecy list for each element, then check for cycle, toldthat courses are labeled 0 to numCourses -1 and total of numCourses */
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        for(const auto &req : prerequisites){
            adj[req[1]].push_back(req[0]);
            inDegree[req[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        int visited = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited++;
            for(int v : adj[curr]){
                inDegree[v]--;
                if(inDegree[v] == 0) q.push(v);
            }
        }
        return visited == numCourses;
        
    }
};