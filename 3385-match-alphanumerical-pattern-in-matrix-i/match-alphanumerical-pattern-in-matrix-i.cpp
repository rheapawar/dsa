class Solution {
public:
    vector<int> findPattern(vector<vector<int>>& board, vector<string>& pattern) {
        /*essentially moving window size/frame that is the size of pattern, nested for loop to look at all possible boards and then hashmap to track the assigned value of every letter from pattern - if all digits and letter match then return true
        
        each time a letter is assigned, conside th
        
        when traversing the loop, need to check every row and col but this is just starting position, to know each  need to have a counter to measure actual pattern size */
        int m = pattern.size();
        int n = pattern[0].size();
        for(int i = 0; i <= board.size() - pattern.size(); i++){
            for(int j = 0; j <= board[0].size() - pattern[0].size(); j++){
                int counter = 0;
                vector<int> map(26, -1);
                vector<int> rev(10, -1);
                for(int a = 0; a < m; a++){
                    for(int b = 0; b < n; b++){
                        int x = i + a;
                        int y = j + b;
                        char c = pattern[a][b];
                        int val = board[x][y];
                        if(isalpha(c)){
                            int index = c - 'a';
                            if (map[index] == -1 && rev[val] == -1){
                                map[index] = val;
                                rev[val] = index;
                                counter++;
                            }
                            else if(map[index] == val && rev[val] == index) counter++;
                        }
                        else if(c -'0' == val) counter++;
                    }
                }
                if(counter == m * n) return {i, j};
                
            }
        }
        return {-1,-1};
    }
};