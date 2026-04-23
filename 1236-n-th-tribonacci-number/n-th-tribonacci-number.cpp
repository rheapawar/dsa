class Solution {
public:
    int tribonacci(int n) {
        static int mems[39] = {0, 1, 1};
        int num = 0;
        if(n < 3 || mems[n] > 0) return mems[n];
        num = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
        mems[n] = num;
        return num;
    }
 
};