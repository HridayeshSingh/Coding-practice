// -> https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool isOnePresent = false;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
            else if(nums[i] == 1)
                isOnePresent = true;
        }
        
        if(!isOnePresent) return 1;
        
        for(int i = 0; i < n; i++) {
            if(nums[abs(nums[i])-1] > 0) {
                nums[abs(nums[i])-1] *= -1;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0)
                return i+1;
        }
        
        return n+1;
    }
};
