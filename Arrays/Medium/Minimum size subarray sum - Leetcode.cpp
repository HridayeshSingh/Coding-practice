// -> https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int s = 0, sum = 0, len = n+1;
        
        for(int e = 0; e < n; e++) {
            sum += nums[e];
            while(sum >= target) {
                len = min(len, e-s+1);
                sum -= nums[s++];
            }
        }
        
        return len <= n ? len : 0;
    }
};
