class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        /*rough idea, use a vector as a stack and push the first element in. then for each proceeding leemnt check if the element at the top of the stack is a diff sign, if it is, pop the top and push_back the max of the abs value of the two of them, if not then push_back asteroid*/
        vector<int> s;
        s.reserve(asteroids.size());
        for(int elem: asteroids){
            bool destroyed = false;
            while(!s.empty() && s.back() > 0 && elem < 0){
                int x = s.back();
                if(abs(x) > abs(elem)){
                    destroyed = true;
                    break;
                }
                else if(abs(x) < abs(elem)) s.pop_back();
                else{
                    destroyed = true;
                    s.pop_back();
                    break;
                }
                
            }
            if(!destroyed) s.push_back(elem);

        }
        return s;
    }
};