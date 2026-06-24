class Solution {
public:
    int maxArea(vector<int>& height) {
       int left = 0;
       int right = height.size()-1;
       int max = 0;
       while(left < right){
            int area = min(height[left], height[right])*(right-left);
            if(area > max) max = area;
            if(height[left] < height[right]) left++;
            else right--;
       }
       return max;
    }
};

// 1. CONSTRAINTS: N = ?, Negative values allowed?, Empty inputs possible?
// 2. BRUTE FORCE CONCEPT: What is the obvious, slowest way to do this?
// 3. THE BLUEPRINT: Sorted? -> Pointers. History? -> Stack. Lookup? -> Map.
// 4. INVARIANT: What rule can absolutely NEVER break inside my loops?