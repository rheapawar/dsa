class Solution {
public:
    int hammingWeight(int n) {
        string s = bitset<32>(n).to_string();
        int res = 0;
        for(auto x : s){
            if(x == '1') res++;
        }
        return res;
    }
};