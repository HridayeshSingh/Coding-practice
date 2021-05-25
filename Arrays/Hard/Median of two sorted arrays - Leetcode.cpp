// -> https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        
        if(n1 == 0) {
            if(n2%2)
                return nums2[n2/2];
            else
                return (nums2[n2/2]+nums2[n2/2-1])/2.0;
        }
        
        int low = 0, high = n1;
        
        while(low <= high) {
            int i1 = (low+high)/2, i2 = (n1+n2+1)/2 - i1;
            int min1 = (i1 == n1) ? INT_MAX : nums1[i1];
            int max1 = (i1 == 0) ? INT_MIN : nums1[i1-1];
            int min2 = (i2 == n2) ? INT_MAX : nums2[i2];
            int max2 = (i2 == 0) ? INT_MIN : nums2[i2-1];
            
            if(min1 >= max2 && min2 >= max1)
                if((n1+n2)%2)
                    return max(max1, max2);
                else
                    return (max(max1, max2) + min(min1, min2))/2.0;
            else if(min1 < max2)
                low = i1+1;
            else
                high = i1-1;
        }
        return -1;
    }
};
