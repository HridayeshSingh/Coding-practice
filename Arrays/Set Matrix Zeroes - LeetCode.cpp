// -> https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isColumnZero = false;
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0)
                isColumnZero = true;
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        
        if(matrix[0][0] == 0)
            for(int j = 0; j < n; j++)
                matrix[0][j] = 0;
        if(isColumnZero)
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};
