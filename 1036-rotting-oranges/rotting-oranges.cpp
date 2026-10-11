class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*okay so traverse over initial array, when u see -1, then and oh use a queue bc then u will know what minute u are on when queue reaches loop of initial*/
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        bool ones = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1) ones = true;
            }
        }
      
        int min = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x > 0 && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    q.push({x-1, y});
                }
                if(x < m-1 && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    q.push({x+1, y});
                }
                if(y > 0 && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    q.push({x, y-1});
                }
                if(y < n-1 && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    q.push({x, y+1});
                }   
            }
            if(!q.empty()) min++;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
      
    return min;
}
};