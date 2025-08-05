class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxi = 1, res = 0;
        vector<int> dp(n, 1), count(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(dp[i] == dp[j]) {
                        dp[i]++;
                        count[i] = 0;
                    }
                    if(dp[i] == dp[j] + 1) {
                        count[i] += count[j];
                    }
                    maxi = max(maxi, dp[i]);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(maxi == dp[i]) {
                res += count[i];
            }
        }
        return res;
    }
};