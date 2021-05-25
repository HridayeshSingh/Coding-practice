// -> https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX, res = 0;
        
        for(auto it = nums.begin(); it != nums.end(); it++) {
            if(it != nums.begin() && *it == *(it-1)) continue;
            
            auto a = it+1, b = nums.end()-1;
            while(a < b) {
                int diff = abs(target - (*it+*a+*b));
                if(diff < minDiff) {
                    minDiff = diff;
                    res = *it+*a+*b;
                }
                if(diff == 0) break;
                if((*it+*a+*b) < target) a++;
                else b--;
            }
        }
        
        return res;
    }
};
