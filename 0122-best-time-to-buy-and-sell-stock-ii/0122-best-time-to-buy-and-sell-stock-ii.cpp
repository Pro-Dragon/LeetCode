class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size(), prv = nums[0], res = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] > nums[i]) {
                res += nums[i - 1] - prv;
                prv = nums[i];
            }
            if(i == n - 1 && nums[i - 1] <= nums[i]) res += nums[i] - prv;
        }
        return res;
    }
};