class Solution {
public:
    long long countStableSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        vector<long long> res(n);
        unordered_map<int, vector<int>> mp;
        unordered_map<long long, unordered_map<long long, int>> pmp;
        pmp[nums[0]][nums[0]] = 1;
        res[0] = nums[0];
        mp[nums[0]].push_back(0);
        for(int i = 1; i < n; i++) {
            res[i] = nums[i] + res[i - 1];
            mp[nums[i]].push_back(i);
            pmp[res[i]][nums[i]] += 1;
        }
        for(int i = 0; i < n; i++) {
            if(mp[nums[i]].size() > 1) {
                long long val = res[mp[nums[i]].back() - 1];
                if(pmp[val - nums[i]].find(nums[i]) != pmp[val - nums[i]].end()) {
                    if(!nums[i]) {
                        count--;
                        if(mp[nums[i]].back() == mp[nums[i]][mp[nums[i]].size() - 2] + 1) count--;
                    }
                    count += pmp[val - nums[i]][nums[i]];
                }
                pmp[res[mp[nums[i]].back()]][nums[i]]--;
                mp[nums[i]].pop_back();
            }
        }
        return count;
    }
};