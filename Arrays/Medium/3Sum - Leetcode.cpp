// -> https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        for(auto i = nums.begin(); i != nums.end(); i++) {
            if(*i > 0) break;
            if(i != nums.begin() && *i == *(i-1)) continue;
            auto j = i+1, k = nums.end()-1;
            while(j < k) {
                if(*i + *j + *k == 0) {
                    v.push_back({*i, *j++, *k--});
                    while(j < k && *j == *(j-1)) j++;
                    while(k > j && *k == *(k+1)) k--;
                } else if(*i + *j + *k < 0) j++;
                else k--;
            }
        }
        return v;
    }
};
