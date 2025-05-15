class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int cur = 1, res = 0, diff = nums[0] - nums[1], n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] - nums[i + 1] == diff) cur++;
            else {
                if(cur >= 3) {
                    cur -= 2;
                    res += ((cur * (cur + 1)) >> 1);
                }
                cur = 2;
                diff = nums[i] - nums[i + 1];
            }
        }
        if(cur >= 3) {
            cur -= 2;
            res += ((cur * (cur + 1)) >> 1);
        }
        return res;
    }
};