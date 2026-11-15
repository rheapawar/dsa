class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int op = 0;
        for(int i : nums){
            op ^= i;
        }
        return op;
    }
};