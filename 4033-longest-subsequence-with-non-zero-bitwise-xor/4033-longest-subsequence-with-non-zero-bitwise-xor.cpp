class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int val = nums[0], n = nums.size(), check = 0;
        for(int i = 1; i < n; i++) {
            val ^= nums[i];
            if(nums[i]) check = 1;
        }
        if(val) return n;
        if(check) return n - 1;
        return 0;
    }
};