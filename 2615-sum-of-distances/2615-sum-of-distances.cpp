class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long, vector<long long>> mp;
        long long n = nums.size();
        vector<long long> res(n, 0);
        for(int i = 0; i < n; i++) {
            if(mp[nums[i]].size()) mp[nums[i]] = {mp[nums[i]][0] + i, 0, mp[nums[i]][2] + 1, 0};
            else mp[nums[i]] = {i, 0, 1, 0};
        }
        for(int i = n - 1; i >= 0; i--) {
            mp[nums[i]][0] -= i;
            mp[nums[i]][1] += i;
            mp[nums[i]][2] -= 1;
            mp[nums[i]][3] += 1;
            res[i] = (1ll * mp[nums[i]][2] * i) - mp[nums[i]][0] + abs((1ll * (mp[nums[i]][3] - 1) * i) - (mp[nums[i]][1] - i));
        }
        return res;
    }
};