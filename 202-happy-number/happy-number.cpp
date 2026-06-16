class Solution {
public:
    bool isHappy(int n) {
        int res = n;
        while(res > 9){
            int x = 0;
            while(res > 9){
                x += (res%10)*(res%10);
                res = res/10;
            }
            x += res*res;
            res = x;
        }
        if(res == 1 || res == 7) return true;
        else return false;

    }
};