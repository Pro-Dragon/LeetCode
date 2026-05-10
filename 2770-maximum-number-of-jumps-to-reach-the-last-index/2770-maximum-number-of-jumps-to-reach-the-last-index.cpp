class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size(), cur = 0;
        vector<int> dp(n, -1);
        dp[n - 1] = 0;
        for(int i = n - 1; i >= 0; i--) {
            cur = 0;
            for(int j = i + 1; j < n; j++) {
                if(abs(nums[i] - nums[j]) <= target && (dp[j] > 0 || j == n - 1)) {
                    cur = max(cur, 1 + dp[j]);
                }
            }
            if(cur > 0) dp[i] = cur;
        }
        return dp[0];
    }
};