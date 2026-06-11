class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size() == 1 || position.size() == 0) return position.size();
        
        vector<pair<int,double>> t(position.size());
        vector<double> s;
        for(int i = 0; i < position.size(); i++){
            double x = (double)(target - position[i])/speed[i];
            t[i] = {position[i], x};
        }
        sort(t.begin(), t.end());
        for(int i = t.size()-1; i>=0; i--){
            double x = t[i].second;
            if (s.empty() || x > s.back()) s.push_back(x);
        }
        return s.size();
    }
};