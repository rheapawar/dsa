class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        ans.reserve(2);
        m.reserve(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            auto it = m.find(target-x);
            if(it != m.end()){
                ans.push_back(i);
                ans.push_back(it->second);
                break;
            }
            else m[x] = i;
        }
        return ans;
    }
};