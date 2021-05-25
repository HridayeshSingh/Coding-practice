// -> https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), i = 0, j = n-1;
        int res = 0;
        
        while(i < j) {
            int area;
            if(height[i] <= height[j]) {
                area = (j-i) * height[i];
                i++;
            }
            else {
                area = (j-i) * height[j];
                j--;
            }
            res = (res > area) ? res : area;
        }
        
        return res;
    }
};
