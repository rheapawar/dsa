class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
        maybe traverse backwards and push temperatures into a stack and for each element check if the top of the stack is greater - if it is then, great its 1 if not then

        */
        int n = temperatures.size();
        vector<int> res(n, 0);
        vector<pair<int,int>> s;
        s.reserve(n);
        s.push_back({temperatures[n-1], n-1});
        for(int i = n-2; i >= 0; i--){
            while(!s.empty() && s.back().first <= temperatures[i]){
                s.pop_back();
            }
            res[i]  = (s.empty()) ? 0 : s.back().second - i;
            s.push_back({temperatures[i], i});
        }
        return res;
        //[72,76]
    }
};