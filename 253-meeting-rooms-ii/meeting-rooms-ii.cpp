class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
     vector<int> count(1000002);
        int maxEnd = 0;
        int ans = 0;
        for(auto interval : intervals) {
            count[interval[0]]++;
            count[interval[1]]--;
            maxEnd = max(maxEnd, interval[1]);
        }
        for(int i = 0; i < maxEnd; i++) {
            count[i + 1] += count[i];
            ans = max(count[i], ans);
        }
        return ans;

    }
};