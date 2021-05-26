// -> https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        
        bool isInserted = false;
        for(auto interval : intervals) {
            if(interval[1] < newInterval[0])
                res.push_back(interval);
            else if(interval[0] > newInterval[1]) {
                if(!isInserted) {
                    res.push_back(newInterval);
                    isInserted = true;
                }
                res.push_back(interval);
            }
            else {
                newInterval[0] = (interval[0] < newInterval[0]) ? interval[0] : newInterval[0];
                newInterval[1] = (interval[1] > newInterval[1]) ? interval[1] : newInterval[1];
            }
        }
        
        if(!isInserted)
            res.push_back(newInterval);
        
        return res;
    }
};
