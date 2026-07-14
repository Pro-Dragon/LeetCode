class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long n = nums.size(), mod = 1e9 + 7, cnt = 0, cur_k = k, cur_cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > cur_k) {
                cur_cnt = (((nums[i] - cur_k) + (k - 1)) / k);
                cur_k += (cur_cnt * k);
                cnt = (cnt + cur_cnt);
            }
            cur_k = (cur_k - nums[i]);
        }
        cnt = ((((cnt / 2) + (cnt % 2)) % mod) * ((cnt + !(cnt % 2)) % mod)) % mod;
        return cnt % mod;
    }
};