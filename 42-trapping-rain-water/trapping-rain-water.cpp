class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int left_max = 0;
        int right_max = height.size() - 1;
        int left = 0;
        int right = right_max;
        while(left < right){
            if(height[left_max] <= height[right_max]){
                left++;
                left_max =(height[left_max] > height[left]) ? left_max : left;
                water += height[left_max] - height[left];
            }
            else if(height[right_max] < height[left_max]){
                right--;
                right_max =(height[right_max] > height[right]) ? right_max : right;
                water += height[right_max] - height[right];
            }
          
        }
        return water;
    }
};

//where there is a gap such that the 
// 1. CONSTRAINTS: N = ?, Negative values allowed?, Empty inputs possible?
// 2. BRUTE FORCE CONCEPT: What is the obvious, slowest way to do this?
// 3. THE BLUEPRINT: Sorted? -> Pointers. History? -> Stack. Lookup? -> Map.
// 4. INVARIANT: What rule can absolutely NEVER break inside my loops?