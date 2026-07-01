class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long n = nums.size(), j = 0, cur = 0;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            if(1ll * (i - j + 1) * nums[i] - cur > k) {
                cur -= nums[j];
                j++;
            }
        }
        return n - j;
    }
};