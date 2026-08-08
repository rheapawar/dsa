class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change[3] = {0,0,0};
        for(int i = 0; i < bills.size(); i++){

            int c = bills[i] - 5;
            if(bills[i] == 5) change[0]++;
            if(bills[i] == 10) change[1]++;
            if(bills[i] == 20) change[2]++;

            while(c > 0){
                if(c == 15 && change[1] > 0){
                    c -= 10;
                    change[1]--;
                }
                else if(change[0] > 0){
                    c -=5;
                    change[0]--;
                }
                else{
                    return false;
                }
            }
        }
        return true;

    }
};