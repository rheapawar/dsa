class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        /*questions that i have, need to construct the sorted form of the vector without actually sorting, so i need to have keep track of the largest and smallest element maybe and then also need to do a bucket sort bc o(n) oh wait maybe i do a radix sort on it first and then go thru and traverse sorted */
        int max_elem = *max_element(nums.begin(), nums.end());
        for(long long exp = 1; max_elem/exp > 0; exp*=10){
            radix(nums, exp);
        }
        //okay now have sorted vector so then need to loop thru and find max difference
        int max_diff = 0;
        for(int i = 1; i < nums.size(); i++){
            max_diff = max(nums[i] - nums[i-1], max_diff);
        }
        return max_diff;

    }
    
    void radix(vector<int> &nums, long long exp){
        int n = nums.size();
        vector<int> sorting(n);
        vector<int>buckets(10, 0);
        for(int x : nums) buckets[ (x/exp) % 10]++;
        for(int i = 1; i < buckets.size(); i++) buckets[i] += buckets[i-1];
        for(int i = nums.size()-1; i >= 0; i--){
            int idx = (nums[i]/exp) % 10;
            sorting[--buckets[idx]] = nums[i];
        }
        nums = sorting;
        /*need to create byckets where i sort and reserve the number of elements ending w each, then compute the prefix sums and then i will know the index, okay now that i know the index how to i ensure that they remain in order of size??*/
    }
};