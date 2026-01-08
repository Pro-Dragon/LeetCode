class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int count = 0, val = -1, res = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            count = 0, val = -1;
            for(int j = 2; j <= sqrt(nums[i]); j++) {
                if(nums[i] % j == 0) {
                    count++;
                    val = j;
                }
            }
            if(val == nums[i] / val) continue;
            if(count == 1) {
                res += ((nums[i] / val) + val + nums[i] + 1);
            }
        }
        return res;
    }
};