class Solution {
public:
    int reverse(int x) {
        int y = 0;
        while(x != 0){
            int n = x%10;
            x /= 10;
            if (y > INT_MAX / 10 || (y == INT_MAX / 10 && n > 7)) return 0;
            if (y < INT_MIN / 10 || (y == INT_MIN / 10 && n < -8)) return 0;
            y = (y*10) + n;
        }
        return y;


    }
};