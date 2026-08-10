class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int erased = 0;
        /*
            methods:
            sort all the elements and then whichever ones have overlapping entries, see the removal of which one would maximize

            so is it posisble to deduce that removing the first problematic one encountered will reduce all

            first one cannot be in the min to remove bc to maximize overlapping, it would need to overlap in many places

            so every time an overlap is encountered, check to see if an overlap occurs on other end too

            while traversing, would remove [3,7] and then 8 overlaps 9, before removing
            test case: [1, 5] [3,7] [6,10] [8,12] [11, 15]

            [1,6] [2,4] [5,8]
            [2,4], [1,6], [5,8]

            [1,2], [1,3] [2,3], [3,4], 
            basically sort, traverse like normal, if an overlap is detected then remove the second one bc that is the one that has a potential overlap w annother

            test case i got caught on

            [[-52,31],[-73,-26],[82,97],[-65,-11],[-62,-49],[95,99],[58,95],[-31,49],[66,98],[-63,2],[30,47],[-40,-26]]

            [-62, -49],
    [-73, -26],
    [-40, -26],
    [-65, -11],
    [-63,   2],
    [-52,  31],
    [ 30,  47],
    [-31,  49],
    [ 58,  95],
    [ 82,  97],
    [ 66,  98],
    [ 95,  99]

            sorted 
        */
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){return a[1] < b[1];});
        int right = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(right > intervals[i][0]){
                erased++;
            }
            else right = intervals[i][1];
        }
        return erased;
    }
};