class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        s.reserve(nums.size());
        for(auto n : nums){
            s.insert(n);
        }
        int longest = 0;
        for(int n : s){
            if(s.find(n-1) == s.end()){
                int num = n;
                int curr = 1;
                while(s.find(num+1) != s.end()){
                    curr++;
                    num++;
                }
                longest = max(longest, curr);
            }
            
        }
        return longest;
    }
};