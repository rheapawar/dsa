class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*can u maybe make a vector and then if its there, make its bool true and then traverse over vector and check, oops can have negative numbers so then maybe a hashmap but ur instead able to keep track of the largest value u and traverse up till that element since O9) access*/
        int best = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int n: s){
           if(s.find(n-1) == s.end()){
                int x = n + 1;
                while(s.find(x) != s.end()){
                    x++;
                }
                best = max(best, x - n);

           }
        }
        return best;
    }
};