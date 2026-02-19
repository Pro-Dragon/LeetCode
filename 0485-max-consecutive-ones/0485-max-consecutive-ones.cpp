class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), cur = 0, maxi = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i]) cur++;
            else cur = 0;
            maxi = max(maxi, cur);
        }
        return maxi;
    }
};