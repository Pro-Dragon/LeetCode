class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        unordered_map<int, pair<long long, int>> mp;
        int n = nums.size(), mod = 1e9 + 7;
        long long sum = 0, left, right, steps;
        for(int i = 0; i < n; i++) {
            left = 0, right = 0, steps = 0;
            if(mp.find(nums[i] - 1) != mp.end()) {
                steps = mp[nums[i] - 1].second;
                left = (mp[nums[i] - 1].first + (1ll * steps * nums[i])) % mod;
            }
            if(mp.find(nums[i] + 1) != mp.end()) {
                right = (mp[nums[i] + 1].first + (1ll * mp[nums[i] + 1].second * nums[i])) % mod;
                steps = (steps + mp[nums[i] + 1].second) % mod;
            }
            mp[nums[i]] = {(mp[nums[i]].first + left + right + nums[i]) % mod, (mp[nums[i]].second + steps + 1) % mod};
            sum = (sum + left + right + nums[i]) % mod;
        }
        return sum;
    }
};