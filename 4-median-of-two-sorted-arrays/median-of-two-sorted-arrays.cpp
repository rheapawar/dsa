class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*time complexity suggests binary search but with log m + n. for a median first need to decide odd and even parity and what number index will indicate that*
        
        
        go to the mid of both arrays, but then need to see what the gap between them would be - whiever is larger
        
        go to center of smaller array and then determine how many elements left and right - then go to the other array and try to find that value or the largest value smaller than that element - once position is determined, figure out how many places left or right need to be moved and then adjust manually between the two */

        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int low = 0;
        int high = nums1.size();
        int sum = nums1.size() + nums2.size();
        while(low <= high){
            int cut1 = low + (high - low)/2;
            int cut2 = (sum + 1)/2 - cut1;
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == nums1.size()) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == nums2.size()) ? INT_MAX : nums2[cut2];
            if(l1 <= r2 && l2 <= r1){
                if(sum % 2 == 0) return (max(l1, l2) + min(r1, r2))/2.0;
                else return max(l1, l2);
            }
            else if(l1 > r2) high = cut1 - 1;
            else if(l2 > r1) low = cut1 + 1;
        }
        return 0.0;
    }
};