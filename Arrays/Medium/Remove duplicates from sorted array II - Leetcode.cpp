// -> https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 2)
            return n;
        
        int len = 2;
        for(int i = 2; i < n; i++) {
            if(nums[i] != nums[len-1] || nums[i] != nums[len-2])
                nums[len++] = nums[i];
        }
        
        return len;
    }
};
