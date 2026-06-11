class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        s.reserve(asteroids.size());
        s.push_back(asteroids[0]);
        for(int i = 1; i < asteroids.size(); i++){
            bool explode = false;
            while(!s.empty() && (asteroids[i] < 0 && s.back() > 0 )){
                
                if(abs(s.back()) < abs(asteroids[i])) s.pop_back();
                else if((abs(s.back()) == abs(asteroids[i]))){
                    s.pop_back();
                    explode = true;
                    break;
                }
                else{
                    explode = true;
                    break;
                }
            }
            if(!explode) s.push_back(asteroids[i]);
        }
        
        return s;
    }
};