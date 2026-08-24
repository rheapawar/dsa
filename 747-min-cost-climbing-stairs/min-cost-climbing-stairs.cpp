class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    /*
    min cost to reach each step is the min cost of that step
    min cost to reach the third step is the min cost of the first and the second step
    min cost to reach the fourth step is the 
    */
    int s = cost.size() + 1;
    vector<int> steps(s);
    steps[0] = 0;
    steps[1] = 0;
    for(int i = 2; i < s; i++){
        steps[i] = min(cost[i-1] + steps[i-1], cost[i-2] + steps[i-2]);
    }
    return steps[s-1];
    }
};