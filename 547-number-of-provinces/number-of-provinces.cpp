#include <numeric>
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<int> found(isConnected.size());
        for(int i = 0; i < found.size(); i++){
            if(found[i] == 0){
                count++;
                helper(isConnected, i, found);
            }
        }
        return count;
    }

    void helper(vector<vector<int>> &isConnected, int x, vector<int> &found){
        found[x] = 1;
        for(int i = 0; i<isConnected[x].size(); ++i){
            if(isConnected[x][i] == 1 && found[i] == 0){
                helper(isConnected, i, found);
            }
        }
    }
};