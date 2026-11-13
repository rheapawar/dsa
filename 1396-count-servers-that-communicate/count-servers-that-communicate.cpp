class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        /*oh wait u can go thru every row and count the number of servers in that row, if its greater than 1, than the total number there would be that number of servers, */
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rows(m);
        vector<int> cols(n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        //calculate the row and col totals and then once you have these, loop over the board again - if the row total or col total is greater than 1, then you can count all the elements in the row and col - but need to readjust for overcounting. wait when looping over the board again, if the row total and the col total are both greater than 1, just add it to the total once OH OKAY THAT SHOULD WORK
        int connected = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) connected++;
            }
        }
        return connected;
    }
};