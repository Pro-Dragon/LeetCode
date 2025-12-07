class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), sum = 0, j = 0, mini = n + 1;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum >= target) {
                mini = min(mini, i - j + 1);
                while(sum >= target && j <= i) {
                    mini = min(mini, i - j + 1);
                    sum -= nums[j];
                    j++;
                }
            }
        }
        return mini == n + 1 ? 0 : mini;
    }
};