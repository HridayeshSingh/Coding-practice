// -> https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = (low+high)/2;
            
            if(nums[mid] < target) {
                if(nums[high] >= nums[mid] && nums[high] < target) high = mid-1;
                else low = mid+1;
            } else if(nums[mid] > target) {
                if(nums[low] <= nums[mid] && nums[low] > target) low = mid+1;
                else high = mid-1;
            } else
                return mid;
        }
        
        return -1;
    }
};
