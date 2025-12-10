class Solution {
public:
    int countPermutations(vector<int>& nums) {
        int n = nums.size(), root = nums[0], count = 1, res = 1, mod = 1e9 + 7;
        for(int i = 1; i < n; i++) {
            if(root >= nums[i]) return 0;
            res = ((long)res * count) % mod;
            count++;
        }
        return res % mod;
    }
};