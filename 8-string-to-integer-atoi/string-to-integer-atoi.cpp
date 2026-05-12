class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int i = 0;
        int sign = 1;
        while(i < s.length() && s[i] == ' '){
            i++;
            continue;
        }
        if(i < s.length() && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-') sign = -1;
            i++;
        }
        if(s[i] == 0) i++;
        for(int j = i; j < s.length(); j++){
            if(!isdigit(s[j])) break;
            else{
                res *= 10;
                res += s[j] - '0';

                if(res * sign > INT_MAX) return INT_MAX;
                if(res * sign < INT_MIN) return INT_MIN;
            }

        }
        return res = (sign == -1) ? res*-1 : res;
    }
};