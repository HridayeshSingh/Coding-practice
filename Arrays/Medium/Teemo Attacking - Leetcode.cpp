// -> https://leetcode.com/problems/teemo-attacking/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0, n = timeSeries.size();
        
        for(int i = 0; i < n-1; i++) {
            res += min(timeSeries[i+1]-timeSeries[i], duration);
        }
        res += duration;
        
        return res;
    }
};
