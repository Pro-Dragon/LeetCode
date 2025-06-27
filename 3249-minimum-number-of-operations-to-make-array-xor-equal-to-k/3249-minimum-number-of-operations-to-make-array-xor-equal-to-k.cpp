class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            res ^= nums[i];
        }
        return __builtin_popcount(res ^ k);
    }
};