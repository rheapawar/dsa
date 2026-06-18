class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        ans.reserve(2);
        for(int i = 0; i < nums.size(); i++){
            auto it = m.find(target-nums[i]);
            if(it != m.end()){
                ans.push_back(i);
                ans.push_back(it->second);
                break;
            }
            else m[nums[i]] = i;
        }
        return ans;
    }
};