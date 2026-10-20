class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*simply like kahns algorithm from course schedule 1 but instead of checking and incrementing visited nodes, you would want to build the path, start path can be any of the nodes with inDegree one to begin with*/

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(const auto &req : prerequisites){
            adj[req[1]].push_back(req[0]);
            indegree[req[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> path;
        path.reserve(numCourses);
        int visited = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            path.push_back(u);
            visited++;

            for(int v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }

        }
        return (visited == numCourses) ? path : vector<int>{};
        }
};