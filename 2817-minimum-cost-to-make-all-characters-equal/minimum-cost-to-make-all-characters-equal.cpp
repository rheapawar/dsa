class Solution {
public:
    long long minimumCost(string s) {
        /*would a general idea not be to loop thru countining the number of zeroes vs the number of 1s at any index in time and determine total cost based on that */

        long long min_cost = 0;
        int n = s.length();
        for(int i =1; i < s.length(); i++){
          if(s[i] != s[i-1]){
            min_cost += min(n-i, i);
          }
        }
        return min_cost;
    }
};