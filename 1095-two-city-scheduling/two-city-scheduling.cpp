class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> diff;
        int cost = 0;
        diff.reserve(costs.size());
        for(int i = 0; i < costs.size(); i++){
            cost+=costs[i][0];
            diff.push_back(costs[i][1] - costs[i][0]);
        }
        sort(diff.begin(), diff.end());
        for(int i = 0; i < diff.size()/2; i++){
            cost += diff[i];
        }
        return cost;
        
        
    }
};