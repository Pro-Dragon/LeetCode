class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), sum = 0, elesum = 0, maxi = 0;
        for(int i = 0; i < n; i++) {
            sum += (nums[i] * i);
            elesum += nums[i];
        }
        maxi = sum;
        for(int i = n - 1; i > 0; i--) {
            sum -= nums[i] * (n - 1);
            sum += (elesum - nums[i]);
            maxi = max(sum, maxi);
        }
        return maxi;
    }
};