class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, res = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(mp[sum - k]) res += mp[sum - k];
            mp[sum]++;
        }
        return res;
    }
};