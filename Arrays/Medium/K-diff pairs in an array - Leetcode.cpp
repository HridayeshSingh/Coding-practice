// -> https://leetcode.com/problems/k-diff-pairs-in-an-array/

// Solution 1 : [Time - O(nlogn); Space - O(1)]
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int i = 0, j = 1, count = 0;
        while(i < n && j < n) {
            if(nums[j]-nums[i] == k) {
                count++;
                i++;
                j++;
                while(j < n && nums[j] == nums[j-1])
                    j++;
            } else if(nums[j]-nums[i] > k) {
                i++;
                if(j == i)
                    j++;
            } else {
                j++;
            }
        }
        
        return count;
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Solution 2 : [Time - O(n); Space - O(n)]
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, bool> m;
        int count = 0;
        
        for(auto it = nums.begin(); it != nums.end(); it++) {
            if(k == 0){
                if(m.find(*it) != m.end()) { 
                    if(!m[*it]) {
                        count++;
                        m[*it] = true;
                    }
                    continue;
                }
            } else if(m.find(*it) == m.end()) { 
                if(m.find(*it+k) != m.end())
                    count++;
                if(m.find(*it-k) != m.end())
                    count++;
            }
            m[*it] = false;
        }
        
        return count;
    }
};
