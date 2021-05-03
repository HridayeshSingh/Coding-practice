class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(auto it = nums.begin(); it != nums.end(); it++) {
            int a = target - *it;
            if(m.find(a) != m.end())
                return {m[a], (int)(it-nums.begin())};
            else 
                m[*it] = it-nums.begin();
        }
        return {};
    }
};
