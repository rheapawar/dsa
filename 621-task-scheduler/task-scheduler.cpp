class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int intervals = 0;
        vector<int> counts(26);
        vector<int> pq;
        pq.reserve(26);
        for(char c : tasks){
            counts[c -'A']++;
        }
        for(int c : counts){
            if(c > 0) pq.push_back(c);
        }
        sort(pq.begin(), pq.end());

        while(!pq.empty()){
            int i = 0;
            vector<int> q;
            while(i < n+1 && !pq.empty()){
                int x = pq.back() - 1;
                pq.pop_back();
                if(x > 0) q.push_back(x);
                intervals++;
                i++;
            }
            while(!q.empty()){
                pq.push_back(q.back());
                q.pop_back();
            }
            if(!pq.empty()){
                intervals += n - i + 1;
                sort(pq.begin(), pq.end());
            }
        }
        return intervals;
    }

    

};