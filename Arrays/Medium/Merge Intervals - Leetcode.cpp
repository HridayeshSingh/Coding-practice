// -> https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &v1, auto &v2) {
            return v1[0] < v2[0];
        });
        
        vector<vector<int>> res;
        int n = intervals.size();
        int first = intervals[0][0], second = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] > second) {
                res.push_back({first, second});
                first = intervals[i][0];
            }
            second = (second > intervals[i][1]) ? second : intervals[i][1];
        }
        
        if(intervals[n-1][0] > second)
            res.push_back(*(intervals.end()-1));
        else
            res.push_back({first, max(intervals[n-1][1], second)});
        
        return res;
    }
};
