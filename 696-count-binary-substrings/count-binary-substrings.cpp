class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.length() == 0) return 0;
        /*kind of like a sliding window, start with traversing array and if nums curr != num prev*/
        int total = 0;
        int prev = 0;
        int curr = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]) curr++;
            else{
                prev = curr;
                curr = 1;
            }
            if(prev >= curr) total++;
        }
        return total;
    }
};