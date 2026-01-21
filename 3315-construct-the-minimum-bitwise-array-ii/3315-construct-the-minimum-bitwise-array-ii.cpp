class Solution {
public:
    int solve(int n) {
        if(~n == 0) return sizeof(int) * 8;
        return __builtin_ctz(~n);
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
           if(nums[i] == 2) res[i] = -1;
           else {
                res[i] = nums[i] - pow(2, solve(nums[i]) - 1);
           }
        }
        return res;
    }
};