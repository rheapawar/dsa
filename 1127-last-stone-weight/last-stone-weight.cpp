class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1){
            int top = pq.top();
            pq.pop();
            int sec = pq.top();
            pq.pop();
            if(top != sec) pq.push(top - sec);
        }
        return (pq.size() > 0) ? pq.top() : 0;
    }
};