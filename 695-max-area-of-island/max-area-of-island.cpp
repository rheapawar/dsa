class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = 0;
        int r = 0;
        for(int i = 0; i <grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) r = helper(grid, i, j);
                m = max(r,m);
            }
        }
        return m;
    }

    int helper(vector<vector<int>> &grid, int x, int y){
        int area = 1;
        grid[x][y] = -1;
        if(x > 0 && grid[x-1][y] == 1) area += helper(grid, x-1, y);
        if(x < grid.size() - 1 && grid[x+1][y] == 1) area += helper(grid, x+1, y);
        if(y > 0 && grid[x][y-1] == 1) area +=helper(grid, x, y-1);
        if(y < grid[0].size() - 1 && grid[x][y+1] == 1) area += helper(grid, x, y+1);
        return area;  
    }
};