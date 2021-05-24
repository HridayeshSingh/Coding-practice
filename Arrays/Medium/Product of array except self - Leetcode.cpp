// -> https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), pro = 1;
        vector<int> res(n, 1);
        
        for(int i = 0; i < n; i++) {
            res[i] = pro;
            pro *= nums[i];
        }
        
        pro = 1;
        for(int i = n-1; i >= 0; i--) {
            res[i] *= pro;
            pro *= nums[i];
        }
        
        return res;
    }
};
