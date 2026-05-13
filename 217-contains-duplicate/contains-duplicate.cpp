class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> n;
        for(auto x: nums){
            if(n.find(x)!=n.end()) return true;
            n.insert(x);
        }
        return false;
    }
};