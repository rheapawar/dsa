class Solution {
public:
    int jump(vector<int>& nums) {
        /*
        main idea - basically need to go thru vector and at each step, 
        see whether its possible to reach the full length - 

        would it work to go as far as possible?? greedy??

        at each index, need to know min number of steps need to get to that point and then furthest forward u can go? this would be mroe dp however

        what is the first instance u can get to end potentially?
        so at each index, check to see whether u can get to end, if not
            if it tkaes u further left than prev, increment num moves, otherwise do not


        ex )

        [2, 1, 5, 2, 4]

        unoptimal solutions, branch & bound + dp

        need a num moves var

        consider base cases

        at each point, choose whether one step over or full step is better?? like gets u closer to result
        and so iterate over which is the best possible in each sub problem and then just jump there i think 

        maintains o(n) bc u are jumping to the largest value so everything is only being processed once, can keep a counter of the furthest right u have already calculated
        */
        if(nums.size() == 0 || nums.size() == 1) return 0;
        int num_moves = 0;
        int right = nums[0];
        for(int i = 0; i < nums.size(); i++){
            num_moves++;
            if(right >= nums.size() -1) break;
            int idx = -1;
            for(int j = i+1; j <= nums[i] + i &&  j < nums.size(); j++){
                if(right <= j + nums[j]){
                    idx = j;
                    right = j + nums[j];
                   
                }
            }
            i = idx-1;
        }
        return num_moves;
    }
};