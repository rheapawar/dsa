class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*general idea, count up the number of zeroes actually everytime a zero is seen, shift all the elements back, have one index for the element we are on, and another for where in the array we are placing an element and then once the element we are on reaches the end, fill in rest of array with zeroes*/
        int place = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[place] = nums[i];
                place++;
            }
        }
        for(int i = place; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};