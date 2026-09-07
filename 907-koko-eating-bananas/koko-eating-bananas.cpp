class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
     /*min eating rate so that all bananas are gona
     
     hours is guaranteed to be more than the number of piles, sort the piles, have to figure out 

     halfway point of the soeted vecror? determine whether 

     need to pick a number such that the sum of all the elements above it divided by k is less than hours i?

     wouldnt quite work but would basically need to check whether all the elemtns larger than that number can be fit within the number of remaining hours broken down
     need to compute the remaining number of bananas from the min amount

     binary search with number rather than elements of the array similar to the balls question

     go to center element of array, everything smaller will take i number of hors, then everyhing greater oh and then everything greater will take at minimum 2 * (piles.length - i)
     try to find the smallest element greater than double the thing and then keep going to till no large value is found

     like if it still works, then decrease by a banana further and keep going till it doesnt work somewhere?
     */

     int right = *max_element(piles.begin(), piles.end());
     int left = 1;
     int mid;

     while(left <= right){
        mid = left + (right - left)/2;
        if(finished(piles, h, mid)) right = mid - 1;
        else left = mid + 1;
     }
     return left;

    }

    bool finished(const vector<int> &piles, int h, int val){
        long long count = 0;
        for(auto pile : piles){
            count += (pile + val - 1)/val;
            if(count > h) return false;
        }
        return count <= h;
    }
};