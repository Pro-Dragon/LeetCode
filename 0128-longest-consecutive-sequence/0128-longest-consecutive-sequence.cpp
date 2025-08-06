class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = 1;
        }
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            if(mp[nums[i]]) {
                int count = 1, val = nums[i] - 1;
                while(mp[val]) {
                    mp[val] = 0;
                    val--;
                    count++;
                }
                val = nums[i] + 1;
                while(mp[val]) {
                    mp[val] = 0;
                    val++;
                    count++;
                }
                maxi = max(maxi, count);
                mp[nums[i]] = 0;
            }
        }
        return maxi;
    }
};