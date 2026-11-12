class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> indices;
        for(int i = 0; i < nums.size(); i++){
            auto &map = indices[nums[i]];
            if(map.size() != 0){
                if(i - map.back() <= k) return true;
            }
            map.push_back(i);
        }
        return false;
    }
};