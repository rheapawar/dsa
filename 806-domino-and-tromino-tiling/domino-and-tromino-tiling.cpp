class Solution {
public:
    int numTilings(int n) {
        int MOD = 1'000'000'007;
        if(n <= 2) return n;
        long prev2 = 1;
        long prev1 = 2;
        long partial = 1;
        for(int i = 3; i < n + 1; i++){
            long tmp = prev1;
            prev1 = (prev1 + prev2 + 2*partial) % MOD;
            partial = (partial + prev2) % MOD;
            prev2 = tmp;
        } 
        return prev1;
    }
};