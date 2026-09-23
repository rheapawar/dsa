class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        /*pq mapping distnace to the set of points, and then a custom comparator evaluating the distances*/
        vector<vector<int>> res;
        res.reserve(k);
        struct compare{
            bool operator()(const vector<int> &p1, const vector<int> &p2) const{
                double dist1 = sqrt((p1[0]*p1[0]) + (p1[1]*p1[1]));
                double dist2 = sqrt((p2[0]*p2[0]) + (p2[1]*p2[1]));
                return dist1 < dist2;
            }
        };

        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        compare c;
        for(auto point : points){
            if(pq.size() < k){
                pq.push(point);
            }
            else if(c(point, pq.top())){
                pq.pop();
                pq.push(point);
            }
        }

        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};