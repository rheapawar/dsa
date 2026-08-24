class Solution {
public:
    int rob(vector<int>& nums) {
    /*
    similar to house robber 1 just in a circle now, so when u get to the end, consider either the last house or the prev plus the first huose??
    need to know for each sum if the first house has been included?

    two subproblems with the max from 0 to n-1 or 1 to n
    */
    if (nums.size() == 1) return nums[0];
    int p1 = 0;
    int p2 = 0;
    for(int i = 0; i < nums.size() - 1; i++){
        int tmp = p1;
        p1 = max(p2 + nums[i], p1);
        p2 = tmp;
    }
    int first = p1;
    p1 = 0;
    p2 = 0;
    for(int i = 1; i < nums.size(); i++){
        int tmp = p1;
        p1 = max(p2 + nums[i], p1);
        p2 = tmp;
    }
    return max(first, p1);
    }
};