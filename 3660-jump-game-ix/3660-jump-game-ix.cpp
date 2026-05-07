class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size(), mini = nums.back();
        vector<int> res(n, 0);
        res[0] = nums[0];
        for(int i = 1; i < n; i++) res[i] = max(res[i - 1], nums[i]);
        for(int i = n - 2; i >= 0; i--) {
            if(res[i] > mini) res[i] = res[i + 1];
            mini = min(mini, nums[i]);
        }
        return res;
    }
};