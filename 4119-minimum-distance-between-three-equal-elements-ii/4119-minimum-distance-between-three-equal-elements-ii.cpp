class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        unordered_map<int, vector<int>> ump;
        for(int i = 0; i < n; i++) {
            ump[nums[i]].push_back(i);
            if(ump[nums[i]].size() > 2) {
                int len = ump[nums[i]].size();
                auto& curr = ump[nums[i]];
                int val = abs(curr[len - 1] - curr[len - 2]) + 
                        abs(curr[len - 2] - curr[len - 3]) + 
                        abs(curr[len - 3] - curr[len - 1]);
                if(ans == -1 || ans > val) 
                    ans = val;
            }
        }
        return ans;
    }
};