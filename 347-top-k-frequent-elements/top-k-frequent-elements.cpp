class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*literally a min pq with a custom comparator to determine ordering based on second element, then iterate over pq at end to hold only, but need to increment the elements - oh go thru, make hashmap, then go thru hashmap, build pq of top k?*/


        struct Compare{
            bool operator()(const pair<int,int> a, const pair<int,int> b){
                return a.second > b.second;
            }
        };
        unordered_map<int,int> map;
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        vector<int> res;
        res.reserve(k);

        for(int n : nums){
            map[n]++;
        }
        for(auto it = map.begin(); it != map.end(); it++){
            if(pq.size() < k) pq.push(*it);
            else if(it->second > pq.top().second){
                pq.pop();
                pq.push(*it);
            }
        }

        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};