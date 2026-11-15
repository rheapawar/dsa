class NumArray {

private: 
    vector<int> prefixes;
public:
    NumArray(vector<int>& nums) {
        prefixes.resize(nums.size());
        prefixes[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefixes[i] = prefixes[i-1] + nums[i];

           // -2, -2, 1, -4, -2, -3
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefixes[right];
        return prefixes[right] - prefixes[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */