class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long n = nums.size(), count = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] > nums[i]) {
                count += nums[i - 1] - nums[i];
            }
        }
        return count;
    }
};