class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size(), mini1 = INT_MAX, mini2 = INT_MAX;
        for(int i = 1; i < n; i++) {
            if(mini1 >= nums[i]) {
                mini2 = mini1;
                mini1 = nums[i];
            }
            if(mini2 > nums[i] && mini1 < nums[i]) mini2 = nums[i];
        }
        return nums[0] + mini1 + mini2;
    }
};