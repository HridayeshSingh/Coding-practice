// -> https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int>::iterator it;
        for(it = nums.end()-1; it != nums.begin(); it--) {
            if(*it > *(it-1)) {
                reverse(it, nums.end());
                auto target = upper_bound(it, nums.end(), *(it-1));
                swap(*(it-1), *target);
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
