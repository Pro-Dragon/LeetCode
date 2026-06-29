class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long res = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < k; i++) {
            if(mul) {
                res += (1ll * mul * nums[i]);
                mul--;
            }
            else res += nums[i];
        }
        return res;
    }
};