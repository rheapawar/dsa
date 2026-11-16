class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        /*such that she can eat the minimum number of bananas and still be able to finisht them all*/

        int n = piles.size();
        int min = 1;
        int max = piles[n-1];


        while(min <= max){
            int speed = min + (max - min)/2;
            if(finished(piles, speed, h)) max = speed -1;
            else min = speed + 1;
        }

        return min;
    }

        bool finished(const vector<int> &piles, int speed, int bound){
            long long hours = 0;
            for(auto pile : piles){
                if(speed > pile) hours++;
                else{
                    hours += (pile + speed -1 )/speed;
                }
            }
            return (hours <= bound) ? true : false;
        }
    
};