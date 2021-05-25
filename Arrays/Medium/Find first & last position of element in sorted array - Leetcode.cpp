// -> https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(first(nums, target));
        res.push_back(last(nums, target));
        return res;
    }
    
    int first(vector<int> nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = (low+high)/2;
            if(nums[mid] < target)
                low = mid+1;
            else if(nums[mid] > target)
                high = mid-1;
            else {
                if(mid > 0 && nums[mid] == nums[mid-1])
                    high = mid-1;
                else
                    return mid;
            }
        }
        return -1;
    }
    
    int last(vector<int> nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = (low+high)/2;
            if(nums[mid] < target)
                low = mid+1;
            else if(nums[mid] > target)
                high = mid-1;
            else {
                if(mid < nums.size()-1 && nums[mid] == nums[mid+1])
                    low = mid+1;
                else
                    return mid;
            }
        }
        return -1;
    }
};
