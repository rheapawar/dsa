class Solution {
public:
    vector<int> partitionLabels(string s) {
        /*for each char, keep track of the last index of the element - loop thru once

        then second loop to see where the first concatenation can be terminated
         so ex 2)
         map 
         e = 8, first encounter 0
         c = 9, first encounter 1

         where to terminate, store the left and right index of the first element in the window and then as u move left between those two values, if any of the elements in between left and right have later right, then change the right bound, once u get to a place where curr == right in the index, then add the value right - left + 1 to the vector and move to the next element left and right while right is smaller than the max size of the array

        */
        vector<int> res;
        res.reserve(s.size());
        unordered_map<char, int> map;
        for(int i = 0; i < s.length(); i++){
            map[s[i]] = i;
        }
        int left = 0;
        int right = map[s[0]];
        for(int curr = 0; curr < s.length(); curr++){
            right = max(right, map[s[curr]]);
            if(curr == right){
                res.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return res;
    }
};