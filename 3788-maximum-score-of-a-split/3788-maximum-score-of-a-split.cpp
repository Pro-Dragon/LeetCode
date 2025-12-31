class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long n = nums.size(), res = INT_MIN, sum = 0;
        vector<int> suffmin(n);
        suffmin[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffmin[i] = min(suffmin[i + 1], nums[i]);
        }
        for(int i = 0; i < n - 1; i++) {
            sum += nums[i];
            if(sum - suffmin[i + 1] > res) res = sum - suffmin[i + 1];
        }
        return res;
    }
};