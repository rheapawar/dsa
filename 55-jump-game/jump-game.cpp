class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*

        backtrack?? or should u always go to the palce with the least mvoes possible?? is greedy possible or is this more dp

        things i noticed - in ex 1) regardless of how many steps u took from og position, u could end up at the end - so is it possible it doesnt quite matter?

        needed a sec to think and prompt and then found
        if u can reach 4, then u can reach 3?? is that true - yes bc at one step u simply take one less step

        so then track how far right u can go at any given point and then proceed with one step forward, seeing whether at any point u reach the ending point

        if traveling, consider whether u can even leave to begin with
        DONT FORGET BASE/EDGE CASES
        implement:

        loop over nums array, keep right pointer, if right pointer ever meets or exceeds right, then return true

        what if u land somewhere and cannot move past it then u must consider 

        test cases: 
        [1,3,2,4,5]
        */
        if(nums.empty() || nums.size() == 1) return true;
        int right = 0;
        for(int i = 0; i < nums.size() -1; i++){
            right = max(right, i + nums[i]);
            if(nums[i] == 0 && right == i) return false;
            if(right >= nums.size()-1) return true;
        }
        return false;
    }
};