class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*brute force, unordered map and return automatically if any element has greater than 0*/

        unordered_map<int,int> freqs;
        for(int n : nums){
            if(freqs[n] > 0) return true;
            freqs[n]++;
        }
        return false;
    }
};