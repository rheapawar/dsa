class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int intervals = 0;
        priority_queue<int> pq;
        vector<int> counts(26);

        for(char c : tasks){
            counts[c -'A']++;
        }
        for(int c : counts){
            if(c > 0) pq.push(c);
        }
    
        while(!pq.empty()){
            int i = 0;
            vector<int> q;
            while(i < n+1 && !pq.empty()){
                int x = pq.top() - 1;
                pq.pop();
                if(x > 0) q.push_back(x);
                intervals++;
                i++;
            }
            for(int c : q) pq.push(c);
            if(!pq.empty()) intervals += n - i + 1;
        }
        return intervals;
    }

    

};