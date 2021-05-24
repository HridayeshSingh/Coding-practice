// -> https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);
    }
    
    void reverse(vector<int>& nums, int a, int b) {
        while(a < b) {
            swap(nums[a++], nums[b--]);
        }
    }
};
