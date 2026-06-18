class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> m;
        vector<int> ans;
        ans.reserve(2);
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]].push_back(i);
        }
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            auto it = m.find(target - x);
            if(it != m.end()){
                if((target - x != x) || m[x].size() > 1){
                    ans.push_back(i);
                    ans.push_back(it->second[m[x].size() -1]);
                    break;
                }
            }
        }
        return ans;
    }
};