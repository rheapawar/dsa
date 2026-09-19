class Solution {
public:
    int countElements(vector<int>& arr) {
        int counts[1001];
        int res = 0;
        for(size_t i = 0; i < arr.size(); i++){
            counts[arr[i]]++;
        }
        for(int i = 0; i < 1000; i++){
            if(counts[i] > 0 && counts[i+1] > 0) res += counts[i];
        }
        return res;
    }
};