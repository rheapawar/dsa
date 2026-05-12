class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(const auto& x : prerequisites){
            adj[x[1]].push_back(x[0]);
        }

        vector<bool> v(numCourses, false);
        vector<bool> p(numCourses, false);

        for(int i = 0; i < numCourses; ++i){
            if(!v[i]){
                if (helper(i, v, p, adj)) return false;

            }
        }
        return true;
    }

    bool helper(int i, vector<bool> &v, vector<bool> &p, const vector<vector<int>> &adj){
        v[i] = true;
        p[i] = true;
        for(auto x : adj[i]){
            if(!v[x]){
                if(helper(x, v, p, adj)) return true;
            }
            else if(p[x]){
                return true;
            }
        }
        p[i] = false;
        return false;
    }
};