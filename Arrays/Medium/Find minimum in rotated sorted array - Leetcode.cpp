// -> https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = (low+high)/2;
            int mid_prev = mid-1 < 0 ? (n+mid)%n : (mid-1)%n;
            int low_prev = low-1 < 0 ? (n+low)%n : (low-1)%n;
            if(nums[mid] < nums[mid_prev] && nums[mid] < nums[(mid+1)%n])
                return nums[mid];
            else if(nums[mid] < nums[high])
                high = mid-1;
            else
                if(nums[low] < nums[low_prev])
                    return nums[low];
                else
                    low = mid+1;
        }
        return nums[0];
    }
};
