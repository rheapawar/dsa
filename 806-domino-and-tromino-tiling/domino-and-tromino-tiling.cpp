class Solution {
public:
    int numTilings(int n) {
        int MOD = 1'000'000'007;
        if(n <= 2) return n;
        vector<long> memo(n+1, 0);
        vector<long> partial(n+1, 0);
        memo[0] = 1;
        memo[1] = 1;
        memo[2] = 2;
        partial[2] = 1;
        for(int i = 3; i < n + 1; i++){
            memo[i] = (memo[i-1] + memo[i-2] + 2*partial[i-1]) % MOD;
            partial[i] = (partial[i-1] + memo[i-2]);
        } 
        return static_cast<int>(memo[n]);
    }
};