class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*traverse over the grid once, any rotten orange add to the queue and then once added, go over queue while not empty - check all surroundings and if it is a 1, change to rotten and then add it to the queue - need a way to distinguish between the levels for res tho
        
        could store as another variable but could also use a counter to when the current level ends
        */
        int res = 0;
        bool ones = false;
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) ones = true;
            }
        }
        if(!ones) return 0;
        
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x > 0 && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    q.push({x-1,y});
                }
                if(x < grid.size()-1 && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    q.push({x+1,y});
                }
                if(y > 0 && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    q.push({x, y-1});
                }
                if(y < grid[0].size()-1 && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    q.push({x, y+1});
                }
            }
            if(q.size() > 0) res++;
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }
       return res;
    }
};