class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int min = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                auto it = q.front();
                q.pop();
                int x = it.first;
                int y = it.second;
                if(x > 0 && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    q.push({x-1,y});
                }
                if(y > 0 && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    q.push({x,y-1});
                }
                if(y < grid[0].size()-1 && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    q.push({x,y+1});
                }
                if(x < grid.size() -1 && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    q.push({x+1,y}); 
                }
                
            }
            if(q.size() > 0)min++;
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1) return -1;
            }
        }
        return min;
    }

   
};