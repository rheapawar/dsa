class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*index of the prev min and th
        
        10,9,2,3,5,7,4,5
        issue is if you run into a number where the streak before doesnt include the actual pre value then u cant increment by one - so does dp instead hold the value of the largest streak containing that element and then a separate variable for max streak so far?
        */
        vector<int> streak;
        streak.reserve(nums.size());
        for(int n : nums){
            if(streak.empty() || streak.back() < n) streak.push_back(n);
            else{
                auto it = lower_bound(streak.begin(), streak.end(), n);
                *it = n;
            }
        }
        return streak.size();
        
        }
};