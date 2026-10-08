class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        /*base idea would be to construct window size and see if anything matches this or if the pattern is the same amount apart*/

        int count = 0;
        for(int i = 0; i < arr.size() - m; i++){
            if(arr[i] != arr[i+m]) count = 0;
            count += (arr[i] == arr[i+m]);
            if(count == (k-1)*m) return true;
        }
        return false;
    }
};