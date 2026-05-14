class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    vector<int> res;
    priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int, int>>> pq;
    
    for(int i = 0; i < nums.size(); i++){
        ++m[nums[i]];
    }
    for(auto it = m.begin(); it != m.end(); it++){
        if(pq.size() < k) pq.push({it->second, it->first});
        else{
            if(it->second > pq.top().first){
                pq.pop();
                pq.push({it->second, it->first});
            }
        }
    }
    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
    }
};