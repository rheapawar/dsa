class Solution {
public:
    int fib(int n) {
        static int nums[31] = {0,1};
        if(n < 2 || nums[n] > 0) return nums[n];
        int sum = fib(n-1) + fib(n-2);
        nums[n] = sum;
        return sum;
    }
};