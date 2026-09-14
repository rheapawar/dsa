class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2){
            if(v1[0] != v2[0]) return v1[0] < v2[0];
            else return v1[1] < v2[1];});
        vector<vector<int>> res;
        res.reserve(intervals.size());
        res.push_back(intervals[0]);
        for(int i = 1; i <intervals.size(); i++){
            int n = res.size() -1;
            if(res[n][1] >= intervals[i][0]) res[n][1] = max(res[n][1], intervals[i][1]);
            else res.push_back(intervals[i]);
        }
        return res;
    }
};