class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>> &grid, int i, int j){
        stack<pair<int,int>> s;
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = '0';
        s.push({i,j});
        while(!s.empty()){
            int x = s.top().first;
            int y = s.top().second;
            s.pop();
            if (x > 0 && grid[x-1][y] == '1') {
                grid[x-1][y] = '0';
                s.push({x-1, y});
            }
            if (x < m-1 && grid[x+1][y] == '1') {
                grid[x+1][y] = '0';
                s.push({x+1, y});
            }
            if (y > 0 && grid[x][y-1] == '1') {
                grid[x][y-1] = '0';
                s.push({x, y-1});
            }
            if (y < n-1 && grid[x][y+1] == '1') {
                grid[x][y+1] = '0';
                s.push({x, y+1});
            }

        }
    }
};