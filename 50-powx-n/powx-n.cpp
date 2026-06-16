class Solution {
public:
    double myPow(double x, int n) {
       if(n>0) return helper(x, n);
       else return helper(1/x, n);
    }
    double helper(double x, int pow){
        double res = 0;
        bool odd = false;
        if(pow == 0) res = 1;
        else if(pow == 1) res = x;
        else{
            if((pow %2) != 0) odd = true;
            res = helper(x, pow/2);
            res *= res;
            if(odd) res *= x;
        } 
        return res;
    }
};