class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long, vector<long long>> mp;
        long long n = nums.size(), leftsum, rightsum, leftfreq, rightfreq;
        vector<long long> res(n, 0);
        for(int i = 0; i < n; i++) {
            if(mp[nums[i]].size()) mp[nums[i]] = {mp[nums[i]][0] + i, 0, mp[nums[i]][2] + 1, 0};
            else mp[nums[i]] = {i, 0, 1, 0};
        }
        for(int i = n - 1; i >= 0; i--) {
            leftsum = mp[nums[i]][0] - i;
            rightsum = mp[nums[i]][1];
            leftfreq = mp[nums[i]][2] - 1;
            rightfreq = mp[nums[i]][3];
            res[i] = (1ll * leftfreq * i) - leftsum;
            res[i] += abs((1ll * rightfreq * i) - rightsum);
            mp[nums[i]][0] = leftsum;
            mp[nums[i]][1] = rightsum + i;
            mp[nums[i]][2] = leftfreq;
            mp[nums[i]][3] = rightfreq + 1;
        }
        return res;
    }
};