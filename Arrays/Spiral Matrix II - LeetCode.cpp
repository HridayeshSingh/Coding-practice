// -> https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int val = 1, top = 0, left = 0, bottom = matrix.size()-1, right = matrix[0].size()-1;
        while(top <= bottom && left <= right) {
            for(int i = left; i <= right; i++)
                matrix[top][i] = val++;
            top++;
            
            for(int i = top; i <= bottom; i++)
                matrix[i][right] = val++;
            right--;
            
            if(top <= bottom) {
                for(int i = right; i >= left; i--)
                    matrix[bottom][i] = val++;
                bottom--;
            }
            
            if(left <= right) {
                for(int i = bottom; i >= top; i--)
                    matrix[i][left] = val++;
                left++;
            }
        }
        return matrix;
    }
};
