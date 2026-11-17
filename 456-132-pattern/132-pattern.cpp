class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //okay so need to find an element when larger than the earliest and smaller than the middle
        //could retain a pointer to the third element and see if there are any where it would be tangible, keep stack of elements we have seen so far, like basically as soon as u find one elemnt that is greater u need to find one that is smaller, keep the smallest u have seen so far as the latest element, wait i feel like u keep adding elements to the stack and u are trying to find one that is bigger than the element
        int k = INT_MIN;
        stack<int> s;
        for(int i = nums.size()-1; i >= 0; i--){
           if(nums[i] < k) return true;
           else{
                while(!s.empty() && nums[i] > s.top()){
                    k = s.top();
                    s.pop();
           }}
           s.push(nums[i]);
        }
        return false;
    }
};