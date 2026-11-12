class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        /*how to best scale them into buckets, know that there are a total of n elements, need to know the best way to group the index,instead of group by elements, meant to group by frequency instead of needing to maintain pq*/
        unordered_map<int,int> counts;
        for(int x : nums) counts[x]++;

        vector<vector<int>> buckets(n+1);
        for(auto &[val, freq] : counts){
            buckets[freq].push_back(val);
        }

        vector<int> res;
        for(int i = buckets.size()-1; i >= 0 && res.size() < k; i--){
            for(int v : buckets[i]){
                res.push_back(v);
                if(res.size() == k) break;
            }
        }
        return res;
    }
};