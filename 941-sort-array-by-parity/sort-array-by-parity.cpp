class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        /*core idea, traverse and count the number of even elements, and then go back through and every even element placed then increment the index, use extra space first then see if it can be eliminated*/

        int num_even = 0;
        for(int n : nums) if(n%2 == 0) num_even++;

        vector<int> res(nums.size());

        int odd_idx = num_even;
        int even_idx = 0;
        for(int n : nums){
            if(n % 2 == 0) res[even_idx++] = n;
            else res[odd_idx++] = n;
        }
        return res;
    }
};