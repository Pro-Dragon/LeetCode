class Solution {
public:
    int solve(vector<int> &nums, int l, int r) {
        int maxi1 = 0, maxi2 = 0, temp, n = nums.size();
        for(int i = l; i <= r; i++) {
            temp = max(maxi1 + nums[i], maxi2);
            maxi1 = maxi2;
            maxi2 = temp;
        }
        return max(maxi1, maxi2);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(solve(nums, 0, nums.size() - 2), solve(nums, 1, nums.size() - 1));
    }
};