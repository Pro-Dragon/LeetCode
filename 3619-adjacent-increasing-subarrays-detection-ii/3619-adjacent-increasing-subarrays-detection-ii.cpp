class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size(), prv = 0, cur = 1, res = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] < nums[i + 1]) cur++;
            else {
                res = max(res, cur / 2);
                res = max(res, min(cur, prv));
                if(i < n - 2 && nums[i + 1] < nums[i + 2] || i == n - 2) prv = cur;
                else prv = 0;
                cur = 1;
            }
        }
        res = max(res, cur / 2);
        res = max(res, min(cur, prv));
        return res;
    }
};