class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size(), a, b, ans = n, premoves = 0;
        vector<int> res(2 + limit * 2, 0);
        for(int i = 0; i < n / 2; i++) {
            a = min(nums[i], nums[n - i - 1]);
            b = max(nums[i], nums[n - i - 1]);

            res[2] += 2;
            res[a + 1] -= 1;
            res[a + b] -= 1;
            res[a + b + 1] += 1;
            res[b + limit + 1] += 1;
        }

        for(int i = 2; i <= 2 * limit; i++) {
            premoves += res[i];
            ans = min(premoves, ans);
        }
        return ans;
    }
};