// -> https://leetcode.com/problems/game-of-life/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        pair<int, int> directions[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        int m = board.size(), n = board[0].size();
        
        // +10 for 0; +20 for 1 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int live = 0;
                for(auto d : directions) {
                    int a = i+d.first, b = j+d.second;
                    if(a >= 0 && a < m && b >= 0 && b < n)
                        live += board[a][b]%10;
                }
                if(board[i][j]%10) {
                    board[i][j] += (live == 2 || live == 3) ? 20 : 10;
                } else {
                    board[i][j] += (live == 3) ? 20 : 10;
                }
            }
        }
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                board[i][j] /= 20;
    }
};
