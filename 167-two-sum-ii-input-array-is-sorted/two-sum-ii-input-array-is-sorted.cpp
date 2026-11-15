class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //nondecreasing order so basically increasing except u may have afew repeated, two pointers

        int left = 0;
        int right = numbers.size()-1;
        int sum;
        while(left < right){
            int curr = numbers[left] + numbers[right];
            if(curr > target) right--;
            else if(curr < target) left++;
            else if(curr == target) break;
        }
        return {left+1, right+1};
    }
};