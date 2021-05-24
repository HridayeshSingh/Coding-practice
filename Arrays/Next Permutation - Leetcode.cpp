// -> https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1, n = nums.size();
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                idx = i;
                reverse(nums.begin()+idx+1, nums.end());
                auto it = upper_bound(nums.begin()+idx+1, nums.end(), nums[idx]);
                swap(nums[idx], *it);
                return;
            }
        }
        reverse(nums.begin()+idx+1, nums.end());
    }
};
