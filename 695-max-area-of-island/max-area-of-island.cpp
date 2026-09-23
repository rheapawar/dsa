class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    area = max(area, dfs(grid, i, j));
                }
            }
        }
        return area;
    }

    int dfs(vector<vector<int>> &grid, int i, int j){
        int area = 1;
        int m = grid.size();
        int n = grid[0].size();
    
        stack<pair<int, int>> s;
        grid[i][j] = 0;
        s.push({i,j});

        while(!s.empty()){
            auto [x,y] = s.top();
            s.pop();
            if(x > 0 && grid[x-1][y] == 1){
                area++;
                grid[x-1][y] = 0;
                s.push({x-1, y});
            }
            if(x < m - 1 && grid[x+1][y] == 1){
                area++;
                grid[x+1][y] = 0;
                s.push({x+1, y});
            }
            if(y > 0 && grid[x][y-1] == 1){
                area++;
                grid[x][y-1] = 0;
                s.push({x, y-1});
            }
            if(y < n - 1 && grid[x][y+1] == 1){
                area++;
                grid[x][y+1] = 0;
                s.push({x, y+1});
            }
        }
        return area;
    }
};