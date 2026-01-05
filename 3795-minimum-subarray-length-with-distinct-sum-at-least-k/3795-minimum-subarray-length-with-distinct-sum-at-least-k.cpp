class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size(), cur = 0, mini = n + 1, j = 0;
        for(int i = 0; i < n; i++) {
            if(!mp[nums[i]]) cur += nums[i];
            mp[nums[i]]++;
            if(cur < k) continue;
            while(j < i && cur - nums[j] >= k || j < i && mp[nums[j]] > 1) {
                mp[nums[j]]--;
                if(!mp[nums[j]]) cur -= nums[j];
                j++;
            }
            mini = min(mini, i - j + 1);
        }
        return (mini == n + 1) ? -1 : mini;
    }
};