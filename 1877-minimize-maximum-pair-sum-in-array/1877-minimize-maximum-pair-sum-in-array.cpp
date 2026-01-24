class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi = 0, n = nums.size();
        for(int i = 0; i < n / 2; i++) maxi = max(nums[i] + nums[n - i - 1], maxi);
        return maxi;
    }
};