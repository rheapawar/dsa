class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> s(temperatures.size());
        vector<int> res(temperatures.size(), 0);    
        s.push_back(0);       
        for(int i = 1; i < temperatures.size(); i++){
            while(!s.empty() && temperatures[i] > temperatures[s.back()]){
                int x = s.back();
                res[x] = i - x;
                s.pop_back();
            }
            s.push_back(i);

        }
        return res;
    }

};