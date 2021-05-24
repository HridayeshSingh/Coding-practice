// -> https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int val = 1;
        int top = 0, bottom = n-1, left = 0, right = n-1;
        
        while(top <= bottom && left <= right) {
            for(int i = left; i <= right; i++)
                res[top][i] = val++;
            top++;
            
            for(int i = top; i <= bottom; i++)
                res[i][right] = val++;
            right--;
            
            if(top <= bottom) {
                for(int i = right; i >= left; i--)
                    res[bottom][i] = val++;
                bottom--;
            }
            
            if(left <= right) {
                for(int i = bottom; i >= top; i--)
                    res[i][left] = val++;
                left++;
            }
        }
        
        return res;
    }
};
