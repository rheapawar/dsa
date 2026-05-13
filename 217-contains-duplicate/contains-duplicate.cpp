class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> n;
        n.reserve(nums.size());
        for(auto x: nums){
            if(!n.insert(x).second) return true;
        }
        return false;
    }
};