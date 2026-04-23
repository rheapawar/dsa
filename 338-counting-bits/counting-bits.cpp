class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1, 0);
        int pow = 1;
        for(int i = 1; i <= n; i++){
            if(i == pow*2) pow = i;
            bits[i] = bits[i-pow] + 1;
        }
        return bits;
    }
};