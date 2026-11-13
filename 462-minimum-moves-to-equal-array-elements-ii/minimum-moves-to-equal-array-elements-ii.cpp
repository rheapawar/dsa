class Solution {
public:
    int minMoves2(vector<int>& nums) {
        /*this is mainly about finding the element closest to the most number of elements possible, would this potentially be the median??? that should be the closest, or would it be the average? okay so it is the median bc this accounts for elements that are actually in the vector rather than whats closest to all of them
        
        */
        int median = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        if(n % 2 != 0) median = nums[n/2];
        else median = (nums[n/2] + nums[(n/2)-1])/2;


        int moves = 0;
        for(int n : nums){
            moves += abs(n - median);
        }
        return moves;
    }

    /*
    0 0 1 6 8
    1 2 9 10
    median = 5
    4 + 3 
    */
};