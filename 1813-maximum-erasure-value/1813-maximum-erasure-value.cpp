class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0, maxi = 0, n = nums.size(), prv = 0, cur = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(mp[nums[i]] > prv) {
                prv = mp[nums[i]];
                cur = sum - prv;
            }
            else cur += nums[i];
            maxi = max(maxi, cur);
            mp[nums[i]] = sum;
        }
        return maxi;
    }
};