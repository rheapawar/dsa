class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*at each index, max subproduct would be just max of the current streak and then the previous, so consider like two pointers, one for max, one for curr, if the new element multiplied by curr will decrease the curr, then set max = max, curr and then set curr = 1
        wait but if u encounter a negative but encounter one again later then it would be okay and move on*/
        if(nums.empty()) return 0;
        int maxima = nums[0];
        int minima = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int curr = nums[i];
            int tmp = max(curr, max(maxima*curr, minima*curr));
            minima = min(curr, min(maxima*curr, minima*curr));

            maxima = tmp;
            res = max(res, maxima);
        }

        return res;
    }
};