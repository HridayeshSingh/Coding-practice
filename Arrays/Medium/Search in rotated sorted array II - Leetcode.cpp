// -> https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size()-1, target);
    }
    
    bool helper(vector<int>& nums, int low, int high, int target) {
        if(low > high)
            return false;
        
        int mid = (low+high)/2;
        if(nums[mid] == target)
            return true;
        
        bool a = false, b = false;
        if(nums[low] <= nums[mid]) {
            if(nums[low] <= target && target < nums[mid])
                a = helper(nums, low, mid-1, target);
            else
                a = helper(nums, mid+1, high, target);
        }
        if(nums[mid] <= nums[high]) {
            if(nums[mid] < target && target <= nums[high])
                b = helper(nums, mid+1, high, target);
            else
                b = helper(nums, low, mid-1, target);
        }
        
        return a||b;
    }
};
