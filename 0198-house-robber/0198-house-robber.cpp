class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), prv1 = 0, prv2 = 0;
        if(n == 1) return nums[0];
        for(int i = 0; i < n; i++) {
            int temp = max(prv1, prv2 + nums[i]);
            prv2 = prv1;
            prv1 = temp;
        }
        return max(prv1, prv2);
    }
};