class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size(), maxi = 0;
        for(int i = 0; i < n; i++) {
            if(!mp[nums[i]]) {
                mp[nums[i]] = 1;
                int length = mp[nums[i] - 1] + mp[nums[i] + 1] + 1;
                mp[nums[i] - mp[nums[i] - 1]] = length;
                mp[nums[i] + mp[nums[i] + 1]] = length;
                maxi = max(length, maxi);
            }
        }
        return maxi;
    }
};