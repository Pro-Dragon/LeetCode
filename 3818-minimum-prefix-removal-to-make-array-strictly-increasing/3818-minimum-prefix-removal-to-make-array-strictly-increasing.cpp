class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        unsigned int cur = 0, sum = 0, n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            cur += nums[i];
            if(nums[i] >= nums[i + 1]) sum = i + 1;
        }
        return sum;
    }
};